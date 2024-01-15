#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "MyGraph.cpp"
#include "MyLinkedList.cpp"

using namespace std;

template<typename T>
class BellmanFord
{
private:
    T source;
    MyGraph<T> graph;
    MyLinkedList<int> previous;
    MyLinkedList<double> distance;
    const int INF = 1 << 30;
    bool negativeCicle;

public:
    BellmanFord(MyGraph<T> graph, T source):graph(graph),source(source){
        this->negativeCicle=false;
        for(int i=0;i<graph.getNumNodes();i++){
            previous.add(0);
            distance.add(0);
        }
    }

    BellmanFord(){}

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

    bool isNegativeCicle() const{
        return negativeCicle;
    }

    void setNegativeCicle(bool negativeCicle){
        this->negativeCicle=negativeCicle;
    }

    int getINF(){
        return INF;
    }

    void init(){
        this->negativeCicle=false;
        for(int i=0;i<graph.getNumNodes();i++){
            distance.set(i,INF);
            previous.set(i,-1);
        }
    }

    bool relaxation(int current, int adjacent, double weigth){
        if(distance.get(current) + weigth < distance.get(adjacent)){
            distance.set(adjacent,distance.get(current) + weigth);
            previous.set(adjacent,current);
            return true;
        }
        return false;
    }

    void initBellmanFord(){
        init();
        distance.set(graph.nodeToNumber(source),0);
        for(int i=0;i<graph.getNumNodes()-1;i++){
            for(int current=0; current<graph.getNumNodes();current++){
                for(int j=0;j<graph.getAdj().get(current).getSize();j++){
                    int adjacent=graph.getAdj().get(current).get(j).getNumber();
                    double weigth=graph.getAdj().get(current).get(j).getWeigth();
                    relaxation(current,adjacent,weigth);
                }
            }
        }
        for(int current=0; current<graph.getNumNodes();current++){
            for(int j=0;j<graph.getAdj().get(current).getSize();j++){
                int adjacent=graph.getAdj().get(current).get(j).getNumber();
                double weigth=graph.getAdj().get(current).get(j).getWeigth();
                if(relaxation(current,adjacent,weigth)){
                    negativeCicle=true;
                    return;
                }
            }
        }
    }

    double obtainDistance(T destination){
        return distance.get(graph.nodeToNumber(destination));
    }

    bool isPath(T destination){
        int current=graph.nodeToNumber(destination);
        while(previous.get(current)!=-1)current=previous.get(current);
        return current==graph.nodeToNumber(source);
    }

    void clear(){
        distance.clear();
        previous.clear();
    }
};


#endif