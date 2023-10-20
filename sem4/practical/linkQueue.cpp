// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// class Queue
// {
//     Node *front;
//     Node *rear;

// public:
//     Queue()
//     {
//         front = NULL;
//         rear = NULL;
//     }
//     ~Queue()
//     {
//         Node *temp = front;
//         while (temp != NULL)
//         {
//             Node *next = temp->next;
//             delete temp;
//             temp = next;
//         }
//     }

//     int isEmpty() { return (front == NULL); }

//     int enqueue(int x)
//     {
//         Node *newNode = new Node();
//         newNode->data = x;
//         newNode->next = NULL;
//         if (isEmpty())
//         {
//             front = newNode;
//             rear = newNode;
//         }
//         else
//         {
//             rear->next = newNode;
//             rear = newNode;
//         }
//     }

//     int dequeue()
//     {
//         if (!isEmpty())
//         {
//             Node *deleteNode = front;
//             if (front == rear)
//             {
//                 front = NULL;
//                 rear = NULL;
//             }
//             else
//             {
//                 front = front->next;
//             }
//             delete deleteNode;
//         }
//     }

//     int display(){
//         if(isEmpty()){
//             cout << "Queue Underflow\n";
//             return 0;
//         }
//         else{
//             Node *temp = front;
//             while(temp != NULL){
//                 cout << temp->data << "\n";
//                 temp = temp->next;
//             }
//         }
//     }
// };

// int main()
// {
//     Queue q;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.display();
//     q.dequeue();
//     q.dequeue();
//     q.dequeue();
//     q.dequeue();
//     q.display();
//     return 0;
// }

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Queue{
    Node *front,*rear;
    public:
    Queue(){
        front = NULL ;
        rear = NULL;
    }
    ~Queue(){
        while(!isEmpty()){
            deQueue();
        }
    }
    bool isEmpty(){
        return front == NULL;
    }

    void enQueue(int x){
        Node *newNode = new Node();
        newNode->data = x;
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }else{
            rear->next = newNode;
            rear = newNode; 
        }
    }

    void deQueue(){
        if(isEmpty()){
            cout << "isEmpty\n";
        }
        else{
            Node *deleteNode = front;
            front = front->next;
            if(front == rear){
                front = rear = NULL;
            }
            delete deleteNode;
        }
    }
};