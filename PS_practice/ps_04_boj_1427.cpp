#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main() {
	long long n;
	int arr[10];
	cin >> n;

	int i = 0;
	while (n) {
		arr[i] = n % 10;
		i++;
		n /= 10;
	}

	sort(arr, arr + i, cmp);
	for (int j = 0; j < i; j++) cout << arr[j];
}