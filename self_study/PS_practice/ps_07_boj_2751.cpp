#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	vector<int> arr;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr.emplace_back(temp);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
}