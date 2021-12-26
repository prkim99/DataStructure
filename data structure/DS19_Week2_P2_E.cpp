#include <iostream>
using namespace std;
class Array {
public:
	int n;
	int * arr;

	Array(int size) {
		this->n = 0;
		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}

	int at(int idx) {
		if (arr[idx] == 0) {
			return 0;
		}
		else
			return  arr[idx];
	}

	void set(int idx, int x) {
			arr[idx] = x;
	}


	void add(int idx, int num) {
		if (idx >= n) {
			arr[n] = num;
			n++;
		}
		else {
			for (int i = n - 1; i >= idx; i--) {
				arr[i + 1] = arr[i];
			}
			arr[idx] = num;
			n++;
		}
	}


	int remove(int idx) {

		int value = arr[idx];
		for (int i = idx; i < n - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = 0;
		n--;

		return value;
	}

	void printArray() {
		if (n == 0) {
			cout << 0 << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}

};

int main() {
	unsigned int M, N;
	string input;
	int i = 0;
	cin >> M;
	unsigned int count = 0;
	while (count < M) {
		cin >> N;
		Array a(N);
		int x, kor = 0, jap = 0, chi = 0;
		for (int i = 0; i < N; i++) {
			cin >> x;
			a.add(i, x);
		}
		for (int j = 0; j < N; j++) {
			x = a.at(j);
			if (j % 3 == 0) {
				kor += x;
			}
			else if (j % 3 == 1) {
				jap += x;
			}
			else {
				chi += x;
			}
		}
		cout << kor << " " << jap << " " << chi << endl;
		a = NULL;
		count++;
	}
	return 0;
}