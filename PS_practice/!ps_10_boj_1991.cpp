#include<iostream>

using namespace std;

char Tree[26][2];
int i;

void treversal(int start) {
	if (start + 'A' == '.') return;

	if (i == 0) printf("%c", start + 'A');
	treversal(Tree[start][0] - 'A');
	if (i == 1)	printf("%c", start + 'A');
	treversal(Tree[start][1] - 'A');
	if (i == 2)	printf("%c", start + 'A');
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char a, b, c;
		scanf(" %c %c %c", &a, &b, &c);
		Tree[a - 'A'][0] = b;
		Tree[a - 'A'][1] = c;
	}

	for (i = 0; i < n; i++) {
		treversal(0);
		printf("\n");
	}
}