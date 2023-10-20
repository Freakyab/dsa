// #include <iostream>
// using namespace std;

// class Queue{
//     int front =-1;
//     int rear = -1;
//     int *Array;
//     int maxSize;
//     public:
//         Queue(int max){
//             maxSize = max;
//             Array = new int[maxSize];
//         }
//         ~Queue(){
//             delete Array;
//         }
//         int isEmpty(){
//             return (front == -1);
//         }
//         int isFull(){
//             return (rear == maxSize -1);
//         }
//         int enqueue(int x){
//             if(isFull()){
//                 cout << "Queue Overflow\n";
//                 return 0;
//             }
//             else{
//                 Array[++rear] = x;
//                 if(front == -1){
//                     front = 0;
//                 }
//             }
//         }
//         int dequeue(){
//             if(isEmpty()){
//                 cout << "Queue Underflow\n";
//                 return 0;
//             }
//             else{
//                 int x = Array[front];
//                 if(front == rear){
//                     front = -1;
//                     rear = -1;
//                 }
//                 else{
//                     front++;
//                 }
//                 return x;
//             }
//         }
//         int display(){
//             if(isEmpty()){
//                 cout << "Queue Underflow\n";
//                 return 0;
//             }
//             else{
//                 for(int i = front;i<=rear;i++){
//                     cout << Array[i] << "\n";
//                 }
//             }
//         }
// };
// int main(){
//     Queue q(10);
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.enqueue(40);
//     q.enqueue(50);
//     q.display();    
//     q.dequeue();
//     q.dequeue();
//     q.display();
// } 


#include <iostream>
using namespace std;


class Queue{
    int front ,rear,maxSize;
    int *Array;

    public :

    Queue(int max){
        int maxSize = max;
        front = -1;
        rear = -1;

        Array = new int [max];
    }

    ~Queue(){
        delete[] Array;
    }

    bool isFull(){
        return rear >=(maxSize-1);
    }

    bool isEmpty(){
        return rear == -1 && front == -1;
    }
    
    void enqueue(int x){
        if(isFull()){
            cout << "Queue overflow\n";

        }else{
            if(front == -1 && rear == -1){
                front =0; 
                rear = 0;
            }
            else{
                rear++;
            }
            Array [rear] = x;
            cout << "The element << "<< x << "is added\n";
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue underflow\n";
        }
        else{
            int x  =  Array [front];
            front++;
            if(front > rear){
                front = -1;
                rear = -1;
            }
            cout << "The element << "<< x << "is added\n";
        }
    }

    void display(){
        for(int i = front ; i<=rear ; i++){
            cout << Array[i]<<endl;
        }
    }
};