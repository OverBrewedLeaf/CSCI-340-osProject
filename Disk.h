#include <queue>
#include <iostream>
#include "Process.h"

class Disk
{
public:

    Disk();
    void print();
    void printQueue();
    void addProcess(Process);
    Process kill();
    Process complete();

private:
    int size;
    void update();
    std::queue<Process> IOQueue;
    Process waiting = Process();
};