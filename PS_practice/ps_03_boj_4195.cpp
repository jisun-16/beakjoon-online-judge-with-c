#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;

int t, f;
int arr[100001];//음수인 경우에는 연결된 부모없음, 양수인 경우 부모를 가르킨다.

int findparent(int num) {
	if (arr[num] < 0) 
		return num;

	int parent = findparent(arr[num]);
	arr[num] = parent;
	return parent;
}

void merge(int ap, int bp) {
	if (ap >= bp) {
		arr[ap] += arr[bp];
		arr[bp] = ap;
	}
	else {
		arr[bp] += arr[ap];
		arr[ap] = bp;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> f;

		memset(arr, -1, sizeof(arr));
		map<string, int> name;
		int idx = 1;

		for (int i = 0; i < f; i++) {
			string temp1, temp2;
			cin >> temp1 >> temp2;

			if (name.count(temp1) == 0) name[temp1] = idx++;
			if (name.count(temp2) == 0) name[temp2] = idx++;

			int temp1P = findparent(name[temp1]);
			int temp2P = findparent(name[temp2]);
			if (temp1P == temp2P) {
				cout<< abs(arr[temp1P])<<'\n';
			}
			else {
				merge(temp1P, temp2P);
				if (temp1P >= temp2P) cout << abs(arr[temp1P]) << '\n';
				else cout << abs(arr[temp2P]) << '\n';
			}
		}
	}
}