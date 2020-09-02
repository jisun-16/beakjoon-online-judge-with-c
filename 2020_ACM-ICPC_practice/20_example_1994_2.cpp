#include<cstdio>
#include<algorithm>
using namespace std;

int N, arr[2001];
short d[2001][2001], ans = 2;

int main()
{
	scanf("%d", &N);

	if (N < 2) {
		return puts("1"), 0;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", arr+i);
	}

	sort(arr, arr + N);

	for (int i=1; i<N-1; i++) {
		d[i][N-1] = 2;
	}

	for (int k = N - 2; k >= 0; k--) {
		int i = k - 1, j = k + 1;
		while (i >= 0 && j < N) {
			if (arr[j] + arr[i] < 2 * arr[k]) {
				++j;
			}
			else if (arr[j] + arr[i] > 2 * arr[k]) {
				d[i][k] = 2;
				--i;
			}
			else {
				d[i][k] = d[k][j] + 1;
				ans = max(d[i][k], ans);
				--i;
			}
		}
		while (i >= 0) {
			d[i][k] = 2;
			--i;
		}
	}

	printf("%d\n", ans);
	return 0;
}
