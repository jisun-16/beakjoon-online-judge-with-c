#include<iostream>
using namespace std;
int checkinout(int x, int y, int cx, int cy, int r) {
	if ((x - cx)*(x-cx) + (y - cy)*(y-cy) < r*r) return 1;
	return 0;
}
int main() {
	int T;
	cin >> T;

	while (T--) {
		int sx, sy, fx, fy, n, cnt = 0;
		cin >> sx >> sy >> fx >> fy;
		cin >> n;
		
		while (n--) {
			int cx, cy, r;
			cin >> cx >> cy >> r;
			int start = checkinout(sx, sy, cx, cy, r);
			int finish = checkinout(fx, fy, cx, cy, r);
			if (start + finish == 1) cnt++;
		}

		cout << cnt << endl;
	}
}