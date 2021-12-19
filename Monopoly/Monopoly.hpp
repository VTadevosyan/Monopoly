/**
 * MONOPOLY
 */

#ifndef MONOPOLY_MONOPOLY_HPP
#define MONOPOLY_MONOPOLY_HPP


#include <stddef.h>



enum {
    MIN_PLAYERS_COUNT = 2,
    MAX_PLAYERS_COUNT = 5,
    BOARD_ITEMS_COUNT = 40
};

typedef unsigned int cash_t;

enum class color_t
{
    undefined = -1,
    red = 0,
    green,
    blue,
    yellow,
    magenta
};


#endif // MONOPOLY_HPP
