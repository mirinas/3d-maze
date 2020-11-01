# 3d-maze

A 3d maze in C++

This program takes a maze as an input - this is an example of a maze:

    ...
    WWWWWWWWWWWWWWW
    WWWOOOOWOOOOWWW
    WWWOWWOWOWWOWWW
    WWWOWWOWOWWOWWW
    WWWOWWOWOWWOWWW
    WWWOWWOWOWWOWWW
    WWWOWWWWWWWOWWW
    WWWWWWWWWWWWWWW     this is one layer of a maze. Typically, it has more, which would be written in a column,
    WWWOWWWWWWWOWWW     first layer being y = 0 layer
    WWWOWWOWOWWOWWW
    WWWOWWOWOWWOWWW
    WWWOWWOWOWWOWWW     W meaning a wall
    WWWOWWOWOWWOWWW     O meaning an empty place
    WWWOOOOWOOOOWWW
    WWWWWWWWWWWWWWW
    ...

Output is the same maze, but empty places filled with integers, meaning how much steps does it take from a starting point to get to a particular empty place:

    ...
    W W W W W W W W W W W W W W W
    W W W O O O O W O O O O W W W
    W W W O W W O W O W W O W W W
    W W W O W W O W O W W O W W W
    W W W O W W O W O W W O W W W
    W W W O W W O W O W W O W W W
    W W W O W W W W W W W O W W W
    W W W W W W W W W W W W W W W
    W W W 18W W W W W W W O W W W
    W W W 17W W 4 W O W W O W W W
    W W W 16W W 5 W O W W O W W W
    W W W 15W W 6 W O W W O W W W
    W W W 12W W 7 W O W W O W W W
    W W W 11109 8 W O O O O W W W
    W W W W W W W W W W W W W W W
    ...
