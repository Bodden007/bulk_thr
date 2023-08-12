#include <iostream>
#include <sstream>
#include "includes/controlsData.hpp"

int main(int argc, char *argv[])
{
    int N = 3;
    std::stringstream strArg;
    strArg << argv[1];
    strArg >> N;

    controlsData controlsDat{N};
    controlsDat.controls();
    return 0;
}