#include <iostream>
using namespace std;

#define MAX 353333
enum flag { AVAIL = 2,YES=1,NO=0 };
class item {
public:
	int key, value;
	item() {
		this->key =-1;
		this->value = -1;
	}
};
class arr {
	item* data;
	int flag = NO;
public:
	arr() {
		data = NULL;
	}
	int getKey() {
		return data->key;
	}
	void set(int k, int v) {
		this->data = new item;
		this->data->key = k;
		this->data->value = v;
		this->flag = YES;
	}
	void clr() {
		data = NULL;
		this->flag = NO;
	}
	void del() {
		data = NULL;
		this->flag = AVAIL;
	}
	int getFlag() {
		return flag;
	}
};
arr HashArr[MAX];
int sz = 0;
int hashfunc(int idx) {
	return idx%MAX;
}
int hashfunc2(int idx) {
	return(17 - (idx % 17));
}
void table_clear() {
	for (int i = 0; i < MAX; i++) {
		HashArr[i].clr();
	}
}
void insert_linear(int X) {
	int Y = hashfunc(X);
	while (HashArr[Y].getFlag() == YES) {
		Y = (Y + 1) % MAX;
	}
	HashArr[Y].set(X, X);
}
void search(int X) {
	int fl = 1;
	int c = 1;
	int Y = hashfunc(X);
	if (HashArr[Y].getFlag() == NO) {
		fl = 0;
	}
	else {
		while ( HashArr[Y].getKey() != X) {
			Y = (Y + 1) % MAX;
			c++;
			if (HashArr[Y].getFlag() == NO) {
				fl = 0;
				break;
			}
		}
	}
	cout << fl << " " << c << endl;
}
void del_linear(int X) {
	int fl = 1;
	int c = 1;
	int Y = hashfunc(X);
	while (true) {
		if (HashArr[Y].getFlag() == NO) {
			fl = 0;
			break;
		}
		else {
			if (HashArr[Y].getFlag() == AVAIL) {
				Y = (Y + 1) % MAX;
				c++;
			}
			else if (HashArr[Y].getKey() != X) {
				Y = (Y + 1) % MAX;
				c++;
			}
			else {
				HashArr[Y].del();
				break;
			}
		}
	}
	cout << fl << " " << c << endl;
	return;
	
}

void insert_double(int X){
	int Y = hashfunc(X);
	if (HashArr[Y].getFlag()!=YES) {
		HashArr[Y].set(X,X);
		return;
	}
	else {
		int Y2 = hashfunc2(X);
		while (true) {
			Y = (Y + Y2)%MAX;
			if (HashArr[Y].getFlag() != YES) {
				HashArr[Y].set(X, X);
				return;
			}
		}
	}
}
void search_double(int X){
	int c = 1;
	int fl = 1;
	int Y = hashfunc(X);
	int Y2 = hashfunc2(X);
	while (true) {
		if (HashArr[Y].getFlag() == NO) {
			fl = 0;
			break;
		}
		else {
			if (HashArr[Y].getFlag() == AVAIL) {
				Y = (Y + Y2) % MAX;
				c++;
			}
			else if (HashArr[Y].getKey() != X) {
				Y = (Y + Y2) % MAX;
				c++;
			}
			else {
				break;
			}
		}
	}
	cout << fl << " " << c << endl;
}
int main() {
	int T, N, X, M;
	cin >> T;
	int count = 0;
	while (count < T) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> X;
			insert_linear(X);
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			cin >> X;
			del_linear(X);
		}
		count++;
		table_clear();
	}
	return 0;
}
