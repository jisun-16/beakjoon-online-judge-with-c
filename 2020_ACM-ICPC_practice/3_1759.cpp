#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int l, c;
char alp[15], vowels[5]={'a','e','i','o','u'};

void solve(int start, int vow, int con, string ans){
	if(vow+con==l){
		if(vow>=1&&con>=2) cout<<ans<<'\n';
		return;
	}
	for(int i=start;i<c;i++){
		bool is_vow=false;
		for(int j=0;j<5;j++) 
			if(alp[i]==vowels[j]) is_vow=true;
		
		if(is_vow) solve(i+1,vow+1,con,ans+alp[i]);
		else solve(i+1,vow,con+1,ans+alp[i]);
	}
}

int main(){
	cin>>l>>c;
	for(int i=0;i<c;i++) cin>>alp[i];
	sort(alp,alp+c);
	solve(0,0,0,"");
}
