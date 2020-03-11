#include<iostream>
#include<algorithm>

using namespace std;
int height[50];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}

	int left = 0, right = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (height[i] > max) {
			left++;
			max = height[i];
		}
	}
	max = 0;
	for (int i = n-1; i >= 0; i--) {
		if (height[i] > max) {
			right++;
			max = height[i];
		}
	}

	printf("%d\n%d\n", left, right);
}