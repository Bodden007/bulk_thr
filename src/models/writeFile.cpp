#include "../includes/writeFile.hpp"

void writeFile::thrFile(std::string out_balk)
{
    if (!flagQueue)
    {
        file1 = std::thread(outFile, this, out_balk, "file1");
        flagQueue = true;
        go();
        file1.join();
    }
    else
    {
        file2 = std::thread(outFile, this, out_balk, "file2");
        flagQueue = false;
        go();
        file2.join();
    }
}

void writeFile::outFile(std::string out_balk, std::string nameThr)
{
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready)
        cv.wait(lck);

    dataTime dataT;
    std::string timeDat = dataT.timeSyst();
    std::string fileName = "bulk";
    fileName += timeDat + "_" + nameThr + ".log";

    std::ofstream out;
    out.open(fileName);

    if (out.is_open())
    {
        out << out_balk << std::endl;
    }

    out.close();
}

void writeFile::go()
{
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}