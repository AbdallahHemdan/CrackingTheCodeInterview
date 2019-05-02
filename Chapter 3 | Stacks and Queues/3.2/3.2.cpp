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


// Solution 1
// I will add Min var with each node of the stack whick store the minimum element before our current element
typedef struct Node {
	int Value, Min; 
}Node;

class StackWithMin_2 {
private:
	Node *Arr;
	int Curr;
public:
	StackWithMin_2(int size = 1000) {
		Arr = new Node[size];
		Arr[0].Min = INT_MAX;
		Curr = 0;
	}
	~StackWithMin_2() {
		delete[] Arr;
	}
	void Push(int Value) {
		Arr[++Curr].Value = Value;
		if (Value<Arr[Curr - 1].Min) Arr[Curr].Min = Value;
		else Arr[Curr].Min = Arr[Curr - 1].Min;
	}
	void Pop() {
		--Curr;
	}
	int top() {
		return Arr[Curr].Value;
	}
	bool empty() {
		return Curr == 0;
	}
	int Min() {
		return Arr[Curr].Min;
	}
};


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
