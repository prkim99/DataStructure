#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int data;
	Node *parent;
	Node *rChild;
	Node *lChild;

	Node() {
		this->data = NULL;
		this->parent = NULL;
		this->lChild = NULL;
		this->rChild = NULL;

	}
	Node(int data) {
		this->data = data;
		this->parent = NULL;
		this->lChild = NULL;
		this->rChild = NULL;

	}
	~Node() {

	}
	void insertlChild(Node *lChild) {
		this->lChild = lChild;
		lChild->parent = this;
	}
	void insertrChild(Node *rChild) {
		this->rChild = rChild;
		rChild->parent = this;
	}
	void printDegree() {
		int degree = 0;
			if (this->lChild != NULL)
				degree++;
			if (this->rChild != NULL)
				degree++;
			cout << degree;

	}
	void printDepth() {
		Node *tmp = this;
		int degree = 0;
		while (tmp->parent != NULL) {
			tmp = tmp->parent;
			degree++;
		}
		cout << degree;
	}
};
class BST {
public:
	Node* root;
	int height;
	BST() {
		root = NULL;
		height = 0;
	}
	~BST() {
		this->treeDestructor(this->root);
	}
	void insertNode(int data) {
		int h = 0;
		Node *nNode = new Node(data);
		if (root == NULL) {
			root = nNode;
		}
		else {
			Node *tmp = root;
			while (1) {
					h++;				
					if (tmp->data < data) {

					if (tmp->rChild != NULL)
						tmp = tmp->rChild;
					else {
						tmp->insertrChild(nNode);
						break;
					}
				}
				else {
					if (tmp->lChild != NULL)
						tmp = tmp->lChild;
					else {
						tmp->insertlChild(nNode);
						break;
					}
				}
			}
		}
		if (h > height) {
			height++;
		}
	}
	Node *findNode(int data) {
		Node *tmp = root;
		while(tmp != NULL) {
			if (tmp->data == data) {
				return tmp;
			}
			else {
				if (tmp->data < data)
					tmp = tmp->rChild;
				else
					tmp = tmp->lChild;
			}
		}
		return NULL;
	}
	void printHeight() {
		
	}
	void deleteNode() {

	}
	Node *findMin(Node* node) {
		return NULL;
	}
	void printPreorderTraversal(Node* root) {

	}
	void treeDestructor(Node* root) {
		if (root == NULL) {
			return;
		}
		if (root->lChild != NULL)
			this->treeDestructor(root->lChild);
		if (root->rChild != NULL)
			this->treeDestructor(root->rChild);
		delete(root);
	}
};
int main() {
	
	int T, N,M;
	cin >> T;
	int count = 0;
	int nn, jj;
	Node *node;
	while (count < T) {
		BST a;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nn;
			a.insertNode(nn);
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> jj;
			node = a.findNode(jj);
			if (node == NULL) {
				cout << 0 << endl;
			}
			else {
				node->printDegree();
				cout << " ";
				node->printDepth();
				cout << endl;
			}
		}
		count++;
	}
	return 0;
}

