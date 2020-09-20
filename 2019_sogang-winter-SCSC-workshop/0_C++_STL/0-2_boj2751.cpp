#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.emplace_back(temp);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N;i++) printf("%d\n", arr[i]);
	return 0;
}