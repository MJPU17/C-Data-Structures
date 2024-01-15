#ifndef GTNODE_H
#define GTNODE_H

#include "MyDoubleLinkedList.cpp"

template<typename T>
class GTNode
{
private:
    T key;
    MyDoubleLinkedList<GTNode<T>*> childs;
public:
    GTNode(){}

    GTNode(T key):key(key){}

    GTNode(T key,MyDoubleLinkedList<GTNode<T>*> childs):key(key), childs(childs){}

    T getKey() const{
        return key;
    }

    void setKey(T key) {
		this->key = key;
	}

    MyDoubleLinkedList<GTNode<T>*>& getChilds() {
		return childs;
	}

    void setChilds(MyDoubleLinkedList<GTNode<T>*> childs) {
		this->childs = childs;
	}

};

#endif