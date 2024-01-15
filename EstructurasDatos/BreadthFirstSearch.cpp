#ifndef BFS_H
#define BFS_H

#include "MyGraph.cpp"
#include "MyLinkedList.cpp"
#include "QueueImp.cpp"
#include "Vertex.cpp"

using namespace std;

template<typename T>
class BreadthFirstSearch
{
private:
    MyGraph<T> graph;
    T source;
    MyLinkedList<int> distance,previous;

public:
    BreadthFirstSearch(MyGraph<T> graph, T source):graph(graph), source(source){
        for(int i=0;i<graph.getNumNodes();i++){
            distance.add(-1);
            previous.add(-1);
        }
    }

    BreadthFirstSearch(){}

    MyGraph<T> getGraph() const{
        return graph;
    }

    void setGraph(MyGraph<T> graph){
        this->graph=graph;
    }
    
    T getSource() const{
        return source;
    }

    void setSource(T source){
        this->source=source;
    }

    MyLinkedList<int> getDistance() const{
        return distance;
    }

    void setDistance(MyLinkedList<int> distance) {
        this->distance=distance;
    }

    MyLinkedList<int> getPrevious() const{
        return previous;
    }

    void setPrevious(MyLinkedList<int> previous) {
        this->previous=previous;
    }

    void init(){
        for(int i=0;i<graph.getNumNodes();i++){
            distance.set(i,-1);
            previous.set(i,-1);
        }
    }

    void runSearch(){
        init();
        QueueImp<int> queue;
        distance.set(graph.nodeToNumber(source),0);
        queue.enqueue(graph.nodeToNumber(source));
        while (!queue.isEmpty()){
            int u=queue.dequeue();
            for(Vertex v:graph.getAdj().get(u)){
                if(distance.get(v.getNumber())==-1){
                    distance.set(v.getNumber(),distance.get(u)+1);
                    previous.set(v.getNumber(),u);
                    queue.enqueue(v.getNumber());
                }
            }
        }
    }

    int obtainDistance(T destination){
        return distance.get(graph.nodeToNumber(destination));
    }

    T obtainPrevious(T node){
        int n=graph.nodeToNumber(node);
        return graph.numberToNode(previous.get(n));
    }

    void clear(){
        distance.clear();
        previous.clear();
    }

};

#endif