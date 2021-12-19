/**
 * MONOPOLY
 */

#include "Engine.hpp"
#include "Manager.hpp"

#include <cassert>


namespace Core {

Manager* Manager::sInstance = nullptr;

void Manager::create()
{
    assert(sInstance == nullptr);
    sInstance = new Manager;
}

void Manager::destroy()
{
    assert(sInstance != nullptr);
    delete sInstance;
    sInstance = nullptr;
}

Manager* Manager::get()
{
    assert(sInstance != nullptr);
    return sInstance;
}

Manager::Manager()
{
    mEngine = new Engine;
}

Manager::~Manager()
{
    if (mEngine != nullptr) {
        delete mEngine;
        mEngine = nullptr;
    }
}

const Engine* Manager::getEngine() const noexcept
{
    assert(mEngine != nullptr);
    return mEngine;
}

Engine* Manager::getEngine() noexcept
{
    assert(mEngine != nullptr);
    return mEngine;
}


} /// Core namespace
