#include "MyDoubleLinkedList.cpp"
#include "DNode.cpp"
#include "DequeList.cpp"
#include "MyLinkedList.cpp"
#include "QueueImp.cpp"
#include "StackImp.cpp"
#include "MyMap.cpp"
#include "MyGraph.cpp"
#include "Vertex.cpp"
#include "BreadthFirstSearch.cpp"
#include "DeepFirstSearch.cpp"
#include "BellmanFord.cpp"
#include "Dijkstra.cpp"
#include "BinaryTree.cpp"
#include "GenericTree.cpp"
#include <iostream>
#include <string>
#include <utility>
#include <cstdio>

using namespace std;

void linkedList(){
    MyLinkedList<int> list;
    for(int i=100;i<=120;i++){
        list.addLast(i);
    }
    for(int aux: list){
        printf("%d ",aux);
    }
    list.remove(0);
    printf("\n");
    for(int aux: list){
        printf("%d ",aux);
    }
    list.remove(list.getSize()-1);
    printf("\n");
    for(int aux: list){
        printf("%d ",aux);
    }
    list.remove(5);
    list.remove(0);
    list.remove(2);
    printf("\n");
    for(int aux: list){
        printf("%d ",aux);
    }
    while(!list.isEmpty()){
        list.remove(0);
    }
    for(int i=200;i<=222;i++){
        list.addLast(i);
    }
    printf("\n");
    for(int aux: list){
        printf("%d ",aux);
    }
    list.clear();
    printf("\nSize: %d\n",list.getSize());
    for(int aux: list){
        printf("%d ",aux);
    }
    for(int i=223;i<=244;i++){
        list.addLast(i);
    }
    list.set(2,1234);
    list.set(0,1345);
    list.set(list.getSize()-1,2367);
    printf("\nSize: %d\n",list.getSize());
    for(int aux: list){
        printf("%d ",aux);
    }
}

void doubleLinkedList(){
    MyDoubleLinkedList<int> dlist;
    for(int i=0;i<5;i++){
        dlist.add(i);
    }
    for(int i=0;i<dlist.getSize();i++){
        printf("%d ",dlist.get(i));
    }
    printf("\n");
    dlist.remove(3);
    for(int i=0;i<dlist.getSize();i++){
        printf("%d ",dlist.get(i));
    }
    printf("\n");
    dlist.remove(3);
    for(int i=0;i<dlist.getSize();i++){
        printf("%d ",dlist.get(i));
    }
    printf("\n");
    dlist.add(1,100);
    for(int i=0;i<dlist.getSize();i++){
        printf("%d ",dlist.get(i));
    }
    printf("\n");
    dlist.addInit(345);
    for(int i=0;i<dlist.getSize();i++){
        printf("%d ",dlist.get(i));
    }
    dlist.remove(0);
    printf("\n");
    for(int aux: dlist){
        printf("%d ",aux);
    }
    dlist.remove(dlist.getSize()-1);
    printf("\n");
    for(int aux: dlist){
        printf("%d ",aux);
    }
    while(!dlist.isEmpty()){
        dlist.remove(0);
    }
    for(int i=90;i<=120;i++){
        dlist.add(i);
    }
    printf("\n");
    for(int aux: dlist){
        printf("%d ",aux);
    }
    dlist.clear();
    printf("\nSize: %d\n",dlist.getSize());
    for(int aux: dlist){
        printf("%d ",aux);
    }
    for(int i=121;i<=140;i++){
        dlist.add(i);
    }
    dlist.set(2,1234);
    dlist.set(0,1345);
    dlist.set(dlist.getSize()-1,2367);
    printf("\nSize: %d\n",dlist.getSize());
    for(int aux: dlist){
        printf("%d ",aux);
    }
}

