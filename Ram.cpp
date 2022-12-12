#include "Ram.h"

Ram::Ram()
{
    size = 0;
}

Ram::Ram(int frames)
{
    size = frames;
    for(int i = 0; i < frames; i++)
    {
        Page temp(0,0);
        frame.push_back(temp);
    }
}

void Ram::print()
{
    for(int i = 0; i < size; i++)
    {
        if(frame.at(i).getPID() > 0)
        {
            std::cout << i << "\t";
            frame.at(i).print();
        }
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
    int min = frame
}