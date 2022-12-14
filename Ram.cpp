#include "Ram.h"

Ram::Ram()
{
    size = 0;
    programCounter = 0;
}

Ram::Ram(int frames)
{
    size = frames;
    programCounter = 0;
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
            std::cout   << i << "\t" << frame.at(i).getPage() << "\t" << frame.at(i).getPID() << "   ";
            std::cerr  << char(frame.at(i).getCPU() * '*') << "\t" << frame.at(i).getAge() << "\n";
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
            min = i;
        }
    }
    return min;
}

void Ram::fetch(int pageNum, int pid)
{
    bool update = false;
    for(int i = 0; i < size; i++)
    {
        if(pageNum == frame.at(i).getPage() && pid == frame.at(i).getPID())
        {
            return;
        }
        frame.at(i).setCPU(false);
    }
    Page temp(pageNum, pid, ++programCounter);
    temp.setCPU(true);
    frame.at(oldest()) = temp;
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
    Page temp(page, pid, ++programCounter);
    temp.setCPU(cpuState);
    frame.at(oldest()) = temp;
    return;
}

void Ram::add(int index, Process copy, bool inCPU)
{
    Page temp(copy.getPage(), copy.getPID(), ++programCounter);
    temp.setCPU(inCPU);
    frame.at(index) = temp;
}

void Ram::deselect()
{
    for(int i = 0; i < size; i++)
    {
        frame.at(i).setCPU(false);
    }
}

void Ram::updateCPU() // find cpu and update to highest time
{
    int time = 0;
    int cpu = -1;
    for(int i = 0; i < size; i++)
    {
        Page x = frame.at(i);
        if(x.getAge() > time)
            time = x.getAge();
        if(x.getCPU())
            cpu = i;
    }
    if(cpu == -1) return;
    frame.at(cpu).setAge(++time);
    programCounter++;

}