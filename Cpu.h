
#include <vector>
#include <iostream>

#include "Process.h"

class Cpu
{
public:

Cpu();
Process getExecuting();
void exit();
void printReadyQueue();
bool addProcess(int,int,int&);
void printExecuting();

private:
    Process executing = Process(0,0,0);
    std::vector<Process> readyQueue;
    int queueSize;

    void update();
};