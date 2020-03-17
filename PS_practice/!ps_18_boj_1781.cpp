#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
using pii = pair<int, int>;

int n;
vector<pii> problem;

bool cmp(pii a, pii b) { 
	if (a.first < b.first) return true;
	else if (a.first > b.first) return false;
	else {
		if (a.second > b.second) return true;
		else return false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int dl, cup;
		cin >> dl >> cup;
		problem.push_back(pii(dl, cup));
	}
	
	sort(problem.begin(), problem.end());

	priority_queue<int> pq;
	for (pii x : problem) {
		int dl = x.first;
		pq.push(-x.second);
		while (dl < pq.size()) pq.pop();
	}

	int ans = 0;
	while (!pq.empty()) {
		ans -= pq.top();
		pq.pop();
	}
	cout << ans << endl;
}