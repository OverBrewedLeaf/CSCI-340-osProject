#include "Cpu.h"
#include "Disk.h"
#include "Ram.h"

class SimulatedOS
{
public:

    SimulatedOS(int, int, int);

    void NewProcess(int);
    void FetchFrom(unsigned int);
    void DiskJobCompleted(int);
    void PrintCPU();//highest prio
    void Exit();//will terminate cpu
    void DiskReadRequested(int disknumber, std::string);//move cpu to disk
    void PrintReadyQueue();
    void PrintRAM();
    void PrintDisk(int);//FIFO
    void PrintDiskQueue(int);

private:
    Cpu cpu = Cpu();
    Ram ram = Ram();
    std::vector<Disk> disk;

    int pageSize;
    int programCounter;
    int pidCounter;
    void update();
};
