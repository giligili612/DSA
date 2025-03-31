#include "LinkedList.hpp"
#include <cstdlib>
#include <ctime>
int main(){
    srand(static_cast<unsigned int>(time(nullptr)));
    LinkedList list;
    for(int i = 0; i < 5; ++i){
        list.insertTail( rand() % 100 );
    }
    list.insertHead(12);
    list.insertHead(16);
    list.print();
    //删除的是16之后的结点
    list.eraseNode(list.find(16));
    list.print();
    //删除的是第5个结点
    list.eraseNode(list.access(4));
    list.print();
    return 0;
}