#pragma once
#include <iostream>
#include <thread>
#include <mutex>

class outConsole
{
   std::mutex mut;
   std::thread log;

public:
   void thrConsol(std::string out_balk);
   void showConsol(std::string out_balk);
};
