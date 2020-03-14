#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n;
priority_queue<int> pq;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		pq.push(-x);
	}

	int ans = 0;
	while (!pq.empty()) {
		int x1 = pq.top();
		pq.pop();

		if (pq.empty()) {
			break;
		}

		int x2 = pq.top();
		pq.pop();

		ans -= x1 + x2;
		pq.push(x1 + x2);
	}
	
	printf("%d\n", ans);
}