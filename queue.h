#pragma once
#include <iostream>
#define defaultCapacity 10
using namespace std;
template <typename Data>
class Queue
{
private:
    Data *data;
    int capacity;
    int count;
public:
    Queue()
    {
        capacity = defaultCapacity;
        data = new Data[capacity];
        count = 0;
    }
    Queue(int const capacity_in)
    {
        capacity = capacity_in;
        data = new Data[capacity];
        count = 0;
    }
    Queue(int const capacity_in, Data const data_in)
    {
        capacity = capacity_in;
        data = new Data[capacity];
        count = 1;
        data[0] = data_in;
    }
    Queue(Queue const &queue_in)
    {
        capacity = queue_in.capacity;
        data = new Data[capacity];
        for(count = 0; count <queue_in.count; ++count)
            data[count] = queue_in.data[count];
    }
    bool const push(Data const data_in)
    {
        if(count == capacity)
        {
            Data *tmpdata = new Data[capacity * 2];
            if(tmpdata == nullptr)
                return false;
            capacity *= 2;
            for( int i = 0; i < count; ++i)
                tmpdata[i] = data[i];
            delete[]data;
            data = tmpdata;
        }
        data[count++] = data_in;
        return true;
    }
    Data const pop()
    {
        if(count == 0)
            return 0;
        Data tmpdata = data[0];
        for(int i = 0; i < count;++i)
            data[i] = data[i+1];
        --count;
        return tmpdata;
    }
    Data const top() const
    {
        if(count == 0)
            return 0;
        return data[0];
    }
    void clear()
    {
        delete[]data;
        capacity = defaultCapacity;
        count = 0;
        data = new Data[capacity];
    }
    bool const isEmpty() const
    {
        if(count == 0)
            return true;
        return false;
    }
    int const size() const
    {
        return count;
    }
    void print() const
    {
        if(count == 0)
        {
            cout<<"\nQueue is empty"<<endl;
        }else{
            for(int i = 0; i<count;)
                cout<<"\t"<<data[i++];
        }
    }
    Queue& operator = (Queue const &queue_in)
    {
        delete[] data;
        capacity = queue_in.capacity;
        data = new Data[capacity];
        for(count = 0; count <queue_in.count; ++count)
            data[count] = queue_in.data[count];
        return *this;
    }
    ~Queue()
    {
        delete[] data;
        count = 0;
        capacity = 0;
    }
};
