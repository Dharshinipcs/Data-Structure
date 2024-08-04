//Pairwise swap of elements in a circular doubly linked list. If the number of nodes is odd, keep the last one
//without swapping. Print the new list.
#include <iostream>
using namespace std;
class Node {
public:
int data;
Node* next;
Node* prev;
};
void insertFront(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* tail = head->prev;

        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void pairwiseSwap(Node* head) {
if (head == NULL || head->next == head) {
return;
}
Node* current = head;
Node* x = NULL;
int temp = 0;
do {
x = current->next;
temp = current->data;
current->data = x->data;
x->data = temp;
current = x->next;
} while (current != head && current->next != head);

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
int main() {
Node* head = NULL;
insertFront(head, 5);
insertFront(head, 4);
insertFront(head, 3);
insertFront(head, 2);
insertFront(head, 1);

cout<<"Original Circular Doubly Linked List:";
print(head);

pairwiseSwap(head);
cout<<"List after pairwise swapping:";
print(head);
return 0;
}
