#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

class CircularLinkedList {

    struct Node {
        int value;
        Node *next;
    };

    Node *ref;

public:
    CircularLinkedList();

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