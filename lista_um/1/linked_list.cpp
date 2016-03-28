#include <iostream>
#include "linked_list.h"

LinkedList::LinkedList()
{
    head = NULL;
}

bool LinkedList::contains(const int value) const 
{
    return indexOf(value) != -1;
}

void LinkedList::free()
{
   while (head != NULL) {
        Node *next = head->next;
        delete head;
        head = next;
   }
}

int LinkedList::indexOf(const int value) const
{
    int i = 0;
    Node *current = head;
    while (current != NULL) {
        if (current->value == value) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1;
}

void LinkedList::insert(const int value)
{
    Node* _new = new Node();
    _new->value = value;
    _new->next = head;
    head = _new;
}

bool LinkedList::isEmpty() const 
{
    return head == NULL;
}

void LinkedList::print() const
{
    Node *current = head;
    while (current != NULL) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::printRecursively()
{ 
    __printRecursively(head);
    std::cout << std::endl;
}

void LinkedList::printReverse()
{
    __printReverse(head);
    std::cout << std::endl;
}

void LinkedList::remove(const int value)
{
    Node *previous = NULL; 
    Node *current = head;
    while (current != NULL) {
        
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

void LinkedList::removeRecursively(const int value)
{
    head = __removeRecursively(head, value);
}

void LinkedList::__printRecursively(Node *node)
{
    if (node != NULL) {
        std::cout << node->value << " ";
        __printRecursively(node->next);
    }
}

void LinkedList::__printReverse(Node *node)
{
    if (node != NULL) {
        __printReverse(node->next);
        std::cout << node->value << " ";
    }    
}

LinkedList::Node* LinkedList::__removeRecursively(Node* node, const int value) 
{
    if (node != NULL) {
        if (node->value == value) {
            Node *next = node->next;
            delete node;
            node = next;
        } else {
            node->next = __removeRecursively(node->next, value);
        }
    }
    return node;
}