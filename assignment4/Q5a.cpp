#include <iostream>
#include <queue>
using namespace std;
class Stack {
queue<int> q1, q2;
public:
void push(int x) { q1.push(x); }
void pop() {

if(q1.empty()) return;
while(q1.size()>1){ q2.push(q1.front()); q1.pop(); }
cout << "Popped: " << q1.front() << endl;
q1.pop();
swap(q1,q2);
}
};
int main(){
Stack s;
s.push(10); s.push(20); s.push(30);
s.pop(); s.pop();
}