#include <string>
#include <iostream>

class Page
{   
public:

    Page(int,int);
    int getPage();
    int getPID();
    int getAge();
    void setPage(int);
    void setPID(int);
    void print();
    void kill();

private:
    int page;
    int pid;
    bool inCPU;
    int trueAge;
};