#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef struct B {
	int num;
	int area;
	int height;
	int weight;
}B;
B brick[101];
int dp[101], track[101] = { -1 };

bool cmp(B a, B b) {
	return a.weight < b.weight;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> brick[i].area >> brick[i].height >> brick[i].weight;
		brick[i].num = i + 1;
	}

	sort(brick, brick + n, cmp);

	int maxheight = -1, maxi = -1;
	dp[0] = brick[0].height;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (brick[i].area > brick[j].area && brick[i].weight > brick[j].weight) {
				if (dp[i] >= dp[j] + brick[i].height) continue;
				dp[i] = dp[j] + brick[i].height;
				track[i] = j;
			}
		}
		if (dp[i] > maxheight) {
			maxheight = dp[i];
			maxi = i;
		}
	}

	stack<int> ans;
	while (maxi!=-1) {
		ans.push(brick[maxi].num);
		maxi = track[maxi];
	}
	cout << ans.size() << '\n';
	while (!ans.empty()) {
		cout << ans.top() << '\n';
		ans.pop();
	}
}