#include <vector>

#include "Page.h"
#include "Process.h"

class Ram
{
public:
    Ram();
    Ram(int);

    void print();
    void kill(int);
    void fetch(int,int);
    void add(int,int,bool);
    void add(int,Process,bool);
    void deselect();
    int oldest();
    void updateCPU();
    
private:
    int size;
    int programCounter;
    std::vector<Page> frame;
};