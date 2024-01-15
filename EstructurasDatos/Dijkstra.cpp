#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "MyGraph.cpp"
#include "MyPriorityQueue.cpp"
#include "MyLinkedList.cpp"
#include "Vertex.cpp"

using namespace std;

template <typename T>
class Dijkstra
{
private:
    const int INF = 1 << 30;
    T source;
    MyGraph<T> graph;
    MyPriorityQueue<Vertex> pq;
    MyLinkedList<double> distance;
    MyLinkedList<int> previous;
    MyLinkedList<bool> visited;
public:
    Dijkstra(MyGraph<T> graph, T source):graph(graph),source(source){
        for(int i=0;i<graph.getNumNodes();i++){
            previous.add(-1);
            distance.add(0);
            visited.add(false);
        }
    }

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

    MyLinkedList<double> getDistance() const{
        return distance;
    }

    void setDistance(MyLinkedList<double> distance) {
        this->distance=distance;
    }

    MyLinkedList<int> getPrevious() const{
        return previous;
    }

    void setPrevious(MyLinkedList<int> previous) {
        this->previous=previous;
    }

    int getINF(){
        return INF;
    }

    MyLinkedList<bool> getVisited() const{
        return visited;
    }

    void setVisited(MyLinkedList<bool> visited) {
        this->visited=visited;
    }

    void init(){
        for(int i=0;i<graph.getNumNodes();i++){
            distance.set(i,INF);
            visited.set(i,false);
            previous.set(i,-1);
        }
    }

    void relaxation(int current, int adjacent, double weigth){
        if(distance.get(current) + weigth< distance.get(adjacent)){
            distance.set(adjacent, distance.get(current) + weigth);
            previous.set(adjacent, current);
            pq.insert(Vertex(adjacent,distance.get(adjacent)));
        }
    }

    void runDijkstra(){
        init();
        int n=graph.nodeToNumber(source);
        pq.insert(Vertex(n,0));
        distance.set(n,0);
        int current, adjacent;
        double weigth;
        while(!pq.isEmpty()){
            current=pq.poll().getNumber();
            if(visited.get(current)){
                continue;
            }
            visited.set(current,true);
            for(int i=0;i<graph.getAdj().get(current).getSize();i++){
                adjacent=graph.getAdj().get(current).get(i).getNumber();
                weigth=graph.getAdj().get(current).get(i).getWeigth();
                if(!visited.get(adjacent)){
                    relaxation(current, adjacent, weigth);
                }
            }
        }
    }

    double obtainDistance(T destination){
        return distance.get(graph.nodeToNumber(destination));
    }

    bool isPath(T destination){
        return visited.get(graph.nodeToNumber(destination));
    }

    void clear(){
        distance.clear();
        previous.clear();
        visited.clear();
    }
};

#endif