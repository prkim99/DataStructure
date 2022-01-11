
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
		int depth = 0;
		while (tmp->parent != NULL) {
			tmp = tmp->parent;
			depth++;
		}
		cout << depth;
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
		while (tmp != NULL) {
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
		cout << height << endl;
	}

	void deleteNode(Node * node) {
		if (node->lChild==NULL) {
			transplant(node, node->rChild);
		}
		else if (node->rChild == NULL) {
			transplant(node, node->lChild);
		}
		else {
			Node * min = findMin(node->rChild);
				if (min->parent != node) {
					transplant(min, min->rChild);
					min->rChild = node->rChild;
					min->rChild->parent = min;
				}
				transplant(node, min);
				min->lChild = node->lChild;
				min->lChild->parent = min;
			}
		delete node;

		}
	void transplant(Node *node, Node *chNode) {
		if (node->parent == NULL) {
			this->root = chNode;
		}
		else if (node == node->parent->lChild)
			node->parent->lChild = chNode;
		else
			node->parent->rChild = chNode;
		if (chNode != NULL)
			chNode->parent = node->parent;
	}

	Node *findMin(Node* node) {
		while (1) {
			if (node->lChild!=NULL){
				node = node->lChild;
			}
			else {
				return node;
			}
		}
	}
	void printPreorderTraversal(Node* root) {
		if (root != NULL) {
			cout << root->data << " ";
			printPreorderTraversal(root->lChild);
			printPreorderTraversal(root->rChild);
		}
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

	int T, N, M;
	cin >> T;
	int count = 0;
	int nn;
	while (count < T) {
		BST a;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> nn;
			a.insertNode(nn);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> nn;
			a.deleteNode(a.findNode(nn));
			
		}
		a.printPreorderTraversal(a.root);
		cout << endl;
		count++;  
	}
	return 0;
}
/*
2
7
18 7 26 3 12 22 30
3
18 22 12
6
92 80 24 18 38 87
3
80 24 18
*/