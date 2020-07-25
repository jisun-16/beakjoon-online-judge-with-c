#include<iostream>
#include<algorithm>

using namespace std;

int n, score[301], sum[301];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> score[i];

	sum[1] = score[1];
	for (int i = 2; i <= n; i++) {
		if (i == 2)
			sum[i] = score[1] + score[2];
		else if (i == 3)
			sum[i] = max(score[1], score[2]) + score[3];
		else
			sum[i] = max(sum[i - 2], sum[i - 3] + score[i - 1]) + score[i];
	}

	cout << sum[n] << endl;
}