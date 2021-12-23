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
			int top = S[t];
			return top;
		}
	}
	void push(int e) {
		S[t + 1] = e;
		t++;
	}

};
int main() {

	int M, X;
	string input;
	arrayStack a(100000);
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
		count++;
	}
	return 0;
}