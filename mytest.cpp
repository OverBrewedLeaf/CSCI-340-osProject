#include "SimulatedOS.h"

int main()
{
	SimulatedOS osSim{3, 96, 32};

    osSim.PrintCPU();
    osSim.PrintReadyQueue();

	osSim.NewProcess(4);
	osSim.PrintRAM();
    osSim.PrintCPU();
    osSim.PrintReadyQueue();

	osSim.NewProcess(2);
	osSim.PrintRAM();
    osSim.PrintCPU();
    osSim.PrintReadyQueue();

	osSim.NewProcess(7);
	osSim.PrintRAM();
	osSim.PrintCPU();
	osSim.PrintReadyQueue();

	osSim.Exit();
	osSim.PrintRAM();
	
	return 0;
}