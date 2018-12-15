#pragma once

// Material here is based on ideas from https://www.redblobgames.com/grids/hexagons/

// "My recommendation: if you are only going to use rectangular maps, and never rotate the map, 
// consider the doubled or offset coordinates, as they will line up with your map better than axial or cube.""
//
// Since CfNA is played on a rectangular map and rotating the map doesn't happen, we will keep to the 
// recomendation and consider doubled or offset coordinates.

// The CfNA map is oriented such that one the angles 'points' north (instead of a north being one of the
// flat sides). With that, it would seem I should use the 'double with' horizontal layout which doubles the
// column values. 


