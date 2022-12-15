//Jeffrey Li
#include "Process.h"

Process::Process()
{
    priority = 0;
    pid = 0;
    disk = false;
    filename = "";
    ramFrame = -1;
    ramPage = 0;
}

Process::Process(int page, int prio, int processID)
{
    ramPage = page;
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


int Process::getFrame()
{
    return ramFrame;
}

void Process::setFrame(int frame)
{
    ramFrame = frame;
}

int Process::getPage()
{
    return ramPage;
}

void Process::setPage(int page)
{
    ramPage = page;
}