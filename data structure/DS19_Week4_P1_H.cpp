#include<iostream>
#include<string>
using namespace std;

class arrayStack {
public:
	int* S;
	int capacity;
	int t;

	arrayStack(int capacity) {
		this->capacity = capacity;
		this->S = new int[capacity];
		this->t = -1;
	}
	bool empty() {
		if (t == -1) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int top() {
		if (t == -1) {
			return -1;
		}
		else {
			int tt = S[t];
			return tt;
		}
	}
	void push(int e) {
		S[t + 1] = e;
		t++;
	}
	int pop() {
		if (t == -1) {
			return -1;
		}
		else {
			int top = S[t];
			S[t] = NULL;
			t--;
			return top;
		}
	}
	int size() {
		return t + 1;
	}

};
int main() {

	int M, X;
	string input;
	arrayStack a(100);
	cin >> M;
	int count = 0;
	while (count < M) {
		cin >> input;
		if (input == "empty") {
			cout << a.empty() << endl;
		}
		else if (input == "top") {
			cout << a.top() << endl;
		}
		else if (input == "push") {
			cin >> X;
			a.push(X);
		}
		else if (input == "size") {
			cout << a.size() << endl;
		}
		else if (input == "pop") {
			cout << a.pop() << endl;
		}
		count++;
	}
	return 0;
}