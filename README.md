# Player aid for the hex and counter game, Campaign for North Africa

## Design notions
Given that the entities in game (map, units) are 'objects', an OO approach seems feasible.
Perhaps serialize the actual objects into and out of the game with persistence the 
responsbility of the file system. 

It is desired to be able to revert the state of the game back to any previous turn, including
all the way to back to the initial state.

It is desired that any given event (move, combat, etc) can be reversed. However, each reversal will 
be done unit by unit (tedious for stacks of units).

It is desired that the state of the game (especially units) can be exported out into JSON. 

Version one of this application will be menu driven console app.  

## Abstractions
### Hexes
The hex is a fundamental concept in the game and is the basis for the terrain environemnt
on which the game is played.

Hexes can be a variety of types (wadi, city, sand, etc). 
Hexes can possess Fortifications

Hexes could be designed as decorators

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
25.1 Each level of Foritifcation gives an increasing defensive benefit to units in that hex 
(see T.E.C., Case 8.37)