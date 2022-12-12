#include <vector>

#include "Page.h"

class Ram
{
public:
    Ram();
    Ram(int);

    void print();
    void kill(int);
    int oldest();
    
private:
    int size;
    std::vector<Page> frame;
};