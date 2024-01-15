#ifndef MNODE_H
#define MNODE_H

template<typename K,typename T>
class MNode
{
private:
    K key;
    T info;
    MNode<K,T> *next;

public:
    MNode(K key, T info, MNode<K,T> *next):key(key), info(info), next(next){}
    MNode(K key, T info):info(info),key(key){
        this->next=nullptr;
    }
    MNode(){}

    K getKey() const{
        return key;
    }

    void setKey(K key){
        this->key=key;
    }

    T getInfo() {
        return info;
    }

    void setInfo(T info){
        this->info=info;
    }

    MNode<K,T>* getNext() const{
        return next;
    }

    void setNext(MNode<K,T> *next){
        this->next=next;
    }

    bool operator==(const MNode<K,T> &other){
        if(key=other.key && info==other.info)return true;
        return false;
    }
};

#endif
