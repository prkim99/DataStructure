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
	void clr() {
		delete Q;
		Q = NULL;
	}
	int size() {
		int s = (r - f + 1 + capacity) % capacity;
		return s;
	}
	bool isEmpty() {
		if (size() == 0) {
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
	int dequeue() {
		if (isEmpty() == 1) {
			//cout << "Empty" << endl;
			return 0;
		}
		else {
			int temp = Q[f];
			f++;
			f = f % capacity;
			return temp;
		}
	}
	bool isfull() {
		if (size() == (capacity - 1)) {
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
	int T, N,x;
	cin >> T;
	int count = 0;
	while (count < T) {
		cin >> N;
		arrQueue x1(N+1);
		arrQueue x2(N + 1);
		int x1Score = 0, x2Score = 0;
		int x22 = 0, x11 = 0;
		for (int i = 0; i < N; i++) {
			cin >> x;
			x1.enqueue(x);
		}
		for (int i = 0; i < N; i++) {
			cin >> x;
			x2.enqueue(x);
		}
		
		for (int i = 0; i < N; i++) {
			 x11= x11+x1.dequeue();
			 x22= x22+x2.dequeue();
			if (x11 > x22) {
				x11 = x11 - x22 - 1;
				x22 = 0;
				x1Score++;
			}
			else if (x11 < x22) {
				x22 = x22 - x11 - 1;
				x11 = 0;
				x2Score++;
			}
		}
		if (x1Score > x2Score) {
			cout << 1 << endl;
		}
		else if (x1Score < x2Score) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}
		x1.clr();
		x2.clr();
		count++;
	}
	return 0;
}