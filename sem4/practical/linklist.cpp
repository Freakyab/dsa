// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// class LinkList
// {
//     Node *head;

// public:
//     LinkList()
//     {
//         head = NULL;
//     }
//     ~LinkList()
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             Node *next = temp->next;
//             delete temp;
//             temp = next;
//         }
//     }
//     void create(int x)
//     {
//         Node *newNode = new Node();
//         newNode->data = x;
//         newNode->next = head;
//         head = newNode;
//     }
//     void display()
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->data << "\n";
//             temp = temp->next;
//         }
//     }
//     void deleteData(int x)
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             if (temp->next->data == x)
//             {

//                 Node *deleteNode = temp->next;
//                 temp->next = deleteNode->next;
//                 cout << deleteNode->data <<"delete\n";
//                 return;
//             }
//             temp = temp->next;
//         }
//     }
// };

// int main()
// {
//     LinkList l1;
//     l1.create(10);
//     l1.create(20);
//     l1.create(30);
//     l1.create(40);
//     l1.deleteData(10);
//     l1.display();
// }

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkList {
    Node* head;

public:
    LinkList() {
        head = nullptr;
    }

    ~LinkList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* deleteNode = temp;
            temp = temp->next;
            delete deleteNode;
        }
    }

    void create(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    void deleteData(int x) {
        Node* temp = head;
        if (temp == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        if (temp->data == x) {
            head = temp->next;
            delete temp;
            cout << x << " deleted\n";
            return;
        }

        while (temp->next != nullptr) {
            if (temp->next->data == x) {
                Node* deleteNode = temp->next;
                temp->next = deleteNode->next;
                delete deleteNode;
                cout << x << " deleted\n";
                return;
            }
            temp = temp->next;
        }

        cout << x << " not found in the list\n";
    }
};

int main() {
    LinkList list;
    list.create(10);
    list.create(20);
    list.create(30);

    list.deleteData(20);
    list.deleteData(40);

    return 0;
}