void dequeList(){
    DequeList<int> dqlist;
    for(int i=1;i<=10;i++){
        (i%2==0?dqlist.insertFirst(i):dqlist.insertLast(i));
    }
    for(int i=0;i<dqlist.getSize();i++){
        printf("%d ",dqlist.get(i));
    }
    printf("\n");
    dqlist.removeFirst();
    dqlist.removeLast();
    for(int i=0;i<dqlist.getSize();i++){
        printf("%d ",dqlist.get(i));
    }
    printf("\n");
    dqlist.removeFirst();
    dqlist.removeLast();
    for(int i=0;i<dqlist.getSize();i++){
        printf("%d ",dqlist.get(i));
    }
    printf("\n%d\n",dqlist.getTail()->getInfo());
    while(!dqlist.isEmpty()){
        printf("%d ",dqlist.removeLast());
    }
    printf("\n");
    printf((dqlist.getTail()==nullptr?"true\n":"false\n"));
    printf((dqlist.getHead()==nullptr?"true\n":"false\n"));
    for(int i=30;i<=46;i++){
        (i%2==0?dqlist.insertLast(i):dqlist.insertFirst(i));
    }
    for(int aux:dqlist){
        printf("%d ",aux);
    }
    dqlist.clear();
    printf("\nSize: %d\n",dqlist.getSize());
    for(int aux : dqlist){
        printf("%d ",aux);
    }
    for(int i=47;i<=76;i++){
        (i%2==0?dqlist.insertFirst(i):dqlist.insertLast(i));
    }
    printf("\nSize: %d\n",dqlist.getSize());
    for(int aux : dqlist){
        printf("%d ",aux);
    }
}

void queue(){
    QueueImp<char> queue;
    for(char i='A';i<='Z';i++){
        queue.enqueue(i);
    }
    for(char aux: queue){
        printf("%c ", aux);
    }
    queue.dequeue();
    printf("\n");
    for(char aux: queue){
        printf("%c ", aux);
    }
    printf("\n%c\n",queue.peek());
    while(!queue.isEmpty()){
        printf("%c ", queue.dequeue());
    }
    for(char i='a';i<='z';i++){
        queue.enqueue(i);
    }
    printf("\n");
    for(char aux: queue){
        printf("%c ", aux);
    }
    queue.clear();
    printf("\nSize: %d\n",queue.size());
    for(char aux: queue){
        printf("%c ", aux);
    }
    for(char i='z';i>='a';i--){
        queue.enqueue(i);
    }
    printf("\nSize: %d\n",queue.size());
    while(!queue.isEmpty()){
        printf("%c ", queue.dequeue());
    }
}

void stack(){
    StackImp<char> stack;
    for(char i='A';i<='Z';i++){
        stack.push(i);
    }
    for(char aux: stack){
        printf("%c ", aux);
    }
    stack.pop();
    printf("\n");
    for(char aux: stack){
        printf("%c ", aux);
    }
    printf("\n%c\n",stack.peek());
    while(!stack.isEmpty()){
        printf("%c ", stack.pop());
    }
    for(char i='a';i<='z';i++){
        stack.push(i);
    }
    printf("\n");
    for(char aux : stack){
        printf("%c ",aux);
    }
    stack.clear();
    printf("\nSize %d:\n ",stack.size());
    for(char aux : stack){
        printf("%c ",aux);
    }
    for(char i='z';i>='a';i--){
        stack.push(i);
    }
    printf("\nSize %d:\n",stack.size());
    for(char aux : stack){
        printf("%c ",aux);
    }
    printf("\n");
    while(!stack.isEmpty()){
        printf("%c ", stack.pop());
    }
}

void map(){
    MyMap<char,int> map;
    for(char i='A';i<='M';i++){
        map.put(i,(int)i);
    }
    for(pair<char,int> aux: map){
        printf("%c: %d\n",aux.first,aux.second);
    }
    printf("\n");
    for(char i='A';i<='M';i++){
        printf("%c: %d\n",i,map.getValue(i));
    }
    printf("\n");
    for(char i='A';i<='Z';i++){
         printf((map.containsKey(i)?"%c: true\n":"%c: false\n"),i);
    }
    for(char i='A';i<='Z';i++){
        if(i<='M')map.remove(i);
        else map.put(i,(int)i);
    }
    printf("\n");
    for(pair<char,int> aux: map){
        printf("%c: %d\n",aux.first,aux.second);
    }
    int j=1;
    for(char i='N';i<='Z';i++){
        map.replace(i,j++);
    }
    printf("\n");
    for(pair<char,int> aux: map){
        printf("%c: %d\n",aux.first,aux.second);
    }
    for(char i='N';i<='Z';i++){
        map.put(i,--j);
    }
    printf("\n");
    for(pair<char,int> aux: map){
        printf("%c: %d\n",aux.first,aux.second);
    }
    for(char i='N';i<='Z';i++){
        map.remove(i);
    }
    for(char i='a';i<='z';i++){
        map.put(i,(int)i);
    }
    printf("\n");
    for(pair<char,int> aux: map){
        printf("%c: %d\n",aux.first,aux.second);
    }
    map.clear();
    printf("\nSize: %d\n",map.getSize());
    for(pair<char,int> aux: map){
        printf("%c: %d\n",aux.first,aux.second);
    }
    map.put('V',22);
    printf("\nSize: %d\n",map.getSize());
    for(pair<char,int> aux: map){
        printf("%c: %d\n",aux.first,aux.second);
    }
}

