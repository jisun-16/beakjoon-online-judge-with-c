#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, k;
bool visit[200001];

int main() {
	cin >> n >> k;

	int time = -1;
	queue<int> q;
	q.push(n);
	while (!q.empty()) 
	{
		time++;
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int u = q.front();
			q.pop();

			if (u == k) {
				queue<int> empty;
				q = empty;
				break;
			}

			if (u - 1 >= 0 && !visit[u - 1]) {
				visit[u - 1] = true;
				q.push(u - 1);
			}
			if (u + 1 <= 200000 && !visit[u + 1]) {
				visit[u + 1] = true;
				q.push(u + 1);
			}
			if (u * 2 <= 200000 && !visit[u * 2]) {
				visit[u * 2] = true;
				q.push(u * 2);
			}
		}
	}

	cout << time << '\n';
}