
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
void addProcess(Process);
void printExecuting();
void fetch(int);
void printRAM();
void moveDisk();

private:
    Process executing = Process();
    std::vector<Process> readyQueue;
    Ram ram = Ram();
    int programCounter;
    void update();
};