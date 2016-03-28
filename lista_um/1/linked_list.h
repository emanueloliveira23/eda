#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {

    struct Node {
        int value;
        Node *next;
    };

    Node *head;

public:
    LinkedList();

    bool contains(const int value) const;
    void free();
    int indexOf(const int value) const;
    void insert(const int value);
    bool isEmpty() const;
    void print() const;
    void printRecursively();
    void printReverse();
    void remove(const int value);
    void removeRecursively(const int value);

private:
    void __printRecursively(Node *list);
    void __printReverse(Node *list);
    Node* __removeRecursively(Node *list, const int value);

};

#endif