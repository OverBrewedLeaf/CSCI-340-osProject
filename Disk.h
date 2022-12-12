#include <queue>
#include "Process.h"

class Disk
{
public:

    Disk();

private:
    std::queue<Process> IOQueue;
    Process waiting = Process(Process(0,0,0),"");
};