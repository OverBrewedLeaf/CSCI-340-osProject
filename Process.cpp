#include "Process.h"

Process::Process(int prio, int processID,int timestamp)
{
    priority = prio;
    pid = processID;
    time = timestamp;
    disk = false;
    filename = "";
}

Process::Process(Process copy, std::string file)
{
    disk = true;
    filename = file;
}

int Process::getPriority()
{
    return priority;
}

int Process::getPID()
{
    return pid;
}

void Process::kill()
{
    priority = 0;
    time = 0;
    pid = 0;
    disk = false;
    filename = "";
}
