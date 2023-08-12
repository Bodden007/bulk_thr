#include "includes/controlsData.hpp"
// namespace ph = std::placeholders;

void controlsData::controls()
{
    std::string data;
    std::cout << "Параметр: " << N << std::endl;

    procesData prData(N);

    while (request)
    {
        std::cin >> data;

        if (std::cin.eof())
        {
            data = "null";
            std::cin.clear();
        }
        prData.sortData(data);
        if (data.compare("t") == 0)
        {
            request = false;
        }
    };
}