void graph(){
    MyGraph<string> graph;
    graph.addNode("Bogota");
    graph.addNode("Cali");
    graph.addNode("Cartagena");
    graph.addEdge("Cali","Bogota",19);
    graph.addEdge("Bogota","Cartagena",32);
    graph.addEdge("Cartagena","Cali",8);
    graph.addEdge("Cali","Cartagena",3);
    graph.addEdge("Cartagena","Bogota",5);
    for(int i=0;i<graph.getNumNodes();i++){
        cout<<graph.numberToNode(i)<<":\n";
        for(int j=0;j<graph.getAdj().get(i).getSize();j++){
            Vertex n=graph.getAdj().get(i).get(j);
            cout<<"["<<graph.numberToNode(n.getNumber())<<", "<<n.getWeigth()<<"] ";
        }
        cout<<"\n\n";
    }
}

void bfs(){
    MyGraph<char> graph;
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addNode('D');
    graph.addNode('F');
    graph.addEdge('A','B',1);
    graph.addEdge('A','C',1);
    graph.addEdge('B','D',1);
    graph.addEdge('B','F',1);
    graph.addEdge('D','C',1);
    graph.addEdge('D','F',1);
    graph.addEdge('F','A',1);

    char source='B';
    
    BreadthFirstSearch<char> bfs(graph,source);
    bfs.runSearch();
    for(int i=0;i<graph.getNumNodes();i++){
        char destination=graph.numberToNode(i);
        if(bfs.obtainDistance(destination)!=-1){
            printf("El camino mas corto del nodo %c al %c es:\n",source,destination);
            string way="";
            int current=i;
            while(current!=-1){
                way=graph.numberToNode(current)+way;
                current=bfs.getPrevious().get(current);
            }
            printf("Camino: ");
            for(int j=0;j<way.length();j++){
                char aux=way[j];
                printf("%c ",aux);
            }
            printf("\nDistancia: %d\n\n",bfs.obtainDistance(destination));
        }
        else {
            printf("No hay camino del nodo %c al %c.\n\n",source,destination);
        }
    }
}

void dfs(){
    MyGraph<char> graph;
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addNode('D');
    graph.addNode('F');
    graph.addNode('G');
    graph.addNode('H');
    graph.addNode('I');
    graph.addNode('J');
    graph.addNode('M');
    graph.addEdge('A','B',1);
    graph.addEdge('A','D',1);
    graph.addEdge('A','C',1);
    graph.addEdge('B','G',1);
    graph.addEdge('B','F',1);
    graph.addEdge('D','J',1);
    graph.addEdge('D','M',1);
    graph.addEdge('F','H',1);
    graph.addEdge('F','I',1);

    char source='A';
    
    DeepFirstSearch<char> dfs(graph,source);
    dfs.runSearch();

    for(int i=0;i<graph.getNumNodes();i++){
        char node=graph.numberToNode(i);
        if(dfs.obtainDiscover(node)!=0){
            printf("Tiempo descubrimiento nodo %c: %d\n",node,dfs.obtainDiscover(node));
            printf("Tiempo terminacion nodo %c: %d\n\n",node,dfs.obtainTermination(node));
        }
        else{
            printf("No se puede llegar desde el origen %c a %c.\n\n",source,node);
        }
    }

}

