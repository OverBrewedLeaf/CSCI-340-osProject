#include "SimulatedOS.h"

SimulatedOS::SimulatedOS(int numberOfDisks, int amountOfRAM, int page)
{
    if(numberOfDisks < 0 || amountOfRAM < 0 || page < 0 || amountOfRAM % page > 0)
    {
        std::cout << "This OS is not valid\n";
        return;
    }
    for(int i = 0; i < numberOfDisks; i++)
    disk.push_back(Disk());

    disk.resize(numberOfDisks);
    diskSize = numberOfDisks;
    ram = Ram(amountOfRAM/pageSize);
    pageSize = page;
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
    Process temp = cpu.getExecuting();
    temp.setFilename(fileName);
    disk.at(diskNumber).addProcess(temp);
    cpu.exit();
}

void SimulatedOS::FetchFrom(unsigned int memoryAddress)
{

}

void SimulatedOS::DiskJobCompleted(int diskNumber)
{
    Process temp = disk.at(diskNumber).complete();
    cpu.addProcess(temp.getPriority(),temp.getPID(),programCounter);
    programCounter++;
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
    if(diskNumber >= diskSize)
    {
        std::cout << "Instruction ignored: no disk with such number exists\n";
    } 
    else
    {
        std::cout << "Disk " << diskNumber;
        disk.at(diskNumber).print();
    }
}

void SimulatedOS::PrintDiskQueue(int diskNumber)
{
    
    if(diskNumber >= diskSize)
    {
        std::cout << "Instruction ignored: no disk with such number exists\n";
    } 
    else
    {
        std::cout << "Disk " << diskNumber;
        disk.at(diskNumber).printQueue();
    }
}