#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
int crain[51], weight[10001], pos[51];
bool check[10001];

bool cmp(int a, int b) { return a > b; }

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> crain[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> weight[i];

	sort(crain, crain + n, cmp);
	sort(weight, weight + m, cmp);

	if (crain[0] < weight[0]) {
		cout << -1 << endl;
		return 0;
	}

	int time = 0, cnt = 0;
	while (1) {
		if (cnt == m) break;

		for (int i = 0; i < n; i++) {
			while (pos[i] < m) {
				if (!check[pos[i]] && crain[i] >= weight[pos[i]]) {
					check[pos[i]] = true;
					pos[i]++;
					cnt++;
					break;
				}
				pos[i]++;
			}
		}

		time++;
	}

	cout << time << endl;
}