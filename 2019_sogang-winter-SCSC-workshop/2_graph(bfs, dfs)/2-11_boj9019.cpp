#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define max 10000

char c[] = "DSLR";
int A, B;
bool check[max];
int path[max], command[max];

void bfs() {
	queue<int> q;
	q.push(A);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == B) {
			vector<char> v;
			int mx = x;
			while(mx != A) {
				v.push_back(command[mx]);
				mx = path[mx];
			}
			int m = v.size();
			for (int i = 0; i < m; i++) cout << v[m - i - 1];
			cout << '\n';
			return;
		}

		int nx[] = { x * 2 % max, x - 1, x % 1000 * 10 + x / 1000, x % 10 * 1000 + x / 10 };
		if (nx[1]<0) nx[1] = 9999;

		for (int i = 0; i < 4; i++) {
			if (check[nx[i]]) continue;
			check[nx[i]] = true;
			path[nx[i]] = x;
			command[nx[i]] = c[i];
			q.push(nx[i]);
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		memset(check, 0, sizeof(check));
		bfs();
	}
	return 0;
}