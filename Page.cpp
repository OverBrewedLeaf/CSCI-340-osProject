#include "Page.h"

Page::Page(int pageNum, int pidNum)
{
    page = pageNum;
    pid = pidNum;
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

void Page::kill()
{
    page = 0;
    pid = 0;
}

