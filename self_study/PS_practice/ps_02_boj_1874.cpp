#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int n, cnt = 1;
	bool avail = true;
	cin >> n;
	stack<int> s;
	vector<char> ans;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		while (cnt <= x) {
			s.push(cnt++);
			ans.push_back('+');
		}

		if (s.top() == x) {
			s.pop();
			ans.push_back('-');
		}
		else avail = false;
	}

	if (avail) {
		for (int i = 0; i < ans.size(); i++) printf("%c\n", ans[i]);
	}
	else cout << "NO" << endl;
}//cin cout 사용하면 시간초과