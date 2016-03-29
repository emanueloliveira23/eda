#ifndef LINKED_LIST_ACCOUNT
#define LINKED_LIST_ACCOUNT

#include "account.h"

class LinkedListAccount {

    struct Node {
        Account* account;
        Node *next;
    };

    Node *head;

public:
    LinkedListAccount();

    bool contains(const Account* account) const;
    bool contains(const int number) const;
    void free();
    int indexOf(const Account* account) const;
    int indexOf(const int number) const;
    void insert(Account* account);
    bool isEmpty() const;
    void print() const;
    void printRecursively();
    void printReverse();
    void remove(const Account* account);
    void remove(const int number);
    void removeRecursively(const Account* account);
    void removeRecursively(const int  number);
    Account* search(const int number);

private:
    void __printRecursively(Node *list);
    void __printReverse(Node *list);
    Node* __removeRecursively(Node *list, const int number);

};

#endif