/**
 * MONOPOLY
 */

#include "Dice.hpp"

#include <ctime>
#include <cstdlib>


namespace Core {

Dice::result_t Dice::rollDices() noexcept
{
    int&& d1 = Dice().roll();
    int&& d2 = Dice().roll();
    return std::make_pair(std::move(d1), std::move(d2));
}

int Dice::roll() const noexcept
{
    std::srand(time(nullptr));
    return rand() % 6 + 1;
}

} /// Core namespace
