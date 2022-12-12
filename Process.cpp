#include "Process.h"

Process::Process()
{
    priority = 0;
    pid = 0;
    disk = false;
    filename = "";
}

Process::Process(int prio, int processID)
{
    priority = prio;
    pid = processID;
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
