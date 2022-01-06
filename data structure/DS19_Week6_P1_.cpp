#include <iostream>
#include <string>
using namespace std;

class arrQueue {
public:
	int *Q;
	int capacity;
	int f;
	int r;

	arrQueue(int size) {
		this->Q = new int[size];
		this->capacity = size;
		this->f = 0;
		this->r = -1;
	}
	int size() {
		int s=(r-f+1+capacity)%capacity;
		return s;
	}
	bool isEmpty() {
		if (size()==0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void enqueue(int data) {
		if (this->isfull()) {
			cout << "full" << endl;
		}
		else {
			r++;
			r = r%capacity;
			Q[r] = data;
		}
	}
	void dequeue() {
		if (isEmpty() == 1) {
			cout << "Empty" << endl;
		}
		else {
			int temp = Q[f];
			this->f = (f + 1) % capacity;
			cout << temp << endl;
		}
	}
	bool isfull() {
		if (size()==(capacity-1)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	int front() {
		if (isEmpty() == 1) {
			return 0;
		}
		return Q[f];
	}
	int rear() {
		if (isEmpty() == 1) {
			return 0;
		}
		return Q[r];
	}
};
int main() {
	int S,N,x;
	cin >> S>>N;
	arrQueue a(S+1);
	int count = 0;
	string cmd;
	while (count < N) {
		cin >> cmd;
		if (cmd == "enqueue") {
			cin >> x;
			a.enqueue(x);
		}
		else if (cmd == "isEmpty") {
			cout << a.isEmpty() << endl;
		}
		else if (cmd == "size") {
			cout << a.size() << endl;
		}
		if (cmd == "dequeue") {
			a.dequeue();
		}
		else if (cmd == "front") {
			if (a.front() == 0) 
				cout << "Empty" << endl;
			else
				cout << a.front() << endl;
		}
		else if (cmd == "rear") {
			if (a.rear() == 0)
				cout << "Empty" << endl;
			else
				cout << a.rear() << endl;
		}
		count++;
	}
	return 0;
}