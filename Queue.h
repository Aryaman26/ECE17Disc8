#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H
#include<iostream>
using namespace std;
template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;


        Node(T _element, Node* _next= nullptr)
        {
            element=_element;
            next= _next;
        }
    };

    Node* front;
    Node* back;
    int numNodes;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();
};



//************************************************
// Constructor                                   *
//************************************************
template<class T>
Queue<T>::Queue()
{
    front=nullptr;
    back=nullptr;
    numNodes=0;
}

//************************************************
// Destructor                                    *
//************************************************
template<class T>
Queue<T>::~Queue()
{
    clear();
}

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template<class T>
void Queue<T>::enqueue(T num) {
    Node *newNode=Node(num);
    if(front== nullptr&&back== nullptr) {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next=newNode;
        back=newNode;
    }
    numNodes++;
}
//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************

template<class T>
void Queue<T>::dequeue(T &num) {
    Node *nodePtr= nullptr;
    if(front== nullptr&&back== nullptr) {
        cout<<"Node empty"<<endl;
    }
    else
    {
        num=front->element;
        nodePtr=front->next;
        delete front;
        front= nodePtr;
        numNodes--;
    }
}

//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************
template<class T>
bool Queue<T>::isEmpty() {
    if(front== nullptr&&back== nullptr) {
       return false;
    }
}

//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template<class T>
void Queue<T>::clear() {
    T value;
    while(!isEmpty())
    {
        dequeue(value)
    }
}


#endif //WEEK8_QUEUE_H
