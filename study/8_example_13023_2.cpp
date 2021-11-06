#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> fnd[2001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		fnd[a].push_back(b);
		fnd[b].push_back(a);
	}
	
	for(int a=0;a<n;a++){
		for(int bi=0;bi<fnd[a].size();bi++){
			int b=fnd[a][bi];
			for(int ci=0;ci<fnd[b].size();ci++){
				int c=fnd[b][ci];
				if(a==c) continue;
				for(int di=0;di<fnd[c].size();di++){
					int d=fnd[c][di];
					if(d==a||d==b) continue;
					for(int ei=0;ei<fnd[d].size();ei++){
						int e=fnd[d][ei];
						if(e==a||e==b||e==c) continue;
						cout<<1<<'\n';
						return 0;
					}
				}
			}
		}
	}
	
	cout<<0<<'\n';
}
