#ifndef PROCESS_H
#define PROCESS_H

#include <string>


class Process
{
public:

    Process(int,int,int);
    Process(Process, std::string);
    int getPriority();
    int getPID();
    void kill();

private:

    int priority;
    int pid;
    int time;
    
    bool disk;
    std::string filename;
};

#endif