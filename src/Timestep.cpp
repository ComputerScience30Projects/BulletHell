#include "TimeStep.h"

#include <iostream>

void TimeStep::start()
{
    _accumulator = 0.0f;
    _initialTime = utils::elapsedTime();
}

void TimeStep::addToAccumulator()
{
        _finalTime = utils::elapsedTime();

        float frameTime = _finalTime - _initialTime;

        _initialTime = _finalTime;
        
        _accumulator += frameTime;
}

bool TimeStep::isAccumulatorFull()
{
    if (_accumulator >= TIMESTEP)
        return true;

    return false;
}

void TimeStep::resetAccumulator()
{
    _accumulator = 0.0f;
}