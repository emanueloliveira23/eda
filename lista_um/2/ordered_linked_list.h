#ifndef ORDERED_LINKED_LIST_H
#define ORDERED_LINKED_LIST_H

class OrderedLinkedList {

    struct Node {
        int value;
        Node *next;
    };

    Node *head;
    
public:
    OrderedLinkedList();

    bool contains(const int value) const;
    bool equals(OrderedLinkedList *list) const;
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