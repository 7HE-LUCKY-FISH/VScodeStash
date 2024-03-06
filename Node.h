#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int data;
    Node *next;
    Node(int value): data(value), next(nullptr){}
};


class LinkedList{
    public:
    Node *head;

    LinkedList();
    
    void append(int data);
    void prepend(int data);
    void insertAfter(int key, int data);
    void deleteNode(int key);
    bool search(int key);
    void display();

};
#endif