#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

char ans[1050000];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n=0;
	cin>>n;
	
	int l=log2(n);
	if(pow(2,l)<n) l++;
	int p=pow(2,l);
	for(int i=0;i<p;i++) ans[i]='#';
	
	int d=p-n;
	int start=p/2;
	while(p>=4){
		if(p/4<=d){
			d-=p/4;
			for(int i=start+p/4;i<start+p/2;i++)
				ans[i]='.';
			start-=p/4;
		}
		else{
			start+=p/4;
		}
		p/=2;
	}
	
	cout<<ans;
}
