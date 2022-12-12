#include "Cpu.h"

Cpu::Cpu()
{
    queueSize = 0;
}

Process Cpu::getExecuting()
{
    return executing;
}

void Cpu::exit()
{
    executing.kill();
    if(queueSize > 0)
    {
        executing = readyQueue.back();
        readyQueue.pop_back();
        queueSize--;
    }

}

void Cpu::printReadyQueue()
{
    std::cout << "Ready-Queue: ";
    for(Process x: readyQueue)
    {
        if(x.getPID() > 0)
        {
            std::cout << x.getPID() << " ";
        }
    }
    std::cout << std::endl;
}

bool Cpu::addProcess(int prio,int pid, int& time)
{   
    if(prio == executing.getPriority())
    {
        return false;
    }
    if(prio > executing.getPriority())
    {
        Process temp = executing;
        executing = Process(prio,pid,time++);
        return addProcess(temp.getPriority(), temp.getPID(), time);//fix timestamp
    }
    queueSize++;
    readyQueue.push_back(Process(prio,pid,time));
    return true;
}

void Cpu::printExecuting()
{
    std::cout << "Cpu: " << executing.getPID() << std::endl;
}

void Cpu::update()
{
    for(int i = 0; i <= queueSize; i++)
    {
        if(readyQueue.at(i).getPriority() > executing.getPriority())
        {
            readyQueue.push_back(executing);
            executing = readyQueue.at(i);
            readyQueue.erase(i+readyQueue.begin());
            return update();
        }
    }
    
}