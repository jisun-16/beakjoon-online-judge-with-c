#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int LCS[1001][1001];

int main() {
	string A, B;
	cin >> A >> B;

	int lenA = A.length();
	int lenB = B.length();

	for (int i = 0; i < lenA; i++) {
		for (int j = 0; j < lenB; j++) {
			if (A[i] == B[j]) {
				LCS[i + 1][j + 1] = max({ LCS[i][j + 1],LCS[i][j] + 1, LCS[i + 1][j] });
				continue;
			}
			LCS[i + 1][j + 1] = max(LCS[i + 1][j], LCS[i][j + 1]);
		}
	}

	cout << LCS[lenA][lenB] << endl;
}