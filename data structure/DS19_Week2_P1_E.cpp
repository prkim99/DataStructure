#include <iostream>
#include <string>
using namespace std;

class Array {
public:
	int n;
	int * arr;

	Array(int size) {
		this->n=0;
		this->arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}

	int at(int idx) {
		if (arr[idx]  == 0) {
			return 0;
		}
		else
			return  arr[idx];
	}

	void set(int idx, int x) {
		if(arr[idx] == 0){
			cout << 0<< endl;
		}
		else {
			arr[idx] = x;
		}
	}


	void add(int idx, int num) {
		if (arr[idx] == 0 || idx>=n ) {
			arr[n] = num;
			n++;
		}
		else if (n == 0) {
			arr[0] = num;
			n++;
		}
		else {
			for (int i = n-1; i >=idx; i--) {
				arr[i + 1] = arr[i];
			}
			arr[idx] = num;
			n++;
		}
	}

	/*
	int remove(int idx) {

		if (arr[idx] == NULL) {
			cout << 0;
		}
		int value = arr[idx];
		for (int i = idx; i < n - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = 0;

		return value;
	}
*/
	void printArray() {
		if (n==0) {

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

	unsigned int M, i, X;
	string input;
	Array a(10000);
	cin >> M;
	unsigned int count = 0;
	while (count < M) {
		cin >> input;
		if (input == "at") {
			cin >> i;
			cout << a.at(i) << endl;
		}
		else if (input == "set") {
			cin >> i >> X;
			a.set(i, X);
		}
		else if (input == "add") {
			cin >> i >> X;
			a.add(i, X);
		}
		count++;
	}
	return 0;
}