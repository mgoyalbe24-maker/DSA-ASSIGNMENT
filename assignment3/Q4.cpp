#include<iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char op) {
if (op == '^') return 3;
if (op == '*' || op == '/') return 2;
if (op == '+' || op == '-') return 1;
return 0;
}
string infixToPostfix(string infix) {
stack<char> s;
string postfix = "";
for (char ch : infix) {
if (isalnum(ch)) {
postfix += ch;
}
else if (ch == '(') {
s.push(ch);
}
else if (ch == ')') {
while (!s.empty() && s.top() != '(') {
postfix += s.top();
s.pop();
}
s.pop(); // remove '('
}
else {
while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
postfix += s.top();
s.pop();
}
s.push(ch);
}
}
while (!s.empty()) {
postfix += s.top();
s.pop();
}
return postfix;
}

int main() {
string infix = "a+b*c";
cout << "Postfix: " << infixToPostfix(infix) << endl;
return 0;
}