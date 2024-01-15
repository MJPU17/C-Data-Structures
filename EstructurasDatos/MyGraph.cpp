#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "Vertex.cpp"
#include "MyMap.cpp"
#include "MyDoubleLinkedList.cpp"
#include<cstdio>

using namespace std;

template<typename T>
class MyGraph
{
private:
    int numNodes,numEdges;
    MyMap<T, int> traduct;
    MyMap<int,T> inverseTraduct;
    MyDoubleLinkedList<MyDoubleLinkedList<Vertex>> adj;
    
public:
    MyGraph(){
        numEdges=0;
        numNodes=0;
    };

    int getNumNodes() const{
        return numNodes;
    }

    void setNumNodes(int numNodes) {
        this->numNodes=numNodes;
	}

    int getNumEdges() const{
        return numEdges;
    }

    void setNumEdges(int numEdges) {
		this->numEdges=numEdges;
	}

    MyMap<T, int> getTraduct() const{
		return traduct;
	}

    void setTraduct(MyMap<T, int> traduct) {
		this->traduct=traduct;
	}

    MyMap<int, T> getInverseTraduct() const{
		return inverseTraduct;
	}

    void setInverseTraduct(MyMap<int, T> inverseTraduct) {
		this->inverseTraduct=inverseTraduct;
	}

    MyDoubleLinkedList<MyDoubleLinkedList<Vertex>> getAdj() const{
		return adj;
    }

    void setAdj(MyDoubleLinkedList<MyDoubleLinkedList<Vertex>> adj) {
		this->adj=adj;
	}

    void addNode(T node){
        traduct.put(node,numNodes);
        inverseTraduct.put(numNodes,node);
        adj.add(MyDoubleLinkedList<Vertex>());
        numNodes++;
    }

    void addEdge(T source, T destination, double weigth){
        int index=traduct.getValue(source);
        MyDoubleLinkedList<Vertex> aux=adj.get(index);
        aux.add(Vertex(traduct.getValue(destination),weigth));
        adj.set(index,aux);
        numEdges++;
    }

    int nodeToNumber(T node){
        if(traduct.containsKey(node)){
            return traduct.getValue(node);
        }
        return -1;
    }

    T numberToNode(int node){
        return inverseTraduct.getValue(node);
    }

    void clear(){
        numNodes=0;
        numEdges=0;
        traduct.clear();
        inverseTraduct.clear();
        adj.clear();
    }
    
};

#endif