#include<iostream>
using namespace std;
int main() {
	bool asc = true, des = true;
	for (int i = 0; i < 8; i++) {
		int x;
		cin >> x;
		if (asc) {
			if (x != i + 1) asc = false;
		}
		if (des) {
			if (x != 8 - i) des = false;
		}
	}
	if (asc) cout << "ascending" << endl;
	else if (des) cout << "descending" << endl;
	else cout << "mixed" << endl;
}