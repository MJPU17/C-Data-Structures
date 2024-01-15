#ifndef DEQUELIST_H
#define DEQUELIST_H

#include "DNode.cpp"
#include "MyDoubleLinkedList.cpp"
using namespace std;

template<typename T>
class DequeList : public MyDoubleLinkedList<T>
{
private:
    DNode<T> *tail;

public:
    DequeList():MyDoubleLinkedList<T>(){
        tail=new DNode<T>();
        this->head=new DNode<T>();
        this->head->setNext(tail);
        tail->setPrevious(this->head);
    };

    DNode<T> *getTail() const{
        return tail;
    }

    void setTail(DNode<T> *tail){
        this->tail=tail;
    }

    void insertLast(T info){
        DNode<T> *t=this->tail;
        DNode<T> *temp=new DNode<T>(info);
        temp->setPrevious(t);
        t->setNext(temp);
        this->current=temp;
        tail=temp;
        if(this->size==0)this->head=temp;
        this->size++;
        this->position=this->size-1;
    }

    T removeLast(){
        T value;
        if(tail==nullptr)return value;
        value=tail->getInfo();
        DNode<T> *removed=tail;
        tail=tail->getPrevious();
        if(tail!=nullptr)tail->setNext(nullptr);
        this->size--;
        this->position=this->size-1;
        this->current=tail;
        if(this->size==0){
            tail=new DNode<T>();
            this->head=new DNode<T>();
            this->head->setNext(tail);
            tail->setPrevious(this->head);      
        }
        delete removed;
        return value;
    }

    void insertFirst(T info){
        DNode<T> *h=this->head;
        DNode<T> *temp=new DNode<T>(info);
        temp->setNext(h);
        h->setPrevious(temp);
        this->current=temp;
        this->head=temp;
        if(this->size==0)tail=temp;
        this->size++;
        this->position=0;
    }

    T removeFirst(){
        T value;
        if(this->head==nullptr) return value;
        value=this->head->getInfo();
        DNode<T> *removed=this->head;
        this->head=this->head->getNext();
        if(this->head!=nullptr)this->head->setPrevious(nullptr);
        this->size--;
        this->position=0;
        this->current=this->head;
        if(this->size==0){
            tail=new DNode<T>();
            this->head=new DNode<T>();
            this->head->setNext(tail);
            tail->setPrevious(this->head);      
        }
        delete removed;
        return value;
    }

};

#endif