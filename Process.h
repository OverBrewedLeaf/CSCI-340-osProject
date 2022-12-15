//Jeffrey Li
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
    int getPage();
    int getFrame();
    void setFrame(int);
    void setPage(int);
    void kill();
    std::string getFilename();
    void setFilename(std::string);

private:

    int priority;
    int pid;

    int ramFrame;
    int ramPage;
    
    bool disk;
    std::string filename;
};

#endif