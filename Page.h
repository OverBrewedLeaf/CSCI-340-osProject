//Jeffrey Li
#include <string>
#include <iostream>

class Page
{   
public:

    Page(int,int,int);
    int getPage();
    int getPID();
    int getAge();
    bool getCPU();
    void setPage(int);
    void setPID(int);
    void setCPU(bool);
    void setAge(int);
    void print();
    void kill();

private:
    int page;
    int pid;
    bool inCPU;
    int trueAge;
};