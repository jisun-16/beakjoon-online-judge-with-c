long long sum_func(int* a, int n) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}