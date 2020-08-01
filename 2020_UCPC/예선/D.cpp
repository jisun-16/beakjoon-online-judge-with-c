#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	vector<vector<int> > t(n);
	
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	
	long long d=0,g=0,one=1;
	for(int i=0;i<n;i++){
		int s=t[i].size();
		if(s<2) continue;
		
		if(s>=3) g+=one*s*(s-1)*(s-2)/6;
		for(int j=0;j<s;j++){
			int ss=t[t[i][j]].size();
			if(ss<2) continue;
			d+=one*(s-1)*(ss-1);
		}
	}
	d/=2;
	
	if(d>g*3) cout<<"D\n";
	else if(d<g*3) cout<<"G\n";
	else cout<<"DUDUDUNGA\n";
}
