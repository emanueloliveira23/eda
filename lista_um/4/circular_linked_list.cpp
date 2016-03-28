#include <iostream>
#include "circular_linked_list.h"

CircularLinkedList::CircularLinkedList()
{
    ref = NULL;
}

bool CircularLinkedList::contains(const int value) const 
{
    return indexOf(value) != -1;
}

void CircularLinkedList::free()
{
   // while (ref != NULL) {
   //      Node *next = ref->next;
   //      delete ref;
   //      ref = next;
   // }
}

int CircularLinkedList::indexOf(const int value) const
{
    if (!isEmpty()) {
        int i = 0;
        Node *current = ref;
        do {
            if (current->value == value) {
                return i;
            }
            i++;
            current = current->next;
        } while (current != ref);
    }
    return -1;
}

void CircularLinkedList::insert(const int value)
{
    Node* _new = new Node();
    _new->value = value;
    
    if (ref == NULL) {
        _new->next = _new;  
    } else {
        _new->next = ref->next;
        ref->next = _new;
    }
    ref = _new;
}

bool CircularLinkedList::isEmpty() const 
{
    return ref == NULL;
}

void CircularLinkedList::print() const
{
    if (!isEmpty()) {
        Node *current = ref;
        do {
            std::cout << current->value << " ";
            current = current->next;
        } while (current != ref);
    }
    std::cout << std::endl;
}

void CircularLinkedList::printRecursively()
{ 
    if (!isEmpty()) {
        std::cout << ref->value << " ";
        __printRecursively(ref->next);
    }
    std::cout << std::endl;
}

void CircularLinkedList::remove(const int value)
{
    // Node *previous = NULL; 
    // Node *current = ref;
    // while (current != NULL) {
        
    //     if (current->value == value) {
            
    //         if (previous == NULL) {
    //             ref = current->next;
    //         } else {
    //             previous->next = current->next;
    //         }
            
    //         delete current;
    //         break;
    //     }

    //     previous = current;
    //     current = current->next;
    // }

    if (!isEmpty()) {
        Node *previous = ref;
        Node *current = ref->next;
        do {
            if (current->value == value) {
                
                delete current;
                break;
            }
            previous = current;
            current = current->next;
        } while (current != ref);
    }
    
}

void CircularLinkedList::removeRecursively(const int value)
{
    // ref = __removeRecursively(ref, value);
}

void CircularLinkedList::__printRecursively(Node *node)
{
    if (node != ref) {
        std::cout << node->value << " ";
        __printRecursively(node->next);
    }
}


CircularLinkedList::Node* CircularLinkedList::__removeRecursively(Node* node, const int value) 
{
    // if (node != NULL) {
    //     if (node->value == value) {
    //         Node *next = node->next;
    //         delete node;
    //         node = next;
    //     } else {
    //         node->next = __removeRecursively(node->next, value);
    //     }
    // }
    // return node;
}