#include <vector>

#include "Page.h"

class Ram
{
public:
    Ram();
    Ram(int);

    void print();
    void kill(int);
    void fetch(int,int);
    void add(int,int,bool);
    
private:
    int size;
    int oldest();
    int programCounter;
    std::vector<Page> frame;
};