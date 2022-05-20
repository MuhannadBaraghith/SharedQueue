#include <deque>
#include <iostream>

#ifndef _SHAREDQ_H_
#define _SHAREDQ_H_
class SharedQueue
{
private:
    std::deque<int> elems;
    SharedQueue() {}
    // TODO: Define member data here (Q 3.1)
    static SharedQueue *instance;
    static int accessors;

public:
    SharedQueue(const SharedQueue &);
    ~SharedQueue();

    void enqueue(int);
    int dequeue();
    bool empty();
    int size() const;
    static SharedQueue &getInstance();
    SharedQueue &operator=(const SharedQueue &);
    static unsigned int num_references();

    friend std::ostream &operator<<(std::ostream &os, const SharedQueue &sq);
};
#endif
