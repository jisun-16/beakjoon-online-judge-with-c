#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[temp]++;
	}

	for (int i = 0; i <= 10000; i++) {
		while (arr[i]) {
			arr[i]--;
			printf("%d\n", i);
		}
	}
}