#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>

using namespace std;

typedef struct brick {
	int bottom;
	int hei;
	int wei;
	int num;
} brick;

int n, dp[101], track[101], h[101];
brick Bricks[101];

bool cmp(brick a, brick b) { return a.bottom < b.bottom; }

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	memset(track, -1, sizeof(track));

	for (int i = 0; i < n; i++) {
		cin >> Bricks[i].bottom >> Bricks[i].hei >> Bricks[i].wei;
		Bricks[i].num = i + 1;
	}
	sort(Bricks, Bricks + n, cmp);

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		h[i] = Bricks[i].hei;
		for (int j = i - 1; j >= 0; j--) {
			if (Bricks[j].wei < Bricks[i].wei && dp[i] <= dp[j] + 1 && h[i]<h[j]+Bricks[i].hei) {
				track[i] = j;
				dp[i] = dp[j] + 1;
				h[i] = h[j] + Bricks[i].hei;
			}
		}
	}

	int mx = 0, index = -1;
	for (int i = 0; i < n; i++) {
		if (h[i] > mx) {
			mx = h[i];
			index = i;
		}
	}

	cout << dp[index] << '\n';
	stack<int> ans;
	while (index != -1) {
		ans.push(Bricks[index].num);
		index = track[index];
	}

	while (!ans.empty()) {
		cout << ans.top() << '\n';
		ans.pop();
	}
}