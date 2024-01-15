#ifndef STACKIMP_H
#define STACKIMP_H

#include "MyDoubleLinkedList.cpp"
#include "DequeList.cpp"

using namespace std;

template<typename T>
class StackImp
{
private:
    DequeList<T> infos;

public:
    StackImp(){};

    void push(T info){
        infos.insertLast(info);
    }

    T pop(){
        return infos.removeLast();
    }

    T peek(){
        return infos.getTail()->getInfo();
    }

    int size(){
        return infos.getSize();
    }

    bool isEmpty(){
        return infos.isEmpty();
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