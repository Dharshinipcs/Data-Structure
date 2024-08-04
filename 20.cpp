//Given a string, reverse it using stack operations.
#include <iostream>
using namespace std;
class Stack {
public:
    char data;
	Stack* next;
	Stack* top=NULL;

    void push(char ch) {
        Stack* newNode = new Stack();
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        Stack* temp = top;
        char poppedData = top->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    bool isEmpty() {
        return top == NULL;
    }
};
string reverseString(string str) {
    Stack s;
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    string reversedStr;
    while (!s.isEmpty()) {
        reversedStr += s.pop();
    }

    return reversedStr;
}

int main() {
    string str;
    cout<<"Enter a string:";
    cin>>str;
    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reverseString(str) << endl;
    return 0;
}


