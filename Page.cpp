#include "Page.h"

Page::Page(int pageNum, int pidNum, int age)
{
    page = pageNum;
    pid = pidNum;
    trueAge = age;
    inCPU = false;
}

int Page::getPage()
{
    return page;
}

int Page::getPID()
{
    return pid;
}

int Page::getAge()
{
    return trueAge;
}

bool Page::getCPU()
{
    return inCPU;
}

void Page::setPage(int pageNum)
{
    page = pageNum;
}

void Page::setPID(int PIDnum)
{
    pid = PIDnum;
}

void Page::print()
{
    std::cout << page << "\t" << pid << "\n";
}

void Page::setCPU(bool state)
{
    inCPU = state;
}

void Page::kill()
{
    page = 0;
    pid = 0;
    inCPU = false;
}

