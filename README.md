# cpp_pathfinder
My implementation of the Breadth-first search algorithm.
Ref: https://en.wikipedia.org/wiki/Breadth-first_search

output e.g given 3,3 grid with a start pos @ 0,0 and target @ 2,2:

Grid layout raw (0 passable; 1 blocker):
~~~~
010
000
010
~~~~

Grid layout formatted (. passable; # blocker):
~~~~
.#.
...
.#.
~~~~

Grid layout raw indicating **path** (2):
~~~~
010
222
012
~~~~

Grid layout formatted indicating **path** (*):
~~~~
.#.
***
.#*
~~~~
