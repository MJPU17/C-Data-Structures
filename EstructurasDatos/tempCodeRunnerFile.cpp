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