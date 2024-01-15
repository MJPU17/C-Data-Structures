#ifndef DNODE_H
#define DNODE_H

template <typename T>
class DNode
{
private:
    T info;
    DNode<T> *previous, *next;
     
public:
    DNode(T info, DNode<T> *next, DNode<T> *previous): info(info), next(next), previous(previous){}
    DNode(T info): info(info){
        this->previous=nullptr;
        this->next=nullptr;
    }
    DNode(){
    }

    T getInfo() const{
        return info;
    }

    void setInfo(T info){
        this->info=info;
    }

    DNode<T>* getPrevious() const{
        return previous;
    }

    void setPrevious(DNode<T> *previous){
        this->previous=previous;
    }

    DNode<T>* getNext() const{
        return next;
    }

    void setNext(DNode<T> *next){
        this->next=next;
    }

    bool operator==(const DNode<T> &other){
        if(info==other.info)return true;
        return false;
    }

    bool operator!=(const DNode<T> &other){
        if(info!=other.info)return true;
        return false;
    }

};

#endif