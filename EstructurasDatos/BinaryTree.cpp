#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TNode.cpp"
#include "MyLinkedList.cpp"
#include <iostream>

using namespace std;

template<typename T>
class BinaryTree
{
private:
    TNode<T> *root;
    MyLinkedList<T> route;

public:
    BinaryTree(){
        this->root=nullptr;
    }

    TNode<T>* getRoot() const{
        return root;
    }

    void setRoot(TNode<T> *root){
        this->root=root;
    }

    MyLinkedList<T> getRoute() const{
        return route;
    }

    void setRoute(MyLinkedList<T> route) {
        this->route=route;
    }

    TNode<T>* insertRec(TNode<T> *root, T key) {
        if(root==nullptr){
            root=new TNode<T>(key);
            return root;
        }
        if(key<=root->getKey()){
            root->setLeft(insertRec(root->getLeft(),key));
        }
        else if(key>root->getKey()){
            root->setRight(insertRec(root->getRight(),key));
        }
        return root;
    }

    void insert(T key){
        root=insertRec(root,key);
    }

    void inOrderRec(TNode<T> *root){
        if(root != nullptr){
            inOrderRec(root->getLeft());
            route.addLast(root->getKey());
            inOrderRec(root->getRight());
        }
    }

    void postOrderRec(TNode<T> *root){
        if(root!=nullptr){
            postOrderRec(root->getLeft());
            postOrderRec(root->getRight());
            route.addLast(root->getKey());
        }
    }

    void preOrderRec(TNode<T> *root){
        if(root!=nullptr){
            route.addLast(root->getKey());
            preOrderRec(root->getLeft());
            preOrderRec(root->getRight());
        }
    }

    MyLinkedList<T> inOrder(){
        route.clear();
        inOrderRec(root);
        return route;
    }

    MyLinkedList<T> preOrder(){
        route.clear();
        preOrderRec(root);
        return route;
    }

    MyLinkedList<T> postOrder(){
        route.clear();
        postOrderRec(root);
        return route;
    }

    void removeLeaves(TNode<T> *root){
        if(root!=nullptr){
            removeLeaves(root->getLeft());
            removeLeaves(root->getRight());
            delete root;
            root=nullptr;
        }
    }

    void clear(){
        removeLeaves(root);
        root=nullptr;
        route.clear();
    }
    
};

#endif
