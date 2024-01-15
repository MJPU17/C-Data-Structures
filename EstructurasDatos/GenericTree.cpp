#ifndef GENERICTREE_H
#define GENERICTREE_H

#include "GTNode.cpp"
#include "MyLinkedList.cpp"
#include "MyMap.cpp"
#include "QueueImp.cpp"

template<typename T>
class GenericTree
{
private:
    GTNode<T> *root;
    MyLinkedList<T> route;
    MyMap<int,MyLinkedList<T>> levels;
    bool add;

public:
    GenericTree(){
        root=nullptr;
    }

     GTNode<T>* getRoot() const{
		return root;
	}

    void setRoot(GTNode<T> *root) {
		this->root = root;
	}

    MyLinkedList<T> getRoute() const{
        return route;
    }

    void setRoute(MyLinkedList<T> route) {
        this->route=route;
    }

    MyMap<int,MyLinkedList<T>> getLevels() const{
        return levels;
    }

    void setLevels(MyMap<int,MyLinkedList<T>> levels){
        this->levels=levels;
    }

    GTNode<T>* searchNodeUtil(GTNode<T> *root, T search){
        if(root->getKey()==search){
            return root;
        }
        GTNode<T> *aux;
        for(int i=0;i<root->getChilds().getSize();i++){
            aux=searchNodeUtil(root->getChilds().get(i),search);
            if(aux!=nullptr)return aux;
        }
        return nullptr;
    }

    GTNode<T>* searchNode(T search) {
		return searchNodeUtil(root, search);
	}

    void addChild(GTNode<T> *node, T father, T child){
        if(node->getKey()==father){
            GTNode<T> *aux=new GTNode<T>(child);
            node->getChilds().add(aux);
            add=true;
        }
        for (int i = 0; !add && i < node->getChilds().getSize(); i++) {
			addChild(node->getChilds().get(i), father, child);
		}
    }
    
    void addNode(T root){
        this->root=new GTNode<T>(root);
    }

    bool addNode(T father, T child){
        add=false;
        if(searchNode(child)==nullptr)addChild(this->root,father,child);
        return add;
    }

    void levelOrder(GTNode<T> *root){
        if(root==nullptr)return;
        int level=0;
        route.clear();
        levels.clear();
        QueueImp<GTNode<T>*> q;
        q.enqueue(root);
        while(!q.isEmpty()){
            int n=q.size();
            MyLinkedList<T> aux;
            while(n>0){
                GTNode<T> *current=q.dequeue();
                aux.addLast(current->getKey());
                for (int i = 0; i < current->getChilds().getSize(); i++) {
					q.enqueue(current->getChilds().get(i));
				}
				n--;
            }
            levels.put(level,aux);
            level++;
        }
    }

    void preOrderRec(GTNode<T> *root){
        if(root!=nullptr){
            route.addLast(root->getKey());
            for(GTNode<T> *child:root->getChilds()){
                preOrderRec(child);
            }
        }
    }

    void postOrderRec(GTNode<T> *root){
        if(root!=nullptr){
            for(GTNode<T> *child:root->getChilds()){
                postOrderRec(child);
            }
            route.addLast(root->getKey());
        }
    }

    MyLinkedList<T> preOrder(GTNode<T> *root){
        route.clear();
        preOrderRec(root);
        return route;
    }

    MyLinkedList<T> postOrder(GTNode<T> *root){
        route.clear();
        postOrderRec(root);
        return route;
    }

    void removeLeaves(GTNode<T> *root){
        if(root!=nullptr){
            for(GTNode<T> *child: root->getChilds()){
                removeLeaves(child);
            }
            root->getChilds().clear();
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