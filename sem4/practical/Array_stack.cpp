#include <iostream>
using namespace std;

class Stack {
    int maxSize;
    int top;
    int* Array;

public:
    Stack(int max) {
        maxSize = max;
        top = -1;
        Array = new int[maxSize];
    }

    ~Stack() {
        delete[] Array;
    }

    int isFull() {
        return (top == maxSize - 1);
    }
    int isEmpty() {
        return top == -1;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
        } else {
            int x = Array[top];
            top = top - 1;
            cout << "The element " << x << " removed\n";
        }
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow\n";
        } else {
            Array[++top] = x;
            cout << "The element " << x << " added\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Empty stack\n";
        } else {
            for (int i = 0; i <= top; i++) {
                cout << Array[i] << endl;
            }
        }
    }
};

int main() {
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.display();

    return 0;
}
