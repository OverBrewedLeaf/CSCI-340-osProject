#include "Cpu.h"

Cpu::Cpu()
{
    queueSize = 0;
    ram = Ram(0);
}

Cpu::Cpu(int ramSize)
{
    queueSize = 0;
    ram = Ram(ramSize);
}

Process Cpu::getExecuting()
{
    return executing;
}

void Cpu::exit()
{
    std::cerr << "Exited CPU PID: " << executing.getPID() << "\n";
    ram.kill(executing.getPID());
    executing.kill();
    update();

}

void Cpu::printReadyQueue()
{
    std::vector<Process> temp;
    int tempQueueSize = 0;
    for(int i = 0; i < queueSize; i++)
    {
        if(readyQueue.at(i).getPID() > 0)
        {
            temp.push_back(readyQueue.at(i));
            tempQueueSize++;
        }
    }
    readyQueue = temp;
    queueSize = tempQueueSize;
    std::cout << "Ready-Queue: ";
    if(queueSize == 0)
    {
        std::cout << "Empty\n";
    }
    else
    {
        for(Process x: readyQueue)
        {
            if(x.getPID() > 0)
            {
                std::cout << x.getPID() << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool Cpu::addProcess(int prio, int pid)
{   
    if(prio == executing.getPriority())
    {
        return false;
    }
    queueSize++;
    readyQueue.push_back(Process(prio,pid));
    update();
    return true;
}

void Cpu::printExecuting()
{
    if(executing.getPID() == 0)
    {
        std::cout << "Cpu: Idle\n";
    }
    else std::cout << "Cpu: " << executing.getPID() << std::endl;
}

void Cpu::update()
{
    Process temp = executing;
    bool change = false;
    int max = 0;
    for(int i = 0; i < queueSize; i++)
    {
        if(readyQueue.at(i).getPriority() > temp.getPriority())
        {
            temp = readyQueue.at(i);
            change = true;
            max = i;
        }
    }
    if(change)
    {
        Process temp2 = executing;
        executing = temp;
        ram.add(0,executing.getPID(),true);
        readyQueue.push_back(temp2);
        queueSize++;
        readyQueue.at(max) = Process();
    }
    
}

void Cpu::fetch(int memory)
{
    ram.fetch(memory,executing.getPID());
}

void Cpu::printRAM()
{
    ram.print();
}