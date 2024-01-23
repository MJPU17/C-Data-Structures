#ifndef MYDOUBLELINKEDLIST_H
#define MYDOUBLELINKEDLIST_H

#include "DNode.cpp"
#include <cmath>
#include<cstdio>

using namespace std;

template<typename T>
class MyDIterator
{
private:
    DNode<T>* node;
public:
    MyDIterator(DNode<T>* start):node(start){}

    T operator*() {
       return node->getInfo();
   }

   MyDIterator& operator++() {
       node = node->getNext();
       return *this;
   }

   bool operator!=(const MyDIterator& other) const {
       return node != other.node;
   }
};


template<typename T>
class MyDoubleLinkedList
{
protected:
    DNode<T> *head, *current;
    int position,size;

public:
    MyDoubleLinkedList(){
        position=-1;
        size=0;
        head=nullptr;
        current=nullptr;
    };

    DNode<T> *getHead() const{
		return head;
	}

    void setHead(DNode<T> *head) {
		this->head = head;
	}

    DNode<T> *getCurrent() const{
		return current;
	}

    void setCurrent(DNode<T> *current) {
		this->current = current;
	}

    int getPosition() const{
		return position;
	}

    int getSize() const{
		return size;
	}

    bool isEmpty(){
        return (size==0);
    }

    void forward(int numposition){
        if(numposition>0 && this->head!=nullptr){
            int positionForward=numposition;
            if(this->current==nullptr){
                current=head;
                positionForward--;
                position++;
            }
            while (current->getNext()!=nullptr && positionForward>0){
                current=current->getNext();
                positionForward--;
                position++;
            }
        }
    }

    void backward(int numposition){
        if(numposition<=0 || head==nullptr || current==nullptr) return;
        int positionBackward=numposition;
        while (current!=nullptr && positionBackward>0){
            current=current->getPrevious();
            positionBackward--;
            position--;
        }  
    }

    void insert(T info){
        DNode<T> *temp=new DNode<T>(info);
        if(this->current==nullptr){
            temp->setNext(head);
            if(this->head!=nullptr)head->setPrevious(temp);
            head=temp;
        }
        else {
            temp->setNext(current->getNext());
            temp->setPrevious(current);
            if(current->getNext()!=nullptr)current->getNext()->setPrevious(temp);
            current->setNext(temp);
        }
        current=temp;
        position++;
        size++;
    }

    T extract(){
        T info;
        if(this->current!=nullptr){
            info=current->getInfo();
            DNode<T> *removed=current;
            if(this->head==this->current && position==0)head=current->getNext();
            else current->getPrevious()->setNext(current->getNext());
            if(current->getNext()!=nullptr)current->getNext()->setPrevious(current->getPrevious());
            current=current->getNext();
            if(size-1==position)position=-1;
            size--;
            delete removed;
            removed=nullptr;
        }
        return info;
    }

    T remove(int index){
        if(position>index)backward(abs(position-index));
        else forward(abs(position-index));
        return extract();
    }

    void addInit(T info){
        backward(size);
        insert(info);
    }

    void add(T info){
        forward(size);
        insert(info);
    }

    void add(int index, T info){
        index-=1;
        if(position>index)backward(abs(position-index));
        else forward(abs(position-index));
        insert(info);
    }

    T get(int index){
        if(position>index)backward(abs(position-index));
        else forward(abs(position-index));
        return current->getInfo();
    }

    void set(int index, T info){
        if(position>index)backward(abs(position-index));
        else forward(abs(position-index));
        current->setInfo(info);
    }

    MyDIterator<T> begin(){
        return MyDIterator<T>(head);
    }

    MyDIterator<T> end(){
        return MyDIterator<T>(nullptr);
    }

    void clear(){
        while(!isEmpty()){
            remove(0);
        }
    }

};

#endif