void bellmanFord(){
    MyGraph<char> graph;
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addNode('D');
    graph.addNode('E');
    graph.addNode('F');
    graph.addEdge('A','B',3);
    graph.addEdge('A','F',40);
    graph.addEdge('B','E',3);
    graph.addEdge('B','D',15);
    graph.addEdge('D','E',20);
    graph.addEdge('F','C',-3);

    char source='B';

    BellmanFord<char> bf(graph,source);
    bf.initBellmanFord();
    if(bf.isNegativeCicle()){
        printf("Hay ciclo.");
    }
    else {
        for(int i=0;i<graph.getNumNodes();i++){
            char destination=graph.numberToNode(i);
            if(bf.isPath(destination)){
                int current=i;
                string way="";
                while(current!=-1){
                    way=graph.numberToNode(current)+way;
                    current=bf.getPrevious().get(current);
                }
                printf("El camino mas corto del nodo %c al %c es:\n",source,destination);
                for(int j=0;j<way.length();j++){
                    char aux=way[j];
                    printf("%c ",aux);
                }
                printf("\nDistancia: %lf\n\n",bf.obtainDistance(destination));
            }
            else {
                printf("No hay camino del nodo %c al %c.\n\n",source,destination);
            }
        }
    }

}

void bellmanFord2(){
    MyGraph<char> graph;
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addEdge('A','B',-1);
    graph.addEdge('B','C',1);
    graph.addEdge('C','A',-1);

    char source='A';

    BellmanFord<char> bf(graph,source);
    bf.initBellmanFord();
    if(bf.isNegativeCicle()){
        printf("Hay ciclo.");
    }
    else {
        for(int i=0;i<graph.getNumNodes();i++){
            char destination=graph.numberToNode(i);
            if(bf.isPath(destination)){
                int current=i;
                string way="";
                while(current!=-1){
                    way=graph.numberToNode(current)+way;
                    current=bf.getPrevious().get(current);
                }
                printf("El camino mas corto del nodo %c al %c es:\n",source,destination);
                for(int j=0;j<way.length();j++){
                    char aux=way[j];
                    printf("%c ",aux);
                }
                printf("\nDistancia: %lf\n\n",bf.obtainDistance(destination));
            }
            else {
                printf("No hay camino del nodo %c al %c.\n\n",source,destination);
            }
        }
    }
}

void dijkstra(){
    MyGraph<char> graph;
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addNode('D');
    graph.addNode('E');
    graph.addNode('F');
    graph.addNode('G');
    graph.addNode('H');
    graph.addNode('I');
    graph.addNode('J');
    graph.addNode('K');
    graph.addNode('L');
    graph.addNode('M');
    graph.addNode('N');
    graph.addNode('P');
    graph.addEdge('A','B',8);
    graph.addEdge('A','D',5);
    graph.addEdge('A','E',4);
    graph.addEdge('B','C',3);
    graph.addEdge('B','F',4);
    graph.addEdge('B','E',12);
    graph.addEdge('D','E',9);
    graph.addEdge('D','H',6);
    graph.addEdge('F','G',1);
    graph.addEdge('F','K',8);
    graph.addEdge('F','E',3);
    graph.addEdge('E','J',5);
    graph.addEdge('E','I',8);
    graph.addEdge('H','I',2);
    graph.addEdge('H','M',7);
    graph.addEdge('G','L',7);
    graph.addEdge('G','K',8);
    graph.addEdge('K','L',5);
    graph.addEdge('K','P',7);
    graph.addEdge('K','J',6);
    graph.addEdge('J','N',9);
    graph.addEdge('J','I',10);
    graph.addEdge('I','M',6);
    graph.addEdge('L','P',6);
    graph.addEdge('P','N',17);
    graph.addEdge('N','M',2);

    char source='A';

    Dijkstra<char> dj(graph,'A');
    dj.runDijkstra();

    for(int i=0;i<graph.getNumNodes();i++){
         char destination=graph.numberToNode(i);
        if(dj.isPath(destination)){
            int current=i;
            string way="";
            while(current!=-1){
                way=graph.numberToNode(current)+way;
                current=dj.getPrevious().get(current);
            }
            printf("El camino mas corto del nodo %c al %c es:\n",source,destination);
            for(int j=0;j<way.length();j++){
                char aux=way[j];
                printf("%c ",aux);
            }
            printf("\nDistancia: %lf\n\n",dj.obtainDistance(destination));
        }
        else {
            printf("No hay camino del nodo %c al %c.\n\n",source,destination);
        }
    }
}

