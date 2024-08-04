#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};
void insertFront(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertEnd(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertNth(Node*& head, int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;

    if (position == 1) {
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            head = newNode;
            temp->next = head;
        }
    } else {
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{
    Node* head = NULL;

    insertFront(head, 5);
    insertFront(head,4);
    insertFront(head, 3);
    insertFront(head,2);
    insertFront(head, 1);
    cout << "After inserting at the front: ";
    print(head);

    insertEnd(head,7);
    cout << "After inserting at the end: ";
    print(head);

    insertNth(head, 5, 3);
    cout << "List after inserting 5 at position 3: ";
    print(head);
    return 0;
}
