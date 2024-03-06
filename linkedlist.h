#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
    ~LinkedList(); 

    void insertion(int data, int index); 
    void display();

    void merge(Node *& list1, Node * list2);
    void deleteDuplicates(Node * list1);
};
#endif