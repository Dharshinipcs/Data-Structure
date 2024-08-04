//Write routines to implement2 stacks using only 1 array. Your stack routines should not decalre an overflow unless every slot in the array is used.
#include <iostream>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }
    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1--];
            return x;
        } else {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            int x = arr[top2++];
            return x;
        } else {
            cout << "Stack Underflow\n";
            return -1;
        }
    }

    bool isEmpty1() {
        return top1 == -1;
    }

    bool isEmpty2() {
        return top2 == size;
    }

    bool isFull() {
        return top1 == top2 - 1;
    }
};

int main() {
    TwoStacks ts(10);

    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);

    cout << "Popped element from stack1 is " << ts.pop1() << "\n";
    cout << "Popped element from stack2 is " << ts.pop2() << "\n";

    return 0;
}


