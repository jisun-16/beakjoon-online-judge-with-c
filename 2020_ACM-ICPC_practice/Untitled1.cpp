#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
char b[20][20];
pair<int, int> coin1;
pair<int, int> coin2;
pair<int, int> key[4];
queue <pair<pair<int, int>,pair<int,int> > > Q;
bool visit[20][20][20][20];

int move();
int main() {
	int i, j, k, cnt=0;

	key[0] = make_pair(1, 0); key[1] = make_pair(-1, 0);
	key[2] = make_pair(0, 1); key[3] = make_pair(0, -1);

	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> b[i];
		for (j = 0; j < M; j++) {
			if (b[i][j] == 'o') {
				if (!cnt) {
					coin1 = make_pair(i, j); cnt++;
				}
				else coin2 = make_pair(i, j);
			}
		}
	}

	cout << move() << "\n";

	return 0;
}
int move() {
	int i, j, drop = 0;
	int movenum = 0, qsize;
	int x1, x2, y1, y2;
	pair<int, int> p1;
	pair<int, int> p2;

	Q.push(make_pair(coin1, coin2));
	visit[coin1.first][coin1.second][coin2.first][coin2.second] = 1;

	while (1) {
		qsize = Q.size();
		while (qsize) {
			p1 = Q.front().first; p2 = Q.front().second;

			for (i = 0; i < 4; i++) {
				x1 = p1.first + key[i].first; y1 = p1.second + key[i].second;
				x2 = p2.first + key[i].first; y2 = p2.second + key[i].second;

				if (b[x1][y1] == '#') { x1 = p1.first; y1 = p1.second; }
				if (b[x2][y2] == '#') { x2 = p2.first; y2 = p2.second; }
				if (x1 == x2 && y1 == y2) continue;
				//동전 위치 조정. 같은 경우 pass

				//움직인 동전이 떨어지지 않은 경우
				if ((x1 >= 0) && (x1 < N) && (y1 >= 0) && (y1 < M)
					&& (x2 >= 0) && (x2 < N) && (y2 >= 0) && (y2 < M)
					&& !visit[x1][y1][x2][y2]) {
					Q.push(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
					visit[x1][y1][x2][y2] = 1;
				}
				else {//둘 중 하나라도 떨어진 경우
 					drop = 0;
					if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M) drop++;
					if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) drop++;
					if (drop == 1) return ++movenum; /*목표달성*/
				}
			}//한 동전 네 방향 확인 끝

			Q.pop(); qsize--;
		}//한 단계 확인 끝
		movenum++;
		if (Q.empty()) break;
	}

	return -1;
}
