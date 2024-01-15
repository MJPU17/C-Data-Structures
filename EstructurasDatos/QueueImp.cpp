#ifndef QUEUEIMP_H
#define QUEUEIMP_H

#include "MyDoubleLinkedList.cpp"
#include "DequeList.cpp"

using namespace std;

template<typename T>
class QueueImp
{
private:
    DequeList<T> infos;

public:
    QueueImp(){}

    void enqueue(T info){
        infos.insertLast(info);
    }

    T dequeue(){
        return infos.removeFirst();
    }

    int size(){
        return infos.getSize();
    }

    bool isEmpty(){
        return infos.isEmpty();
    }

    T peek(){
        return infos.getHead()->getInfo();
    }

    MyDIterator<T> begin(){
        return infos.begin();
    }

    MyDIterator<T> end(){
        return infos.end();
    }

    void clear(){
        infos.clear();
    }
    
};

#endif