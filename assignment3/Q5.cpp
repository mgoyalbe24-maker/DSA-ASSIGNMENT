#include<iostream>
#include<stack>
using namespace std;
int evaluatePostfix(string exp) {
stack<int> s;
for (char ch : exp) {
if (isdigit(ch)) {
s.push(ch - '0');
} else {
int val2 = s.top(); s.pop();
int val1 = s.top(); s.pop();
switch (ch) {
case '+': s.push(val1 + val2); break;
case '-': s.push(val1 - val2); break;
case '*': s.push(val1 * val2); break;
case '/': s.push(val1 / val2); break;
}
}
}
return s.top();
}
int main() {
string exp = "53+62/*"; // Equivalent to ((5+3)*6)/2 = 24
cout << "Result: " << evaluatePostfix(exp) << endl;
return 0;
}