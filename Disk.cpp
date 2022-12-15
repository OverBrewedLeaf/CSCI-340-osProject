//Jeffrey Li
#include "Disk.h"

Disk::Disk()
{
    size = 0;
}

void Disk::print()
{   
    if(waiting.getPID() == 0)
    {
        std::cout << ": Idle\n"; 
    }
    else
    {
        std::cout << ": PID " << waiting.getPID() << ", \"" << waiting.getFilename() << "\"\n";
    }
}

void Disk::printQueue()
{
    std::cout << " I/O-queue: ";
    if(size == 0)
    {
        std::cout << "Empty\n";
    }
    else{
        std::queue<Process> tempQueue;
        while(!IOQueue.empty())
        {
            Process temp = IOQueue.front();
            tempQueue.push(temp);
            IOQueue.pop();
            std::cout << " PID " << temp.getPID() << ", \"" << temp.getFilename() << "\"";
        }
        std::cout << std::endl;
        IOQueue = tempQueue;
    }
}

void Disk::addProcess(Process element)
{
    IOQueue.push(element);
    size++;
    update();
}

Process Disk::kill()
{
    Process temp = waiting;
    waiting = Process();
    update();
    return waiting;
}

void Disk::update()
{
    if(waiting.getPID() == 0 && !IOQueue.empty())
    {
        waiting = IOQueue.front();
        IOQueue.pop();
        size--;
    }
}

Process Disk::complete()
{
    Process temp = waiting;
    waiting = Process();
    update();
    return temp;
}