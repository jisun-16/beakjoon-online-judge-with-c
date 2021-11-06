#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	string n,m;
	cin>>n>>m;
	
	if(n.size()>m.size()){
		string temp=n;
		n=m;
		m=temp;
	}
	
	int cnt[26];
	for(int i=n.size();i>0;i--){
		bool chk=false;
		set<string> alp;
		string temp;
		
		for(int j=0;j<26;j++){
			cnt[j]=0;
			temp.push_back('a'+j);
			for(int k=0;k<4;k++) temp.push_back('0');
		}
		
		for(int j=0;j<n.size();j++){
			int x=n[j]-'a';
			cnt[x]++;
			for(int p=1000,k=1,v=cnt[x];p;p/=10){
				temp[x*5+k++]='0'+v/p;
				v%=p;
			}
			
			if(j<i-1) continue;	
			
			alp.insert(temp);
			
			x=n[j-i+1]-'a';
			cnt[x]--;
			for(int p=1000,k=1,v=cnt[x];p;p/=10){
				temp[x*5+k++]='0'+v/p;
				v%=p;
			}
		}
		
		for(int j=0;j<26;j++){
			cnt[j]=0;
			for(int k=1;k<=4;k++) temp[j*5+k]='0';
		}
		
		for(int j=0;j<m.size();j++){
			int x=m[j]-'a';
			cnt[x]++;
			for(int p=1000,k=1,v=cnt[x];p;p/=10){
				temp[x*5+k++]='0'+v/p;
				v%=p;
			}
			
			if(j<i-1) continue;	
			
			if(alp.count(temp)){
				chk=true;
				break;
			}
			
			x=m[j-i+1]-'a';
			cnt[x]--;
			for(int p=1000,k=1,v=cnt[x];p;p/=10){
				temp[x*5+k++]='0'+v/p;
				v%=p;
			}
		}
		
		if(chk){
			cout<<i<<'\n';
			return 0;
		}
	}
	
	cout<<0<<'\n';
}
