#include<iostream>
#include<algorithm>
using namespace std;
typedef struct coor {
	int x;
	int y;
}coordinate;
coordinate C[100001];
bool cmp(coordinate a, coordinate b) {
	if (a.x < b.x)  return true;
	else if (a.x > b.x) return false;
	else {
		if (a.y < b.y) return true;
		else return false;
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> C[i].x >> C[i].y;
	}
	sort(C, C + n, cmp);
	for (int i = 0; i < n; i++) cout << C[i].x << ' ' << C[i].y << '\n';
}