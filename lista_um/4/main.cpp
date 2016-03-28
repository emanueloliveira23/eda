#include <iostream>
#include <stdio.h>
#include "circular_linked_list.h"

void println(std::string);

int main(int argc, const char* argv[]) 
{

    //1.
    println("Criando a lista encadeada...");
    CircularLinkedList *list = new CircularLinkedList();
       
    //5.
    printf("list is empty?: %d\n", list->isEmpty()); 

    //2.
    println("insert 10");
    list->insert(10);
    println("insert 20");
    list->insert(20);
    println("insert 30");
    list->insert(30);
    println("insert 40");
    list->insert(40);

    //5.
    printf("list is empty?: %d\n", list->isEmpty());
    
    //3.
    println("normal print:");
    list->print();
    
    //4.
    println("recursively print:");
    list->printRecursively();

    
    //6.
    printf("contains(%d): %d\n", 10, list->contains(10));
    printf("index of %d: %d\n", 10, list->indexOf(10));
    printf("contains(%d): %d\n", 50, list->contains(50));
    printf("index of %d: %d\n", 50, list->indexOf(50));
    
    //7.   
    /*printf("normal remove(%d)\n", 10);
    list->remove(10);
    printf("contains(%d): %d\n", 10, list->contains(10));
    printf("index of %d: %d\n", 10, list->indexOf(10));

    //8.
    printf("remove recursively(%d)\n", 30);
    list->removeRecursively(30);
    printf("contains(%d): %d\n", 30, list->contains(30));
    printf("index of %d: %d\n", 30, list->indexOf(30));    

    println("normal print:");
    list->print();

    //9.
    println("releasing list");
    list->free();

    printf("list is empty?: %d\n", list->isEmpty());
    std::cout << "normal print:" << std::endl;
    list->print();*/

    delete list;

    
    return 0;
}

void println(std::string data)
{
    std::cout << data << std::endl;
}
