#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

string s;
int m,n,z[1000001];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>s;
	reverse(s.begin(),s.end());
	n=s.size();
	
	z[0]=n;
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i>r)
			l=r=i;
		else
			if(i+z[i-l]<=r) {
				z[i]=z[i-l];
				continue;
			}
			else
				l=i;
		
		while(r<n&&s[r]==s[r-l]) r++;
		z[i]=r-l;
		r--;
	}
	
	cin>>m;
	while(m--){
		int q;
		cin>>q;
		cout<<z[n-q]<<'\n';
	}
}
