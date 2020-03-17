#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int n, m;
vector<int> book;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		book.push_back(temp);
	}

	sort(book.begin(), book.end());

	int ans = 0;
	for (int i = 0; i < book.size() && book[i] < 0; i += m) {
		ans += abs(book[i]) * 2;
	}
	for (int i = book.size() - 1; i >= 0 && book[i] > 0; i -= m)
		ans += book[i] * 2;

	ans -= max(abs(book.front()), abs(book.back()));

	cout << ans << endl;
}