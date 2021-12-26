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

	int M, v1,v2;
	string input;
	arrayStack a(100);
	cin >> M;
	int count = 0;
	while (count < M) {
		cin >> input;
		int N = input.size();
		for (int i=0; i < N; i++) {
			int v = input[i] - '0';
			if (1<=v&&v<=9) {
				a.push(v);
			}
			else if (v == -5) {
				v1 = a.pop();
				v2 = a.pop();
				a.push(v1 + v2);
			}
			else if (v == -3) {
				v1 = a.pop();
				v2 = a.pop();
				a.push(v2 - v1); 
			}
			else if (v == -6) {
				v1 = a.pop();
				v2 = a.pop();
				a.push(v1 * v2);
			}
		}
		cout << a.pop() << endl;
		count++;
	}
	return 0;
}
