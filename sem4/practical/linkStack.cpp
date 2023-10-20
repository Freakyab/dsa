// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// class Stack
// {
//     Node *top;

// public:
//     Stack()
//     {
//         top = NULL;
//     }
//     ~Stack()
//     {
//         Node *temp = top;
//         while (temp != NULL)
//         {
//             Node *next = temp->next;
//             delete temp;
//             temp = next;
//         }
//     }
//     int isEmpty() { return top == NULL; }
//     void push(int x)
//     {
//         Node *newNode = new Node();
//         newNode->data = x;
//         newNode->next = top;
//         top = newNode;
//     }
//     void pop()
//     {
//         if (isEmpty())
//         {
//             cout << "Stack Underflow\n";
//             return;
//         }
//         else
//         {
//             Node *temp = top;
//             top = top->next;
//             delete temp;
//         }
//     }
//     void display(){
//         if(isEmpty()){
//             cout << "Stack Underflow\n";
//             return;
//         }
//         else{
//             Node *temp = top;
//             while(temp != NULL){
//                 cout << temp->data << "\n";
//                 temp = temp->next;
//             }
//         }
//     }
//     void peek(){
//         if(isEmpty()){
//             cout << "Stack Underflow\n";
//             return;
//         }
//         else{
//             cout << top->data << "\n";
//         }
//     }
// };


// int main()
// {
//     Stack s1;
//     s1.push(10);
//     s1.push(20);
//     s1.push(30);
//     s1.push(40);
//     s1.push(50);
//     s1.display();
//     s1.pop();
//     s1.peek();
//     s1.pop();
//     s1.pop();
//     s1.pop();
//     s1.pop();
//     s1.pop();
//     s1.display();
//     return 0;
// }


#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class Stack{
    Node *top;
    public:
    Stack(){
        top = NULL;
    }
    bool isEmpty(){
        return top == NULL;
    }
    void push(int x){
        Node *newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << newNode ->data;
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack underFlow\n";
        }
        else{
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    void display(){
        Node *temp = top;
        while(temp!=nullptr){
            cout << temp->data;
            temp = temp->next;
        }
    }
};