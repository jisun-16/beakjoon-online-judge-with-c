#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) { return a < b; }
int main() {
	int N, arr[1000];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N, cmp);
	for (int i = 0; i < N; i++) cout << arr[i] << endl;
	return 0;
}