#include "Ram.h"

Ram::Ram()
{
    // size = 0;
}

Ram::Ram(int frames)
{
    size = frames;
    for(int i = 0; i < frames; i++)
    {
        Page temp(0,0,0);
        frame.push_back(temp);
    }
}

void Ram::print()
{
    for(int i = 0; i < size; i++)
    {
        // if(frame.at(i).getPID() > 0)
        // {
            std::cout   << i << "\t" << frame.at(i).getPage() 
                        << "\t" << frame.at(i).getPID() << "\t" << frame.at(i).getCPU() * '*' << "\n";
        // }
    }
    std::cout << "\n";
}

void Ram::kill(int pid)
{
    for(int i = 0; i < size; i++)
    {
        if(frame.at(i).getPID() == pid)
        {
            frame.at(i).kill();
        }
    }
}

int Ram::oldest()
{
    int min = 0;
    for(int i = 0; i < size; i++)
    {
        if(frame.at(i).getPID() == 0)
        {
            return i;
        }
        if(!frame.at(i).getCPU() && frame.at(i).getAge() < frame.at(min).getAge())
        {
            std::cout << "is this running\n";
            min = i;
        }
    }
    return min;
}

void Ram::fetch(int pageNum, int pid)
{
    add(pageNum,pid,true);
}

void Ram::add(int page, int pid, bool cpuState)
{
    if(cpuState)
    {
        for(int i = 0; i < size; i++)
        {
            if(frame.at(i).getPage() == page && frame.at(i).getPID() == pid)
            {
                frame.at(i).setCPU(true);
                return;
            }
            frame.at(i).setCPU(false);
        }
    }
    Page temp(page, pid, programCounter);
    temp.setCPU(cpuState);
    frame.at(oldest()) = temp;
}