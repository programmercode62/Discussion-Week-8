#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H

using namespace std;
template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;
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
front = nullptr;
back = nullptr;
numNodes = 0;

//************************************************
// Destructor                                    *
//************************************************
template <class T>
void Queue<T>::clear();

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template <class T>
void Queue<T>::enqueue(T num) {
    Node *newNode = new Node(num);
    if (isEmpty()) {
        front = newNode;
        back = newNode;

    }
    back ->next = newNode;
    back = newNode;
    ++numNodes;

}

//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************
template <class T>
void Queue<T>::dequeue(T &num) {
    Node* nodePtr = nullptr;

    if (isEmpty()) {
        cout<< "Empty Queue" << endl;

    } else {
        num= front -> element;
        nodePtr = front -> next;
        delete front;
        front = nodePtr;
    }
}

//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************
template <class T>
bool Queue<T>:: isEmpty () {
    return numNodes == 0;
}

//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template <class T>
void Queue<T>::clear() {
   if (numNodes != 0) {
       --numNodes;
   }
}

#endif //WEEK8_QUEUE_H
