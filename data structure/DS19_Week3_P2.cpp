#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int e) {
		this->data = e;
		this->next= NULL;
	}
};

class CLinkedList {
public:
	Node* head;
	Node* tail;

	CLinkedList() {
		head = NULL;
		tail = NULL;
	}
	~CLinkedList()
	{

	}

	void addFront(int X) { //ㄱㅏ장앞에 노드 삽입
		if (head==NULL) {//리스트 비엇을떄
			Node *b= new Node(X);
			head = b;
			tail = b;
		}
		else {
			Node *b = new Node(X);
			(*b).next = head;
			head = b;
		}
		(*tail).next = head;
	}
	void removeFront() {
		if (head == NULL) {
		}
		else {
			Node *a = head;
			head = (*a).next;
			(*tail).next = head;
			delete a;
		}
	}
	void remove(int step) {
		Node *a = head;
		Node *b = a;
		for(int i=0;i<step;i++){
			b = a;
			a = (*a).next;
		}
		(*b).next = (*a).next;
		if ((*b).next== head) {
			tail = b;
		}
		delete a;
	}
	int front() {
		if (head == NULL) {
			return -1;
		}
		else {

			return (*head).data;
		}
	}
	int empty() {
		if (head == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void showList() {
		if (head == NULL) {
			cout << -1<<endl;
		}
		else {
			Node *n = head;
			while ((*n).next!=head) {
				cout << (*n).data << " ";
				n = (*n).next;
			}
			cout << (*n).data << endl;
		}
	}
	void addBack(int X) {
		Node * t = new Node(X);
		(*tail).next = t;
		tail = t;
		(*tail).next = head;
	}

};
int main() {

	int M, X,v;
	string input;
	cin >> M;
	int count = 0;
	while (count < M) {
		CLinkedList a;
		cin >> v;
		a.addFront(v);
		for (int i = 0; i < 9; i++) {
			cin >> v;
			a.addBack(v);
		}
		for (int j = 0; j < 3; j++) {
			cin >> input>>X;
			X = X % (10-j);
			if (input == "Delete") {
				if (X == 0) {
					a.removeFront();
				}
				else {
					a.remove(X );
				}
			}
		}
		a.showList();
		a.~CLinkedList();
		count++;
	}
	return 0;
}