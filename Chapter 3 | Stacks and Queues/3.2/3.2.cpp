/*Author : Abdallah Hemdan */
/* ___   __
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/
#include <iostream>
using namespace std;

class Stack {
 private:
  int* Arr;
  int Curr;

 public:
  Stack(int Size = 1000) {
    Arr = new int[Size];
    Curr = -1;
  }
  ~Stack() { delete[] Arr; }
  void Push(int val) { Arr[++Curr] = val; }
  void Pop() { --Curr; }
  int top() { return Arr[Curr]; }
  bool empty() { return Curr == -1; }
};

class StackWithMin {
 private:
  Stack s1, s2;

 public:
  StackWithMin() {}
  ~StackWithMin() {}
  void Push(int val) {
    if (val <= min()) {
      s2.Push(val);
    }
    s1.Push(val);
  }
  void Pop() {
    if (s1.top() == min()) s2.Pop();
    s1.Pop();
  }
  int min() {
    if (s2.empty()) return INT_MAX;
    return s2.top();
  }
  int top() { return s1.top(); }
};
int main() {
  StackWithMin mystack;

  for (int i = 0; i < 20; ++i) mystack.Push(i);

  cout << mystack.min() << " " << mystack.top() << endl;

  mystack.Push(-100);
  cout << mystack.min() << " " << mystack.top() << endl;
  mystack.Pop();
  cout << mystack.min() << " " << mystack.top() << endl;
}
