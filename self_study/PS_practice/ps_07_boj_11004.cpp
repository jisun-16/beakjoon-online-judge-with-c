#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, k;
	vector<int> arr;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr.emplace_back(temp);
	}

	sort(arr.begin(), arr.end());

	printf("%d\n", arr[k-1]);
}