# Player aid for the hex and counter game, Campaign for North Africa

## Acknowledgements
Algorithms and ideas about hexgrids was leveraged and taken from: https://www.redblobgames.com/grids/hexagons/


## Design notions
Given that the entities in game (map, units) are 'objects', an OO approach seems feasible.
Perhaps serialize the actual objects into and out of the game with persistence to the file system.

It is desired to be able to revert the state of the game back to any previous turn, including
all the way to back to the initial state. 

It is desired that any given event (move, combat, etc) can be reversed. However, each reversal will 
be done unit by unit (tedious for stacks of units). So, maybe some form of event sourcing that can played
forward and backwards.

It is desired that the state of the game (especially units) can be exported out into ?

Version one of this application will be menu driven console app.  

## Abstractions

### Map
There are five maps to the game (A-E)
Each map contains a rectangle of Hexes. These hexes are 'pointy-top' in their north-south orientation.

### Hexes
The hex is a fundamental concept in the game and is the basis for the terrain environemnt
on which the game is played.

Hexes have the following 'responsibilities'
1. possess a overall terrain type for the hex
2. sides of hexes can possess additional terrain types such as rivers, escarpments
3. roads and tracks cross hexes from one side to another and on occansion terminate 'in' the hex
4. Towns and cities can occupy hexes
5. Fortifications can occupy hexes - and while constructed and are destroyable are treated as 'terrain',
unlike units
6. Units can occupy hexes - but unlike the above, are not an intregal part of the 'terrain' of the hex

Given that most hexes do not have 'side' terrain (rivers, escarpments), roads, railroads, or towns/citys, 
it seems wasteful to include space for these entities in a hex object. How about a design where a collection 
keyed by map letter and hex number (from the physical map) contain information about these 'sparse' features.

For instance, we could have a map of roads. The key could be B5504 and the value could be an array of enum 
of 'W', 'E', 'SE'. There could also be a map of towns/city/birs/oases. In this case the key of B5504 would be 
the town of Barce. There could be a map of hexside terrain and the key of B5504 would return an array of pairs 
of TerrainTypes and hexside enum. But only the hexes that had these sorts of terrain would be in these collections. 

Given that most of the terrain on the map is clear, you could extend this to terrian 'in' the hex as well.

Hexes are represented internally using the cube coordinate syntax as described in redblobgames link above.


### Units
#### Characteristics
It seems appropriate to treat units as a rollup of a set of reduce actions against a Java stream for the 
unit level values of attack, defense, water, food, etc. 

I should explore designing units using decorators



## Land Game Rules of Play

25.0 Fortifications
General Rule
All major cities in the game are considered fortifications. In addition, players may construct 
fortifications (see Case 24.4). Fortifications are availabe in levels, reflective of the depth and
strength of the fortifications. Most fortiifications and cities have two possible levels, but Cairo
and Alexandria have three possible levels. Fortifications give beneifts to units in that hex.
Cases
25.11 Each level of Foritifcation gives an increasing defensive benefit to units in that hex 
(see T.E.C., Case 8.37)
25.12 Each major city on the game-map is a Level 2 fortification. Cairo and Alexandria are Level 3 
fortifications. Villages are not fortifications.
25.13 Constructed fortifications are either Level 1 or Level 2. Fortifications can never be constructed
higher than Level 2, except in Cairo or Alexandria. 