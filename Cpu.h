
#include <vector>
#include <iostream>

#include "Process.h"
#include "Ram.h"

class Cpu
{
public:

Cpu();
Cpu(int);
Process getExecuting();
void exit();
void printReadyQueue();
bool addProcess(int,int);
void printExecuting();
void fetch(int);
void printRAM();

private:
    Process executing = Process(0,0);
    std::vector<Process> readyQueue;
    Ram ram = Ram();
    int queueSize;
    int programCounter;
    void update();
};