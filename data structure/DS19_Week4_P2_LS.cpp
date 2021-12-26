#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
		this->next = NULL;
	}
};
class SlinkedList {
public:
	Node* head;
	Node* tail;

	SlinkedList() {
		head = NULL;
		tail = NULL;
	}
	int front() {
		return head->data;
	}
	void addFront(int e) {
		Node* newNode = new Node(e);
		if (head == NULL) {
			head = tail = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
	}
	int removeFront() {
		Node* temp = head;
		head = head->next;
		return temp->data;
	}
};
class linkedStack {
public:
	int n;
	SlinkedList* S;

	linkedStack() {
		this->S = new SlinkedList();
		this->n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		if (n == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int top() {
		if (n == 0) {
			return 0;
		}
		else {
			int top = (*S).tail->data;
			return top;
		}
	}
	void push(int e) {
		(*S).addFront(e);
		n++;
	}
	int pop() {
		if (n == 0) {
			return 0;
		}
		else {
			int top = (*S).removeFront();
			return top;
		}
	}
};
int calPostfix(string exp) {
	linkedStack S= linkedStack();
	string postfix = exp;
	int n = postfix.size();
	char testch;
	int v1, v2;
	for (int i = 0; i < n; i++) {
		testch = exp.at(i);
		int v= testch - '0';
		if (1 <= v&&v <= 9) {
			S.push(v);
		}
		else{
			if (v == -5) {
				v1 = S.pop();
				v2 = S.pop();
				S.push(v1 + v2);
			}
			else if (v == -3) {
				v1 = S.pop();
				v2 = S.pop();
				S.push(v2 - v1);
			}
			else if (v == -6) {
				v1 = S.pop();
				v2 = S.pop();
				S.push(v1 * v2);
			}
		}
	}
	return S.pop();
}
int main() {
	string input;
	cin >> input;
	while (input!="q") {
		cout << calPostfix(input) << endl;
		cin >> input;
	}
	return 0;
}