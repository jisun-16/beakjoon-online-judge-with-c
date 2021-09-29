#include<iostream>
using namespace std;
int n,p[17],r[17][17],num,ans;
bool die[17];
void sol(int cnt,int night){
	if(die[num]||cnt==1){
		if(cnt%2) night++;
		ans=ans>night?ans:night;
		return;
	}
	if(cnt%2==0){
		for(int i=0;i<n;++i){
			if(die[i]||i==num) continue;
			int temp[17]={0,};
			for(int j=0;j<n;++j) 
				temp[j]=p[j],p[j]+=r[i][j];
			die[i]=true;
			sol(cnt-1,night);
			die[i]=false;
			for(int j=0;j<n;++j) 
				p[j]=temp[j];
		}
	}
	else{
		int idx=-1,mp=-19999;
		for(int i=0;i<n;++i)
			if(p[i]>mp&&!die[i])
				idx=i,mp=p[i];
		die[idx]=true;
		sol(cnt-1,night+1);
		die[idx]=false;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i)
		cin>>p[i];
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>r[i][j];
	cin>>num;
	if(n==1) cout<<num;
	else{
		if(n%2) sol(n,-1);
		else sol(n,0);
		cout<<ans;
	}
}
