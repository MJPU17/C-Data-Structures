#ifndef MYMAP_H
#define MYMAP_H

#include "MNode.cpp"
#include <utility>

using namespace std;

template<typename K, typename T>
class MyMIterator
{
private:
    MNode<K,T>* node;

public:
    MyMIterator(MNode<K,T>* start):node(start){};
    
    pair<K,T> operator*() {
       return pair<K,T>(node->getKey(),node->getInfo());
    }
    
    MyMIterator& operator++() {
       node = node->getNext();
       return *this;
    }
    
    bool operator!=(const MyMIterator& other) const {
       return node != other.node;
    }
};

template<typename K, typename T>
class MyMap
{
private:
    MNode<K,T> *first;
    int size;

public:
    MyMap(){
        this->size=0;
        this->first=nullptr;
    }

    int getSize() const{
        return size;
    }

    bool isEmpty(){
        return (size==0);
    }

    bool containsKey(K key){
        MNode<K,T> *current=first;
        while (current!=nullptr){
            if(current->getKey()==key)return true;
            current=current->getNext();
        }
        return false;
    }

    void put(K key, T info){
        MNode<K,T> *newNode= new MNode<K,T>(key,info);
        if(this->first==nullptr)first=newNode;
        else {
            MNode<K,T> *current=first;
            while(current->getNext()!=nullptr){
                if(current->getKey()==key){
                    current->setInfo(info);
                    return;
                }
                current=current->getNext();
            }
            if(current->getKey()==key){
                current->setInfo(info);
                return;
            }
            current->setNext(newNode);
        }
        size++;
    }

    bool replace(K key, T info){
        MNode<K,T> *current=first;
        while (current!=nullptr){
            if(current->getKey()==key){
                current->setInfo(info);
                return true;
            }
            current=current->getNext();
        }
        return false;
    }

    bool remove(K key){
        if(this->first->getKey()==key){
            first=first->getNext();
            size--;
        }
        else{
            MNode<K,T> *current=first;
            while (current->getNext()!=nullptr){
                if(current->getNext()->getKey()==key){
                    size--;
                    MNode<K,T> *removed=current->getNext();
                    current->setNext(current->getNext()->getNext());
                    delete removed;
                    return true;
                }
                current=current->getNext();
            }
        }
        return false;
    }

    T getValue(K key){
        MNode<K,T> *current=first;
        T value;
        while(current!=nullptr){
            if(current->getKey()==key){
                value=current->getInfo();
                break;
            }
            current=current->getNext();
        }
        return value;
    }

    MyMIterator<K,T> begin(){
        return MyMIterator<K,T>(first);
    }

    MyMIterator<K,T> end(){
        return MyMIterator<K,T>(nullptr);
    }

    void clear(){
        while (!isEmpty()){
            remove(first->getKey());
        }
    }    

};

#endif
