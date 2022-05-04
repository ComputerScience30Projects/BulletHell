#pragma once

#include "Utils.h"

class TimeStep
{
public:

    /*Run the TimeStep*/
    void start();
    void addToAccumulator();
    bool isAccumulatorFull();
    void resetAccumulator();

    const float TIMESTEP = 0.01f;

private:

    float _accumulator;
    float _initialTime;
    float _finalTime;
    
};