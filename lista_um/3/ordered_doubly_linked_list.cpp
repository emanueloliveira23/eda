#include <iostream>
#include "ordered_doubly_linked_list.h"

OrderedDoublyLinkedList::OrderedDoublyLinkedList()
{
    head = NULL;
}


bool OrderedDoublyLinkedList::contains(const int value) const 
{
    return indexOf(value) != -1;
}

bool OrderedDoublyLinkedList::equals(OrderedDoublyLinkedList *list) const 
{
    Node * _this = head;
    Node * _other = list->head;
    while (_this != NULL && _other != NULL && _this->value == _other->value) {
        _this = _this->next;
        _other = _other->next;
    }
    return _this == NULL && _other == NULL;
}


void OrderedDoublyLinkedList::free()
{
   while (head != NULL) {
        Node *next = head->next;
        delete head;
        head = next;
   }
}

int OrderedDoublyLinkedList::indexOf(const int value) const
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

void OrderedDoublyLinkedList::insert(const int value)
{
    
    Node *previous = NULL;
    Node *current = head;
    while (current != NULL && current->value < value) {
        previous = current;
        current = current->next;
    }

    Node* _new = new Node();
    _new->value = value;
    _new->previous = previous;
    _new->next = current;

    if (previous == NULL) {
        head = _new;
    } else {
        previous->next = _new;
        if (current != NULL) {
            current->previous = _new;
        }
    }

}

bool OrderedDoublyLinkedList::isEmpty() const 
{
    return head == NULL;
}

void OrderedDoublyLinkedList::print() const
{
    Node *current = head;
    while (current != NULL) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void OrderedDoublyLinkedList::printRecursively()
{ 
    __printRecursively(head);
    std::cout << std::endl;
}

void OrderedDoublyLinkedList::printReverse()
{
    __printReverse(head);
    std::cout << std::endl;
}

void OrderedDoublyLinkedList::remove(const int value)
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

            if (current->next != NULL) {
                current->next->previous = previous;
            }
            
            delete current;
            break;
        }

        previous = current;
        current = current->next;
    }
}

void OrderedDoublyLinkedList::removeRecursively(const int value)
{
    head = __removeRecursively(head, value);
}

void OrderedDoublyLinkedList::__printRecursively(Node *node)
{
    if (node != NULL) {
        std::cout << node->value << " ";
        __printRecursively(node->next);
    }
}

void OrderedDoublyLinkedList::__printReverse(Node *node)
{
    if (node != NULL) {
        __printReverse(node->next);
        std::cout << node->value << " ";
    }    
}

OrderedDoublyLinkedList::Node* OrderedDoublyLinkedList::__removeRecursively(Node *node, const int value) 
{
    if (node != NULL && node->value <= value) {
        if (node->value == value) {
            Node *next = node->next;
            if (next != NULL) {
                next->previous = node->previous;
            }
            delete node;
            node = next;
        } else {
            node->next = __removeRecursively(node->next, value);
        }
    }
    return node;
}