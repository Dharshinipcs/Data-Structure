#include <iostream>
#define MAX 10
using namespace std;

class Stack {
public:
    int count[MAX];
    string result[MAX];
    int countTop = -1;
    int resultTop = -1;

    void push(int k) {
        if (countTop < MAX - 1) {
            count[++countTop] = k;
        }
    }

    int pop() {
        if (countTop >= 0) {
            return count[countTop--];
        }
        return -1;
    }

    void pushResult(string str) {
        if (resultTop < MAX - 1) {
            result[++resultTop] = str;
        }
    }

    string popResult() {
        if (resultTop >= 0) {
            return result[resultTop--];
        }
        return "";
    }

    bool isCountEmpty() {
        return countTop == -1;
    }

    bool isResultEmpty() {
        return resultTop == -1;
    }
};

string decodeString(string s) {
    Stack stack;
    string currentString = "";
    int k = 0;

    for (int i = 0; i < s.length(); ++i) {
        char ch = s[i];
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0');
        } else if (ch == '[') {
            stack.push(k);
            stack.pushResult(currentString);
            currentString = "";
            k = 0;
        } else if (ch == ']') {
            string temp = currentString;
            currentString = stack.popResult();
            int repeatTimes = stack.pop();
            for (int j = 0; j < repeatTimes; ++j) {
                currentString += temp;
            }
        } else {
            currentString += ch;
        }
    }

    return currentString;
}

int main() {
    string s ;
    cout<<"Enter Input:";
    cin>>s;
    cout << decodeString(s) << endl;
    return 0;
}


