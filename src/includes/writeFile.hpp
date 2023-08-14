#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "../includes/dataTime.hpp"

class writeFile
{
    std::mutex mtx;
    std::condition_variable cv;
    std::thread file1;
    std::thread file2;

private:
    bool ready = false;
    bool flagQueue = false;

public:
    void thrFile(std::string out_Balk);
    void outFile(std::string out_balk, std::string nameThr);
    void go();
};