#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> fibo[10001];

void _add(int x, vector<int> a, vector<int> b){
	int i=0, k=0;
	while(i<a.size()||i<b.size()){
		int tt=0;
		if(i>=a.size())
			tt=k+b[i];
		else
			tt=a[i]+b[i]+k;
		k=tt/10;
		tt%=10;
		fibo[x].push_back(tt);
		i++;
	}
	
	if(k) fibo[x].push_back(k);
}

int main(){
	fibo[3].push_back(4);
	fibo[4].push_back(7);
	for(int i=5;i<=10000;i++){
		_add(i, fibo[i-2],fibo[i-1]);
	}
	
	while(~scanf("%d", &n)){
		for(int i=fibo[n].size()-1;i>=0;i--)
			cout<<fibo[n][i];
		cout<<'\n';
	}
}
