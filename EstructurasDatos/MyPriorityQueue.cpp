#ifndef MYPRIORITYQUEUE_H
#define MYPRIORITYQUEUE_H

#include "MyDoubleLinkedList.cpp"

using namespace std;

template<typename T>
class MyPriorityQueue
{
private:
    MyDoubleLinkedList<T> datas;

public:
    MyPriorityQueue(){}

    void insert(T info){
        for(int i=0;i<datas.getSize();i++){
            if(datas.get(i)>info){
                datas.add(i,info);
                return;
            }
        }
        datas.add(info);
    }
    
    T poll(){
        return datas.remove(0);
    }

    int size(){
        return datas.getSize();
    }

    bool isEmpty(){
        return datas.isEmpty();
    }

    void clear(){
        datas.clear();
    }
};

#endif