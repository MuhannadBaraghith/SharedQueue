#include "sharedqueue.h"
#include <iostream>

int main()
{
    SharedQueue sq = SharedQueue::getInstance();
    sq.enqueue(1);
    sq.enqueue(2);
    std::cout << sq;
    std::cout << "Num of References " << SharedQueue::num_references() << std::endl;
    SharedQueue sq1 = SharedQueue::getInstance();
    std::cout << "Num of References " << SharedQueue::num_references() << std::endl;
    {
        std::cout << "INSIDE THE BLOCK" << std::endl;
        auto sq2 = sq1;
    }
    std::cout << "OUTSIDE THE BLOCK" << std::endl;
    for (int i = 2; i < 11; ++i)
    {
        SharedQueue sq2 = sq1;
        std::cout << "Num of References " << SharedQueue::num_references() << std::endl;
    }
}