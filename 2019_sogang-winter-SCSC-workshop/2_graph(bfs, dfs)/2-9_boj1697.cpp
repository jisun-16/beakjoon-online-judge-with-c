#include<iostream>
#include<queue>
using namespace std;
#define max 200000
bool visit[max] = { 0 };
int main() {
	int N, K;
	cin >> N >> K;

	if (N == K) cout << 0 << endl;
	else {
		queue<int> q;
		int time = 0;

		q.emplace(N);
		visit[N] = true;

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int v = q.front();
				q.pop();

				if (v == K) {
					cout << time << endl;
					queue<int> empty;
					q = empty;
					break;
				}

				if (v - 1 >= 0 && !visit[v - 1]) {
					q.emplace(v - 1);
					visit[v - 1] = true;
				}
				if (v + 1 <= max && !visit[v + 1]) {
					q.emplace(v + 1);
					visit[v + 1] = true;
				}
				if (v * 2 <= max && !visit[v * 2]) {
					q.emplace(v * 2);
					visit[v * 2] = true;
				}
			}
			time++;
		}
	}
	return 0;
}