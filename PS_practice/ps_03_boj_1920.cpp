#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int A[100001], n, m, B[100001];

int bisearch(int key) {
	int start = 0, end = n-1;
	while (end >= start) {
		int mid = (start + end) / 2;
		if (A[mid] == key) return 1;
		else if (key < A[mid]) end = mid - 1;
		else start = mid + 1;
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	cin >> m;
	sort(A, A + n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &B[i]);
		printf("%d\n", bisearch(B[i]));
	}
}