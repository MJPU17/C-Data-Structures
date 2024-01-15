#ifndef DFS_H
#define DFS_H

#include "MyGraph.cpp"
#include "MyLinkedList.cpp"
#include "Vertex.cpp"

using namespace std;

template<typename T>
class DeepFirstSearch
{
private:
    MyGraph<T> graph;
    T source;
    MyLinkedList<int> discover,termination;
    int time;

public:
    DeepFirstSearch(MyGraph<T> graph, T source):graph(graph), source(source){
        for(int i=0;i<graph.getNumNodes();i++){
            discover.add(0);
            termination.add(0);
        }
    };

    DeepFirstSearch(){}

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

    MyLinkedList<int> getDiscover() const{
        return discover;
    }

    void setDiscover(MyLinkedList<int> discover){
        this->discover=discover;
    }

    MyLinkedList<int> getTermination() const{
        return termination;
    }

    void setTermination(MyLinkedList<int> termination){
        this->termination=termination;
    }

    void runSearchUtil(int u){
        discover.set(u,time++);
        for(Vertex v:graph.getAdj().get(u)){
            if(discover.get(v.getNumber())==0){
                runSearchUtil(v.getNumber());
            }
        }
        termination.set(u,time++);
    }

    void runSearch(){
        for(int i=0;i<graph.getNumNodes();i++){
            discover.set(i,0);
            termination.set(i,0);
        }
        time=1;
        runSearchUtil(graph.nodeToNumber(source));
    }

    int obtainDiscover(T node){
        return discover.get(graph.nodeToNumber(node));
    }

    int obtainTermination(T node){
        return termination.get(graph.nodeToNumber(node));
    }

    void clear(){
        discover.clear();
        termination.clear();
    }


};

#endif