#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <iostream>

class Process
{
public:

    Process();
    Process(int,int,int);
    Process(Process, std::string);
    int getPriority();
    int getPID();
    void kill();
    std::string getFilename();
    void setFilename(std::string);    

private:

    int priority;
    int pid;
    int time;
    
    bool disk;
    std::string filename;
};

#endif