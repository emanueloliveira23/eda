#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

class CircularDoublyLinkedList {

    struct Node {
        int value;
        Node *next;
        Node *previous;
    };

    Node *ref;

public:
    CircularDoublyLinkedList();

    bool contains(const int value) const;
    void free();
    int indexOf(const int value) const;
    void insert(const int value);
    bool isEmpty() const;
    void print() const;
    void printRecursively();
    void remove(const int value);
    void removeRecursively(const int value);

private:
    void __printRecursively(Node *list);
    Node* __removeRecursively(Node *list, const int value);

};

#endif