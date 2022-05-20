#include "sharedqueue.h"
#include <stdexcept>
#include <iostream>

int SharedQueue::accessors = -1;
SharedQueue *SharedQueue::instance = new SharedQueue();

void SharedQueue::enqueue(int i)
{
    elems.push_back(i);
}

int SharedQueue::dequeue()
{
    int i = elems.front();
    elems.pop_front();
    return i;
}

bool SharedQueue::empty()
{
    return elems.empty();
}

int SharedQueue::size() const
{
    return elems.size();
}

unsigned int SharedQueue::num_references()
{
    // TODO: Implement this function (3.2)
    return accessors;
}

SharedQueue::~SharedQueue()
{
    // TODO: Implement this function(3.3)
    // elems.clear();
    accessors--;
}

SharedQueue &SharedQueue::getInstance()
{
    // TODO: Implement this function (3.4)
    if (accessors > 10)
    {
        throw std::runtime_error("More accessors than allowed(10)!");
    }

    accessors++;
    return *instance;
}

SharedQueue::SharedQueue(const SharedQueue &other)
{
    // TODO: Implement this function (3.5)
    if (accessors > 10)
    {
        throw std::runtime_error("More accessors than allowed(10)!");
    }

    accessors++;
    *this = other;
}

SharedQueue &SharedQueue::operator=(const SharedQueue &rhs)
{
    // TODO: Implement this function (3.6)
    for (int i = 0; i < rhs.size(); i++)
    {
        elems[i] = rhs.elems[i];
    }

    return *this;
}

std::ostream &operator<<(std::ostream &os, const SharedQueue &sq)
{
    for (auto &i : sq.elems)
    {
        os << i << " ";
    }
    os << std::endl;
    return os;
}