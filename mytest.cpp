#include "SimulatedOS.h"

int main()
{
	// SimulatedOS osSim{4, 16, 4};

	// osSim.NewProcess(4);
	// osSim.PrintRAM();

	// osSim.NewProcess(2);
	// osSim.PrintRAM();

	// osSim.NewProcess(7);
	// osSim.PrintRAM();

	// osSim.FetchFrom(10);
	// osSim.PrintRAM();

	// osSim.FetchFrom(10);
	// osSim.PrintRAM();

	// osSim.FetchFrom(14);
	// osSim.PrintRAM();

	// osSim.Exit();
	// osSim.PrintRAM();

	// osSim.Exit();
	// osSim.PrintRAM();

	// osSim.Exit();
	// osSim.PrintRAM();

	SimulatedOS osSim{3, 96, 32};

	osSim.NewProcess(4);
	osSim.NewProcess(2);
	osSim.NewProcess(7);

	osSim.PrintCPU();
	// CPU: 3

	osSim.PrintReadyQueue();
	// Ready-Queue: 1 2

	osSim.DiskReadRequested(0, "HW.txt");

	// osSim.PrintCPU();
	// // CPU: 1

	osSim.PrintDisk(0);
	// Disk 0: PID 3, "HW.txt"

	osSim.PrintDiskQueue(0);
	// Disk 0 I/O-queue: Empty

	osSim.PrintDiskQueue(5);
	// Instruction ignored: no disk with such number exists
	
	osSim.DiskJobCompleted(0);

	osSim.PrintRAM();
	
	// osSim.PrintCPU();
	// // CPU: 3

	osSim.PrintDisk(0);
	// Disk 0: Idle

	osSim.FetchFrom(48);
	osSim.PrintRAM();
	// Frame	Page	PID
	// 0		0		1
	// 1		1		3
	// 2		0		3

	osSim.Exit();

	osSim.PrintCPU();
	// CPU: 1

	osSim.PrintRAM();
	// Frame	Page	PID
	// 0		0		1
	
	return 0;
}

