#include "Cpu.h"

Cpu::Cpu()
{
    ram = Ram(0);
}

Cpu::Cpu(int ramSize)
{
    ram = Ram(ramSize);
}

Process Cpu::getExecuting()
{
    return executing;
}

void Cpu::exit()
{
    // std::cerr << "Exited CPU PID: " << executing.getPID() << "\n";
    ram.kill(executing.getPID());
    executing.kill();
    update();
}

void Cpu::printReadyQueue()
{
    std::vector<Process> temp;
    int tempQueueSize = 0;
    for(int i = 0; i < readyQueue.size(); i++)
    {
        if(readyQueue.at(i).getPID() > 0)
        {
            temp.push_back(readyQueue.at(i));
        }
    }
    readyQueue = temp;
    std::cout << "Ready-Queue: ";
    if(readyQueue.size() == 0)
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

void Cpu::addProcess(Process temp)
{
    // temp.setFrame(ram.oldest()); // temp should replace oldest frame... unless temp exists within ram already
    // std::cerr << "CPU: Page: " << temp.getPage() << "\tPID: " << temp.getPID() << "\n";
    readyQueue.push_back(temp);
    ram.add(temp.getPage(),temp.getPID(),true);
    ram.deselect();
    update();
}

void Cpu::printExecuting()
{
    if(executing.getPID() == 0)
    {
        std::cout << "Cpu: Idle\n";
    }
    else std::cout << "Cpu: " << executing.getPID() << std::endl;
}

/*
    CPU has to check for possible higher priorities and swap
    If a swap occurs, Ram has to be updated
    If no swap occurs, CPU age in ram must be updated
*/
void Cpu::update()
{
    Process temp = executing;
    int max = -1;
    for(int i = 0; i < readyQueue.size(); i++)
    {
        if(readyQueue.at(i).getPriority() > temp.getPriority())
        {
            temp = readyQueue.at(i);
            max = i;
        }
    }
    if(max > -1)//cpu changing executing process
    {
        readyQueue.push_back(executing);
        executing = temp;
        ram.add(executing.getPage(),executing.getPID(),true);
        readyQueue.at(max) = Process();// remove old process from queue
    }
    else
    {
        ram.updateCPU();
        programCounter++;
    }
    
}

void Cpu::fetch(int memory)
{
    ram.fetch(memory,executing.getPID());
    executing.setPage(memory);
}

void Cpu::printRAM()
{
    ram.print();
}

void Cpu::moveDisk()
{
    ram.deselect();
    executing = Process();
    update();
    ram.updateCPU();
}