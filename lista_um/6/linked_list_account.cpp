#include <iostream>
#include "linked_list_account.h"

LinkedListAccount::LinkedListAccount()
{
    head = NULL;
}

bool LinkedListAccount::contains(const Account* account) const 
{
    return indexOf(account) != -1;
}

bool LinkedListAccount::contains(const int number) const 
{
    return indexOf(number) != -1;
}

void LinkedListAccount::free()
{
   while (head != NULL) {
        Node *next = head->next;
        delete head->account;
        delete head;
        head = next;
   }
}

int LinkedListAccount::indexOf(const Account* account) const
{
    if (account != NULL) {
        return indexOf(account->number());
    } else {
        return -1;
    }
}

int LinkedListAccount::indexOf(const int number) const 
{
    int i = 0;
    Node *current = head;
    while (current != NULL) {
        if (current->account != NULL && 
            current->account->number() == number) {
            return i;
        }
        current = current->next;
        i++;
    }
    return -1;
}

void LinkedListAccount::insert(Account* account)
{
    Node* _new = new Node();
    _new->account = account;
    _new->next = head;
    head = _new;
}

bool LinkedListAccount::isEmpty() const 
{
    return head == NULL;
}

void LinkedListAccount::print() const
{
    Node *current = head;
    while (current != NULL) {
        if (current->account != NULL) {
            current->account->print();
        }
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedListAccount::printRecursively()
{ 
    __printRecursively(head);
    std::cout << std::endl;
}

void LinkedListAccount::printReverse()
{
    __printReverse(head);
    std::cout << std::endl;
}

void LinkedListAccount::remove(const Account* account)
{
    if (account != NULL) { 
        remove(account->number());
    }
}

void LinkedListAccount::remove(const int number)
{
    Node *previous = NULL; 
    Node *current = head;
    while (current != NULL) {
        
        if (current->account != NULL && 
            current->account->number() == number) {
            
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

void LinkedListAccount::removeRecursively(const Account* account)
{
    if (account != NULL) {
        removeRecursively(account->number());
    }
}

void LinkedListAccount::removeRecursively(const int  number)
{
    head = __removeRecursively(head, number);
}

Account* LinkedListAccount::search(const int number)
{
    Node *current = head;
    while (current != NULL) {
        if (current->account != NULL &&
            current->account->number() == number) {
            return current->account;
        }
        current = current->next;
    }
    return NULL;
}

void LinkedListAccount::__printRecursively(Node *node)
{
    if (node != NULL) {
        if (node->account != NULL) {
            node->account->print();
        }
        __printRecursively(node->next);
    }
}

void LinkedListAccount::__printReverse(Node *node)
{
   if (node != NULL) {
        __printReverse(node->next);
        if (node->account != NULL) {
            node->account->print();
        }
    } 
}

LinkedListAccount::Node* LinkedListAccount::__removeRecursively(Node* node, const int number) 
{
    if (node != NULL) {
        if (node->account != NULL && 
            node->account->number() == number) {
            
            Node *next = node->next;
            delete node;
            node = next;
        } else {
            node->next = __removeRecursively(node->next, number);
        }
    }
    return node;
}