#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node {
public:
	int data;
	Node* par;
	vector<Node*>chi;

	Node() {
		this->data = NULL;
		this->par - NULL;
	}
	Node(int data) {
		this->data = data;
		this->par = NULL;
	}
	~Node() {

	}
	void insertChild(Node* chi) {
		this->chi.push_back(chi);
		return;
	}
	void delChild(Node* chi) {
		for (int i = 0; i < this->chi.size(); i++) {
			if (this->chi[i] == chi) {
				this->chi.erase(this->chi.begin() + i);
			}
		}
		return;
	}
};
class GeneralTree {
private:
	Node* root;
	vector<Node*> node_list;
public:
	GeneralTree() {
		root = NULL;
	}
	GeneralTree(int data) {
		root = new Node(data);
		node_list.push_back(root);
	}
	~GeneralTree() {

	}
	void setRoot(int data) {
		root = new Node(data);
		node_list.push_back(root);
	}
	Node* getRoot() {
		return root;
	}
	void insertNode(int parent, int data) {
		Node *newNode = new Node(data);
		Node *n = findNode(parent);
		if (n == NULL) {
			cout << -1 << endl;
		}
		else {
			n->insertChild(newNode);
			newNode->par = n;
			node_list.push_back(newNode);
		}
	}
	void delNode(int data) {
		Node *d = findNode(data);
	}
	Node*findNode(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->data == data) {
				return node_list[i];
			}
		}
		return NULL;
	}
	void printChild(int data) {
		Node *a = findNode(data);
		if (a != NULL) {
			if (a->chi.size() != 0) {
				for (int i = 0; i < a->chi.size(); i++) {
					cout << a->chi[i]->data << " ";
				}
			}
			else {
				cout << 0 << endl;
			}
		}
		else {
			cout << -1;
		}
		cout << endl;
	}
	int countDepth(int data) {
		Node *tmp = findNode(data);
		int depth = 0;
		if (tmp == NULL) {
			return -1;
		}
		while (tmp->par != NULL) {
			tmp = tmp->par;
			depth++;
		}
		return depth;
	}
	void preorder(Node* node) {

	}
	void postorder(Node* node) {

	}
};
int main() {

	int M, X, Y;
	string input;
	GeneralTree a(1);
	cin >> M;
	int count = 0;
	while (count < M) {
		cin >> input;
		if (input == "insert") {
			cin >> X >> Y;
			a.insertNode(X, Y);
		}
		else if (input == "printChild") {
			cin >> X;
			a.printChild(X);
		}
		else if (input == "printDepth") {
			cin >> X;
			cout<<a.countDepth(X)<<endl;
		}
		count++;
	}
	return 0;
}