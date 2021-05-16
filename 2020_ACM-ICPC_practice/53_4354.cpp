#include<iostream>
using namespace std;
int v[1000001];
char s[1000001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(true){
		cin>>s;
		if(s[0]=='.') break;
		int i,j;
		for(i=1,j=0;s[i];++i){
			while(j&&s[i]!=s[j])
				j--;
			if(s[i]==s[j]) v[i]=++j;
			else v[i]=0;
		}
		if(i%(i-v[i-1])) cout<<1<<'\n';
		else cout<<i/(i-v[i-1])<<'\n';
	}
}
