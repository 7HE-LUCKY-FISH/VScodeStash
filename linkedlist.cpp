#include "linkedlist.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(nullptr) {} // Constructor

LinkedList::~LinkedList() { // Destructor
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insertion(int data, int index) {
    if (index < 1) {
        cout << "Invalid index" << endl;
        return;
    }
    Node* newNode = new Node(data);
    if (index == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "The previous node is null." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void LinkedList::display() {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::merge(Node*& list1, Node* list2) {
    if (list1 == nullptr) {
        list1 = list2;
    } else {
        Node* temp = list1;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = list2;
    }
}

void LinkedList::deleteDuplicates(Node* list) {
    Node* current = list;
    while (current != nullptr && current->next != nullptr) {
        Node* temp = current;
        while (temp->next != nullptr) {
            if (current->data == temp->next->data) {
                Node* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

