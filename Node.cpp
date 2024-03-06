#include "Node.h"
using namespace std;
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::append(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void LinkedList::prepend(int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAfter(int key, int data) {
    Node *current = head;
    while (current != nullptr && current->data != key) {
        current = current->next;
    }
    if(current == nullptr){
        cerr<<"Key not found in the list."<<endl;
        return;
    }
    if (current != nullptr) {
        Node *newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;
    }
}
void LinkedList::deleteNode(int key) {
    if (head == nullptr){
        cerr<<"List is empty"<<endl;
        return;
    }
    if (head->data == key) {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node *current = head;
    while (current->next != nullptr && current->next->data != key) {
        current = current->next;
    }
    if (current->next == nullptr) return;
    Node *toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;
}
bool LinkedList::search(int key) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data == key){
            return true;
        }
        current = current->next;
    }
    return false;
}
void LinkedList::display() {
    Node *current = head;
    while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
    cout << endl;
}

