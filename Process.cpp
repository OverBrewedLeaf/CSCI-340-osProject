#include "Process.h"

Process::Process()
{
    priority = 0;
    pid = 0;
    time = 0;
    disk = false;
    filename = "";
}

Process::Process(int prio, int processID, int timestamp)
{
    priority = prio;
    pid = processID;
    time = timestamp;
    disk = false;
    filename = "";
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

std::string Process::getFilename()
{
    return filename;
}

void Process::setFilename(std::string name)
{
    disk = true;
    filename = name;
}
