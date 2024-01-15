#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T info;
    Node<T> *next;

public:
    Node(T info, Node<T> *next) : info(info), next(next) {}
    Node() {}
    Node(T info) : info(info){
        this->next=nullptr;
    }

    T getInfo(){
        return info;
    }

    void setInfo(T info) {
        this->info = info;
    }

    Node<T>* getNext() const{
        return next;
    }

    void setNext(Node<T> *next) {
        this->next = next;
    }

    bool operator==(const Node<T> &other){
        if(info==other.info){
            return true;
        }
        return false;
    }

    bool operator!=(const Node<T> &other){
        if(info!=other.info){
            return true;
        }
        return false;
    }

};

#endif