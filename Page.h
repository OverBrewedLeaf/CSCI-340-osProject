#include <string>
#include <iostream>

class Page
{   
public:

    Page(int,int);
    int getPage();
    int getPID();
    void setPage(int);
    void setPID(int);
    void print();
    void kill();

private:
    int page;
    int pid;
    bool inCPU;
};