#include<iostream>
#include<algorithm>

using namespace std;

int n,r,c,l1,l2;
bool rl[101],cl[101];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>r>>c;
	cin>>n;
	rl[r]=true;cl[c]=true;
	for(int i=0;i<n;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		if(temp1==1) rl[temp2]=true;
		else cl[temp2]=true;
	}
	
	int pi=0;
	for(int i=1;i<=r;i++){
		if(rl[i]){
			l1=max(l1,i-pi);
			pi=i;
		}
	}
	pi=0;
	for(int i=1;i<=c;i++){
		if(cl[i]){
			l2=max(l2,i-pi);
			pi=i;
		}
	}
	
	cout<<l1*l2<<'\n';
}
