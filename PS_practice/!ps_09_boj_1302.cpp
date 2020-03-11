#include<iostream>
#include<map>

using namespace std;

int main() {
	int n;
	map<string, int> book;
	string best;

	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string title;
		cin >> title;
		book[title]++;
		if (book[title] > cnt) {
			cnt = book[title];
			best = title;
		}
		else if (book[title] == cnt && best.compare(title)>0) {
			best = title;
		}
	}

	cout << best << endl;
}//strcmp, compare사용방법 알기