void binaryTree(){
    BinaryTree<char> bt;
    bt.insert('C');
    bt.insert('F');
    bt.insert('B');
    bt.insert('D');
    bt.insert('A');

    printf("Caracteres:");
    printf("\nInorder: ");
    for(char aux : bt.inOrder()){
        printf("%c ",aux);
    }
    printf("\nPostorder: ");
    for(char aux : bt.postOrder()){
        printf("%c ",aux);
    }
    printf("\nPreorder: ");
    for(char aux : bt.preOrder()){
        printf("%c ",aux);
    }
    bt.clear();
    
    BinaryTree<int> bt2;
    bt2.insert(5);
    bt2.insert(4);
    bt2.insert(7);
    bt2.insert(2);
    bt2.insert(11);

    printf("\n\nNumeros:");
    printf("\nInorder: ");
    for(int aux : bt2.inOrder()){
        printf("%d ",aux);
    }
    printf("\nPostorder: ");
    for(int aux : bt2.postOrder()){
        printf("%d ",aux);
    }
    printf("\nPreorder: ");
    for(int aux : bt2.preOrder()){
        printf("%d ",aux);
    }
    bt2.clear();

    BinaryTree<string> bt3;
    bt3.insert("AC");
    bt3.insert("AD");
    bt3.insert("AF");
    bt3.insert("AA");
    bt3.insert("AE");

     printf("\n\nString:");
    printf("\nInorder: ");
    for(string aux : bt3.inOrder()){
        for(char c:aux)printf("%c",c);
        printf(" ");
    }
    printf("\nPostorder: ");
    for(string aux : bt3.postOrder()){
        for(char c:aux)printf("%c",c);
        printf(" ");
    }
    printf("\nPreorder: ");
    for(string aux : bt3.preOrder()){
        for(char c:aux)printf("%c",c);
        printf(" ");
    }
    bt3.clear();
}

void genericTree(){
    GenericTree<string> gt;
    gt.addNode("A");
    gt.addNode("A","B");
    gt.addNode("A","C");
    gt.addNode("A","D");
    gt.addNode("B","E");
    gt.addNode("B","F");
    gt.addNode("D","G");
    gt.addNode("D","H");
    gt.addNode("D","I");
    gt.levelOrder(gt.getRoot());
    printf("Level Order:\n");
    for(pair<int,MyLinkedList<string>> aux:gt.getLevels()){
        printf("Level %d:\n",aux.first);
        for(string leave:aux.second){
            for(char c:leave)printf("%c",c);
            printf(" ");
        }
        printf("\n\n");
    }
    printf("PreOrder:\n");
    for(string aux: gt.preOrder(gt.getRoot())){
        for(char c:aux)printf("%c",c);
        printf(" ");
    }
    printf("\n\nPostOrder:\n");
    for(string aux: gt.postOrder(gt.getRoot())){
        for(char c:aux)printf("%c",c);
        printf(" ");
    }

    gt.clear();
    gt.addNode("a");
    gt.addNode("a","b");
    gt.addNode("a","c");
    gt.addNode("a","d");
    gt.addNode("b","e");
    gt.addNode("b","f");
    gt.addNode("d","g");
    gt.addNode("d","h");
    gt.addNode("d","i");
    gt.levelOrder(gt.getRoot());
    printf("\n\nLevel Order:\n");
    for(pair<int,MyLinkedList<string>> aux:gt.getLevels()){
        printf("Level %d:\n",aux.first);
        for(string leave:aux.second){
            for(char c:leave)printf("%c",c);
            printf(" ");
        }
        printf("\n\n");
    }
    printf("PreOrder:\n");
    for(string aux: gt.preOrder(gt.getRoot())){
        for(char c:aux)printf("%c",c);
        printf(" ");
    }
    printf("\n\nPostOrder:\n");
    for(string aux: gt.postOrder(gt.getRoot())){
        for(char c:aux)printf("%c",c);
        printf(" ");
    }
}

int main(int argc, char const *argv[]){
    genericTree();
    return 0;
}
