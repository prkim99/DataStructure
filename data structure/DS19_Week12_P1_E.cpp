#include <iostream>
using namespace std;

#define MAX 353333

class item {
public:
	int key, value;
	item() {
		this->key = 0;
		this->value = 0;
	}
};
class arr {
	item* data;
	bool flag = false;
public:
	arr(){
		data = NULL;
	}
	int getKey() {
		return data->key;
	}
	void set(int k, int v) {
		this->data = new item;
		this->data->key = k;
		this->data->value = v;
		this->flag = true;
	}
	void del() {
		data = NULL;
		this->flag = false;
	}
	bool getFlag() {
		return flag;
	}
};
arr HashArr[MAX];
int sz = 0;
int hashfunc(int idx) {
	return idx%MAX;
}
void table_clear() {
	for (int i = 0; i < MAX; i++) {
		HashArr[i].del();
	}
}

int main() {
	int T, N, X, Y, M;
	cin >> T;
	int count = 0;
	while (count < T) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> X;
			Y = hashfunc(X);
			while (HashArr[Y].getFlag() == true) {
				Y=(Y+1)%MAX;
			}
			HashArr[Y].set(X, X);
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			int fl=1;
			int c = 1;
			cin >> X;
			Y = hashfunc(X);
			if (HashArr[Y].getFlag() == false) {
				fl = 0;
			}
			else {
				while (HashArr[Y].getKey() != X) {
					Y = (Y + 1) %MAX;
					c++;
					if (HashArr[Y].getFlag() == false) {
						fl = 0;
						break;
					}
				}
			}
			cout << fl << " " << c << endl;
		}
		count++;
		table_clear();
	}
	return 0;
}
