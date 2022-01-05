#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum direction{MIN=1,MAX=-1};

class Heap {
private:
	vector<int> v;
	int heap_size;
	int root_index;
	int direction;
public:
	Heap(int direction) {
		v.push_back(-1);
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction;
	}
	void swap(int idx1, int idx2) {
		int temp=v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = temp;

	}
	void unHeap(int idx) {

	}
	void downHeap(int idx){

	}
	void insert(int e) {
		v.push_back(e);
		heap_size++;
		int i = heap_size;
		while (i > 0) {
			int parent = i / 2;
			if (v[i] < v[parent]) {
				swap(i,parent);
				i = parent;
			}
			else {
				return;
			}
		}
	}
	int pop() {

	}
	int top() {

	}
	int size() {
		return heap_size;
	}
	int isEmpty() {
		if (heap_size == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void print() {
		for (int i = root_index; i < heap_size; i++) {
			cout << v[i] << " ";
		}
		cout << v[heap_size ]<<endl;
	}
};
int main() {
	Heap a(MIN);
	int M, X;
	cin >> M;
	string input;
	int count = 0;
	while (count < M) {
		cin >> input;
		if (input == "isEmpty") {
			cout << a.isEmpty() << endl;
		}
		else if (input == "insert") {
			cin >> X;
			a.insert(X);
		}
		else if (input == "size") {
			cout << a.size() << endl;
		}
		else if (input == "print") {
			a.print();
		}
		count++;
	}
	return 0;
}