#include "../includes/outConsole.hpp"

void outConsole::thrConsol(std::string out_balk)
{
    log = std::thread(showConsol, this, out_balk);
    log.join();
}

void outConsole::showConsol(std::string out_balk)
{
    mut.lock();
    std::cout << out_balk << std::endl;
    mut.unlock();
}