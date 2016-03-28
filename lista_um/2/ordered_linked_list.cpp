#include <iostream>
#include "ordered_linked_list.h"

OrderedLinkedList::OrderedLinkedList()
{
    head = NULL;
}


bool OrderedLinkedList::contains(const int value) const 
{
    return indexOf(value) != -1;
}

bool OrderedLinkedList::equals(OrderedLinkedList *list) const 
{
    Node * _this = head;
    Node * _other = list->head;
    while (_this != NULL && _other != NULL && _this->value == _other->value) {
        _this = _this->next;
        _other = _other->next;
    }
    return _this == NULL && _other == NULL;
}


void OrderedLinkedList::free()
{
   while (head != NULL) {
        Node *next = head->next;
        delete head;
        head = next;
   }
}

int OrderedLinkedList::indexOf(const int value) const
{
    int i = 0;
    Node *current = head;
    while (current != NULL && current->value <= value) {
        if (current->value == value) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1;
}

void OrderedLinkedList::insert(const int value)
{
    
    Node *previous = NULL;
    Node *current = head;
    while (current != NULL && current->value < value) {
        previous = current;
        current = current->next;
    }

    Node* _new = new Node();
    _new->value = value;
    
    if (previous == NULL) {
        _new->next = head;
        head = _new;
    } else {
        _new->next = previous->next;
        previous->next = _new;
    }
}

bool OrderedLinkedList::isEmpty() const 
{
    return head == NULL;
}

void OrderedLinkedList::print() const
{
    Node *current = head;
    while (current != NULL) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void OrderedLinkedList::printRecursively()
{ 
    __printRecursively(head);
    std::cout << std::endl;
}

void OrderedLinkedList::printReverse()
{
    __printReverse(head);
    std::cout << std::endl;
}

void OrderedLinkedList::remove(const int value)
{
    Node *previous = NULL; 
    Node *current = head;
    while (current != NULL && current->value <= value) {
        if (current->value == value) {
            
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            
            delete current;
            break;
        }

        previous = current;
        current = current->next;
    }
}

void OrderedLinkedList::removeRecursively(const int value)
{
    head = __removeRecursively(head, value);
}

void OrderedLinkedList::__printRecursively(Node *list)
{
    if (list != NULL) {
        std::cout << list->value << " ";
        __printRecursively(list->next);
    }
}

void OrderedLinkedList::__printReverse(Node *list)
{
    if (list != NULL) {
        __printReverse(list->next);
        std::cout << list->value << " ";
    }    
}

OrderedLinkedList::Node* OrderedLinkedList::__removeRecursively(Node *list, const int value) 
{
    if (list != NULL && list->value <= value) {
        if (list->value == value) {
            Node *next = list->next;
            delete list;
            list = next;
        } else {
            list->next = __removeRecursively(list->next, value);
        }
    }
    return list;
}