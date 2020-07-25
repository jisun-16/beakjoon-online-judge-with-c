#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int tree[10001][2], level_min[10001], level_max[10001], maxlevel = 1, x = 1, node[10001];

void inorder(int key, int level) {
	if (key == -1) return;

	maxlevel = max(maxlevel, level);

	inorder(tree[key][0],level+1);
	
	level_min[level] = min(level_min[level], x);
	level_max[level] = max(level_max[level], x);
	x++;

	inorder(tree[key][1], level + 1);
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i <= 10001; i++) {
		level_min[i] = 10001;
	}

	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		tree[a][0] = b;
		tree[a][1] = c;
		node[a]++;
		node[b]++;
		node[c]++;
	}

	int root = 0;
	for (int i = 0; i < 10001; i++) 
		if (node[i] == 1) {
			root = i;
			break;
		}

	inorder(root, 1);

	int value = 1, ans = 1;
	for (int i = 1; i <= maxlevel; i++) {
		if (level_max[i] - level_min[i] +1 > value) {
			value = level_max[i] - level_min[i] + 1;
			ans = i;
		}
	}

	cout << ans << ' ' << value << endl;
}