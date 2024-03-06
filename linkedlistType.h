#include <iostream>
using namespace std;
template <class T>
class Node {
public:
    T data;
    Node* next;
    Node* first;
    Node* last;


    Node(const T& value) : data(value), next(nullptr), first(nullptr), last(nullptr) {}
};

template <class T>
class LinkedList {
protected:
    Node<T>* head;
    Node<T>* tail;
public:

    LinkedList() : head(nullptr) {}

    LinkedList(const LinkedList& other) {
        if (other.head == nullptr) {
            head = nullptr;
            return;
        }
        head = new Node<T>(other.head->data);
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head->next;

        while (otherCurrent != nullptr) {
            current->next = new Node<T>(otherCurrent->data);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* nextNode;

        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void display() const {
        Node<T>* current = head;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
    
    virtual void insert(const T& data) =0;
    /*
    {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    */
    int length() const {
        int count = 0;
        Node<T>* current = head;

        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    bool isEmpty() const{
        return head == nullptr;
    }
    void deleteSmallest(){
        if(head == nullptr){
            return; 
        }
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        Node<T>* minNode = head;
        Node<T>* minPrev = nullptr;

        // Find the node with the smallest info
        while (current != nullptr) {
            if (current->data < minNode->data) {
                minNode = current;
                minPrev = prev;
            }

            prev = current;
            current = current->next;
        }

        // Delete the node with the smallest info (if found)
        if (minPrev == nullptr) {
            // The smallest node is the first node
            head = minNode->next;
        } else {
            minPrev->next = minNode->next;
        }

        delete minNode;
    }
    virtual void deleteNodeWithSmallestInfo() = 0;
    virtual void deleteAllOccurrences(const T &info) = 0;
    T getkelement(int k){
        Node<T>*temp = head;
        int count = 1;
        while(temp!=nullptr && count<k){
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        cerr << "No such element exists." << endl;
        exit(EXIT_FAILURE);
    }
    return temp->data;
    }

    void deleteAt(int k){
        if (k<0||head == nullptr){
            cerr <<"Out of range"<<endl;
            exit(EXIT_FAILURE);
        }
        if (k == 0) {
        Node<T>* toDelete = head;
        head = head->next;
        delete toDelete;
        if (head == nullptr) tail = nullptr;
        return;
        }
        

        Node<T>* temp = head;
        for (int i = 0; temp != nullptr && i < k - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cerr << "Position is out of range, terminating program.\n";
            exit(EXIT_FAILURE);
        }

        Node<T>* toDelete = temp->next;
        temp->next = temp->next->next;
        if (toDelete == tail) {
            tail = temp;
        }
        delete toDelete;
    }


};

template <class Type>
class unorderedLinkedList : public LinkedList<Type>
{
public:
    void deleteNodeWithSmallestInfo() override
    {
        if (this->head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node<Type> *current = this->head;
        Node<Type> *prev = nullptr;
        Node<Type> *minNode = this->head;
        Node<Type> *minPrev = nullptr;

        while (current != nullptr)
        {
            if (current->data < minNode->data)
            {
                minNode = current;
                minPrev = prev;
            }

            prev = current;
            current = current->next;
        }
        // Remove the node with the smallest info
        if (minPrev == nullptr)
        {
            this->head = minNode->next;
        }
        else
        {
            minPrev->next = minNode->next;
        }

        delete minNode;
    }

    void deleteAllOccurrences(const Type &info) override
    {
        Node<Type> *current = this->head;
        Node<Type> *prev = nullptr;

        while (current != nullptr)
        {
            if (current->data == info)
            {
                // Node with matching info found, remove it
                if (prev == nullptr)
                {
                    this->head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                Node<Type> *temp = current;
                current = current->next;
                delete temp;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
    /*
    void insert(const Type& data) override{
        Node<Type> *newNode = new Node<Type>(data);
        newNode->next = this->head;
        this->head= newNode;
    }
    */
    void insert(const Type& data) override{
       {
        Node<Type>* newNode = new Node<Type>(data);
        if (this->head == nullptr) {
            this->head = newNode;
        } else {
            Node<Type>* temp = this->head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    }
    
};

template<typename Type>
class OrderedLinkedList : public LinkedList<Type> {
public:
    void insert(const Type& data) override {
        Node<Type>* newNode = new Node<Type>(data);
        if (this->head == nullptr || this->head->data > data) {
            newNode->next = this->head;
            this->head = newNode;
        } else {
            Node<Type>* temp = this->head;
            while (temp->next != nullptr && temp->next->data < data) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

void deleteNodeWithSmallestInfo() override
    {
        if (this->head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node<Type> *current = this->head;
        Node<Type> *prev = nullptr;
        Node<Type> *minNode = this->head;
        Node<Type> *minPrev = nullptr;

        while (current != nullptr)
        {
            if (current->data < minNode->data)
            {
                minNode = current;
                minPrev = prev;
            }

            prev = current;
            current = current->next;
        }
        // Remove the node with the smallest info
        if (minPrev == nullptr)
        {
            this->head = minNode->next;
        }
        else
        {
            minPrev->next = minNode->next;
        }

        delete minNode;
    }
    void deleteAllOccurrences(const Type &info) override
    {
        Node<Type> *current = this->head;
        Node<Type> *prev = nullptr;

        while (current != nullptr)
        {
            if (current->data == info)
            {
                // Node with matching info found, remove it
                if (prev == nullptr)
                {
                    this->head = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                Node<Type> *temp = current;
                current = current->next;
                delete temp;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }
};
