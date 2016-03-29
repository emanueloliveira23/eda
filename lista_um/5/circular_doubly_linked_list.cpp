#include <iostream>
#include "circular_doubly_linked_list.h"

CircularDoublyLinkedList::CircularDoublyLinkedList()
{
    ref = NULL;
}

bool CircularDoublyLinkedList::contains(const int value) const 
{
    return indexOf(value) != -1;
}

void CircularDoublyLinkedList::free()
{
    if (!isEmpty()) {
        while (ref->next != ref) {
            Node *nodeRemove = ref->next;
            ref->next = nodeRemove->next;
            delete nodeRemove;
        }
        delete ref;
        ref = NULL;
    }
}

int CircularDoublyLinkedList::indexOf(const int value) const
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

void CircularDoublyLinkedList::insert(const int value)
{
    Node* _new = new Node();
    _new->value = value;
    
    if (ref == NULL) {
        _new->next = _new;
        _new->previous = _new;
    } else {
        _new->next = ref->next;
        _new->previous = ref;
        ref->next = _new;

        Node *_previous = ref->previous;
        while (_previous->previous != ref) {
            _previous = _previous->previous;
        }
        _previous->previous = _new;

    }
    ref = _new;
}

bool CircularDoublyLinkedList::isEmpty() const 
{
    return ref == NULL;
}

void CircularDoublyLinkedList::print() const
{
    if (!isEmpty()) {
        Node *current = ref->next;
        do {
            std::cout << current->value << " ";
            current = current->next;
        } while (current != ref->next);
    }
    std::cout << std::endl;
}

void CircularDoublyLinkedList::printRecursively()
{ 
    if (!isEmpty()) {
        __printRecursively(ref->next);
    }
    std::cout << std::endl;
}

void CircularDoublyLinkedList::remove(const int value)
{
    if (!isEmpty()) {
        Node *current = ref;
        do {
            if (current->next->value == value) {
                Node *nodeRemove = current->next;
                current->next = nodeRemove->next;
                current->next->previous = current;
                if (nodeRemove == ref) {
                    if (nodeRemove == current) {
                        ref = NULL;
                    } else {
                        ref = current;
                    }
                }
                delete nodeRemove;
                break;
            }
            current = current->next;
        } while (current != ref);
    }
    
}

void CircularDoublyLinkedList::removeRecursively(const int value)
{
    if (!isEmpty()) {
        __removeRecursively(ref->next, value);
    }
}

void CircularDoublyLinkedList::__printRecursively(Node *node)
{
    std::cout << node->value << " ";
    if (node != ref) {
        __printRecursively(node->next);
    }
}


CircularDoublyLinkedList::Node* CircularDoublyLinkedList::__removeRecursively(Node* node, const int value) 
{
    if (node == ref) {
        
        if (ref->value == value) {
            delete ref;
            ref = NULL;
        }

    } else {
        
        if (node->next->value == value) {
            Node *nodeRemove = node->next;
            node->next = nodeRemove->next;
            node->next->previous = node;
            if (nodeRemove == ref) {
                ref = node;
            }
            delete nodeRemove;
        } else {
            __removeRecursively(node->next, value);
        }

    }
}