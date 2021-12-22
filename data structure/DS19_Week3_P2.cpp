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

class SLinkedList {
public:
	Node* head;
	Node* tail;

	SLinkedList() {
		head = NULL;
		tail = NULL;
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
	int removeFront() {
		if (head == NULL) {
			return -1;
		}
		else {
			int remove = (*head).data;
			Node *a = (*head).next;
			head = a;
			(*tail).next = head;
			return remove;
		}
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
			while ((*n).next!=NULL) {
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

	int M, X;
	string input;
	SLinkedList a;
	cin >> M;
	int count = 0;
	while (count < M) {
		cin >> input;
		if (input == "empty") {
			cout << a.empty() << endl;
		}
		else if (input == "front") {
			cout << a.front() << endl;
		}
		else if (input == "addFront") {
			cin >> X;
			a.addFront(X);
		}
		else if (input == "removeFront") {
			cout << a.removeFront() << endl;
		}
		else if (input == "addBack") {
			cin >> X;
			a.addBack(X);
		}
		else if (input == "showList") {
			a.showList();
		}
		count++;
	}
	return 0;
}