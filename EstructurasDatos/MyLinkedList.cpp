#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include "Node.cpp"

using namespace std;

template<typename T>
class MyIterator
{
private:
    Node<T>* current;
public:
    MyIterator(Node<T>* start):current(start){}

    T operator*() {
       return current->getInfo();
   }

   MyIterator& operator++() {
       current = current->getNext();
       return *this;
   }

   bool operator!=(const MyIterator& other) const {
       return current != other.current;
   }
};

template<class T>
class MyLinkedList {

private:
    Node<T> *first; 
    int size;

public:
    MyLinkedList() {
        first = nullptr; 
        size = 0;
    }

    Node<T> *getFirst() const {
        return first;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return (size == 0);
    }

    void add(T info){
        Node<T> *newNode = new Node<T>(info,first);
        first = newNode;
        size++;
    }

    Node<T> *getLast() {
        Node<T> *current = first;
        while (!isEmpty() && current->getNext() != nullptr) {
            current = current->getNext();
        }
        return current;
    }

    void addLast(T info) {
        Node<T> *newNode= new Node<T>(info); 
        if (isEmpty()) {
            first = newNode;
        } else {
            getLast()->setNext(newNode);
        }
        size++;
    }

    Node<T> *getNode(int n){
        Node<T> *current = first;
        int count=0;
        if(n<0 || n>=size)throw "Index is invalid.";
        while (!isEmpty() && count<n) {
            current = current->getNext();
            count++;
        }
        return current;

    }

    T get(int n){
        if(n<0 || n>=size)throw "Index is invalid.";
        return getNode(n)->getInfo();
    }

    void remove(int n){
        if(n<0 || n>=size)throw "Index is invalid.";
        Node<T> *removed;
        if(n==0){
            removed=first;
            if(first->getNext()!=nullptr)first = first->getNext();
            else first = nullptr;
            delete removed;
        }
        else{
            removed=getNode(n);
            getNode(n-1)->setNext(removed->getNext());
            delete removed;
        }
        size--;
    }

    void set(int n, T info){
        if(n<0 || n>=size)throw "Index is invalid.";
        getNode(n)->setInfo(info);
    }

    MyIterator<T> begin(){
        return MyIterator<T>(first);
    }

    MyIterator<T> end(){
        return MyIterator<T>(nullptr);
    }

    void clear(){
        while(!isEmpty()){
            remove(0);
        }
    }

};

#endif