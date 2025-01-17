//Develop an employee job scheduling system using a circular linked list. Traverse through all the employee
//tasks one at a time. And find out which employee completes the allotted task first.
#include <iostream>
using namespace std;
class Node {
public:
    string name;
    int id;
    int taskTime;
    Node* next;
};
void insertdetails(Node*& head,int id,string name, int taskTime) {
    Node* newNode = new Node();
    newNode->id = id;
    newNode->name = name;
    newNode->taskTime = taskTime;

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
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << "Employee Id: "<<temp->id <<" ,Employee :"<< temp->name << ", Task Time: " << temp->taskTime << endl;
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
string FirstCompleter(Node* head) {
    if (head == NULL) {
        return "No employees in the list.";
    }

    Node* temp = head;
    Node* firstCompleter = head;
    int minTime = head->taskTime;

    do {
        if (temp->taskTime < minTime) {
            minTime = temp->taskTime;
            firstCompleter = temp;
        }
        temp = temp->next;
    } while (temp != head);

    return firstCompleter->name;
}

int main() {
    Node* head = nullptr;

    insertdetails(head,104, "Alice", 5);
    insertdetails(head,103, "Bob", 2);
    insertdetails(head,102,"Charlie", 8);
    insertdetails(head,101,"David", 6);

    cout << "Employee Task List:" << endl;
    print(head);

    cout << "The employee who completes their task first is: " << FirstCompleter(head) << endl;

    return 0;
}
