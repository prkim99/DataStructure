#include <iostream>
#include <string>
#include <vector>

using namespace std;
enum direction { MIN = 1, MAX = -1 };

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
		int temp = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = temp;

	}
	void upHeap(int idx) {
		if (idx == root_index) {
			return;
		}
		else {
			int p = idx / 2;
			if (v[idx] * direction < v[p] * direction) {
				swap(p, idx);
				upHeap(p);
			}
		}
	}
	void downHeap(int idx) {
		int l = idx * 2;
		int r = idx * 2 + 1;
		if (r <= heap_size) {
			if (v[l] * direction <= v[r] * direction) {
				if (v[l] * direction < v[idx] * direction) {
					swap(l, idx);
					downHeap(l);
				}
				else return;
			}
			else {
				if (v[r] * direction < v[idx] * direction) {
					swap(r, idx);
					downHeap(r);
				}
				else return;
			}
		}
		else if (l <= heap_size) {
			if (v[l] * direction < v[idx] * direction) {
				swap(l, idx);
				downHeap(l);
			}
			else return;
		}
		else return;
	}

	void insert(int e) {
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}
	int pop() {
		if (heap_size == 0) {
			return -1;
		}
		else {
			int temp = v[root_index];
			v[root_index] = v[heap_size];
			v.pop_back();
			heap_size--;
			downHeap(root_index);
			return temp;
		}

	}
	int top() {
		if (heap_size == 0) {
			return -1;
		}
		else {
			int temp = v[root_index];
			return temp;
		}
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
		if (heap_size == 0) {
			cout << -1 << endl;
		}
		else {
			for (int i = root_index; i <= heap_size; i++) {
				cout << v[i] << " ";
			}
			cout <<endl;
		}
	}
	int printP(int idx) {
		return v[idx];
	}
};
int main() {

	int M, N,nn,p;
	cin >> M;
	string input;
	int count = 0;
	while (count < M) {
		Heap a(MIN);
		cin >> N >> p;
		for (int i = 0; i < N; i++) {
			cin >> nn;
			a.insert(nn);
		};

		cout << a.printP(p) << endl;
		int *arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = a.pop();
		}
		cout << arr[p-1] << endl;
		count++;
	}
	return 0;
}