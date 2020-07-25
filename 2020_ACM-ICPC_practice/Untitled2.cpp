#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct ABC {
	int idx, val;
	ABC() {}
	ABC(int idx, int val) : idx(idx), val(val) {}
};

int n, m, s, e, ans, dp[10001];
bool chk[10001];
vector<ABC> A[10001];

void get_max_len(int now) {
	for (int i=0;i<A[now].size();i++) {
		ABC nxt=A[now][i];
		int nn = nxt.idx, nw = nxt.val;
		if (!dp[nn]) get_max_len(nn);
		dp[now] = max(dp[now], dp[nn] + nw);
		printf("%d\n",dp[now]);
	}
}

void get_max_cnt(int now) {
	if (chk[now]) return;
	chk[now] = true;
	for (int i=0;i<A[now].size();i++){
		ABC nxt=A[now][i];
		if (dp[nxt.idx] + nxt.val == dp[now]){
			++ans;
			get_max_cnt(nxt.idx);
		}
			
	}
		
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		A[a].push_back(ABC(b, w));
	}
	scanf("%d %d", &s, &e);

	get_max_len(s);
	get_max_cnt(s);

	printf("%d\n%d", dp[s], ans);

	return 0;
}
