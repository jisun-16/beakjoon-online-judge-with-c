#include<iostream>
#include<algorithm>

using namespace std;

int n, m, res[50][50];

int main() {
	cin >> n >> m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            scanf("%1d", &res[i][j]);

	int size = min(n, m);

	for (int k = size; k >= 1; k--) {
		for (int i = 0; i <= n - k; i++) {
			for (int j = 0; j <= m - k; j++) {
				int temp = res[i][j];
				if (res[i][j + k - 1] == temp && res[i + k - 1][j] == temp && res[i + k - 1][j + k - 1] == temp) {
					cout << k * k << endl;
					return 0;
				}
			}
		}
	}
}