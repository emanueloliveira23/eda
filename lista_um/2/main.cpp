#include <iostream>
#include <stdio.h>
#include "ordered_linked_list.h"

void println(std::string);

int main(int argc, const char* argv[]) 
{

    //1.
    println("Criando a lista encadeada...");
    OrderedLinkedList *list = new OrderedLinkedList();
       
    //6.
    printf("list is empty?: %d\n", list->isEmpty()); 

    //2.
    println("insert 50");
    list->insert(50);
    println("insert 40");
    list->insert(40);
    println("insert 60");
    list->insert(60);
    println("insert 88");
    list->insert(88);

    //6.
    printf("list is empty?: %d\n", list->isEmpty());
    
    //3.
    println("normal print:");
    list->print();
    
    //4.
    println("recursively print:");
    list->printRecursively();

    //5.
    println("reverse print:");
    list->printReverse();

    //7.
    printf("contains(%d): %d\n", 10, list->contains(10));
    printf("index of %d: %d\n", 10, list->indexOf(10));
    printf("contains(%d): %d\n", 50, list->contains(50));
    printf("index of %d: %d\n", 50, list->indexOf(50));
    
    //8.   
    printf("normal remove(%d)\n", 10);
    list->remove(10);
    printf("contains(%d): %d\n", 10, list->contains(10));
    printf("index of %d: %d\n", 10, list->indexOf(10));

    //9.
    printf("remove recursively(%d)\n", 30);
    list->removeRecursively(30);
    printf("contains(%d): %d\n", 30, list->contains(30));
    printf("index of %d: %d\n", 30, list->indexOf(30));    

    println("normal print:");
    list->print();

    //10.
    println("releasing list");
    list->free();

    printf("list is empty?: %d\n", list->isEmpty());
    std::cout << "normal print:" << std::endl;
    list->print();

    //11.
    OrderedLinkedList *aList = new OrderedLinkedList();
    aList->insert(10);
    aList->insert(23);
    aList->insert(409);
    aList->insert(11);
    aList->insert(1490);

    println("normal print a list:");
    aList->print();

    OrderedLinkedList *anotherList = new OrderedLinkedList();
    anotherList->insert(10);
    anotherList->insert(23);
    anotherList->insert(409);
    anotherList->insert(11);
    
    println("normal print another list:");
    anotherList->print();

    std::cout << "a list is equals to another list? r: " << aList->equals(anotherList) << std::endl;

    println("inserting 1490 on another list");
    anotherList->insert(1490);

    std::cout << "a list is equals to another list? r: " << aList->equals(anotherList) << std::endl;

    delete list;
    delete aList;
    delete anotherList;

    return 0;
}

void println(std::string data)
{
    std::cout << data << std::endl;
}
