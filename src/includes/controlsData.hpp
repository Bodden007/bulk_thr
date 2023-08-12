#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include "procesData.hpp"

class controlsData
{
private:
    int N;
    bool request = true;

public:
    controlsData(int argN)
    {
        N = argN;
    }
    ~controlsData(){};
    void controls();
};
