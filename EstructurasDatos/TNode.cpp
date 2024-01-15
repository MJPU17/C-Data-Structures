#ifndef TNODE_H
#define TNODE_H

template<typename T>
class TNode
{
private:
    T key;
    TNode<T> *left, *right;

public:
    TNode(){}

    TNode(T key, TNode<T> *left,TNode<T> *right):key(key), right(right), left(left){}

    TNode(T key):key(key){
        this->left=nullptr;
        this->right=nullptr;
    }

    T getKey() const{
        return key;
    }

    void setKey(T key){
        this->key=key;
    }

    TNode<T>* getLeft() {
        return left;
    }

    void setLeft(TNode<T> *left){
        this->left=left;
    }

    TNode<T>* getRight() {
        return right;
    }

    void setRight(TNode<T> *right){
        this->right=right;
    }

    bool operator==(const TNode<T> &other){
        if(key==other.key)return true;
        return false;
    }

    bool operator!=(const TNode<T> &other){
        if(key!=other.key)return true;
        return false;
    }

};

#endif