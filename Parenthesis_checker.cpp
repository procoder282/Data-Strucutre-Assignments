#include <iostream>
using namespace std;
#define n 10

class check {
public:
    int top;
    char arr[n];
    
    check() {
        top = -1;}
    void push(char a) {
        if (top != n - 1) {
            top++;
            arr[top] = a;
        } else {
            cout << "Stack is full...\n";
        }
    }
      void pop() {
        if (top != -1) {
            top--;
        } else {
            cout << "Stack is empty...\n";
        }
    }
     bool empty() {
        return (top == -1);
    }
};

int main() {
    check a;
    int p;
    cout << "Enter number of elements in expression: ";
    cin >> p;
     char arr[p];
    cout << "Enter the expression:\n";
    for (int i = 0; i < p; i++) {
        cin >> arr[i];
    }
  for (int i = 0; i < p; i++) {
        if (arr[i] == '(' || arr[i] == '[' || arr[i] == '{') {
            a.push(arr[i]);
        } else if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}') {
            if (a.empty()) {
                cout << "NOT WELL PARENTHESIZED EXPRESSION";
                return 0;
            }
   char topChar = a.arr[a.top];
            if ((arr[i] == ')' && topChar == '(') ||
                (arr[i] == ']' && topChar == '[') ||
                (arr[i] == '}' && topChar == '{')) {
                a.pop();
            } else {
                cout << "NOT WELL PARENTHESIZED EXPRESSION";
                return 0;
            }
        }
    }
  if (a.empty()) {
        cout << "WELL PARENTHESIZED EXPRESSION";
    } else {
        cout << "NOT WELL PARENTHESIZED EXPRESSION";
    }
   return 0;
}
