/**
 * MONOPOLY
 */

#include "Player.hpp"


namespace Core {

Player::Player(const std::string& name)
    : mName(name)
    , mCash(15000)
    , mColor(color_t::undefined)
    , mIsActive(true)
{
}

std::string Player::getName() const noexcept
{
    return mName;
}

cash_t Player::getCash() const noexcept
{
    return mCash;
}

bool Player::isActive() const noexcept
{
    return mIsActive;
}

void Player::addCash(const cash_t c)
{
    mCash += c;
}

void Player::withdrawCash(const cash_t c)
{
    if (c > mCash) {
        /// TODO throw
        bankrupt();
    }
    mCash -= c;
}

void Player::setColor(const color_t c) noexcept
{
    mColor = c;
}

color_t Player::getColor() const noexcept
{
    return mColor;
}

void Player::bankrupt()
{

}

} /// Core namespace
