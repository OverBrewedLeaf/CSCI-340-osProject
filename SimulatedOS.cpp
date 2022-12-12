#include "SimulatedOS.h"

SimulatedOS::SimulatedOS(int numberOfDisks, int amountOfRAM, int page)
{
    if(numberOfDisks < 0 || amountOfRAM < 0 || page < 0 || amountOfRAM % page > 0)
    {
        std::cout << "This OS is not valid\n";
        return;
    }
    for(int i = 0; i < numberOfDisks; i++)
    {
        disk.push_back(Disk());
    }
    pageSize= page;
    ram = Ram(amountOfRAM/pageSize);
    programCounter = 0;
    pidCounter = 1;
    return;
}

void SimulatedOS::NewProcess(int priority)
{
    cpu.addProcess(priority,pidCounter++,programCounter);
    programCounter++;
}

void SimulatedOS::Exit()
{
    cpu.exit();
    ram.kill(cpu.getExecuting().getPID());
}

void SimulatedOS::DiskReadRequested(int diskNumber, std::string fileName)
{
    
    cpu.exit();
}

void SimulatedOS::FetchFrom(unsigned int memoryAddress)
{

}

void SimulatedOS::DiskJobCompleted(int diskNumber)
{

}

void SimulatedOS::PrintCPU()
{
    cpu.printExecuting();
}

void SimulatedOS::PrintReadyQueue()
{
    cpu.printReadyQueue();
}

void SimulatedOS::PrintRAM()
{
    std::cout << "Frame\tPage\tPID\n";
    ram.print();
}

void SimulatedOS::PrintDisk(int diskNumber)
{

}

void SimulatedOS::PrintDiskQueue(int diskNumber)
{

}