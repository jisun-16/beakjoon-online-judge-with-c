#include<iostream>
#include<algorithm>

using namespace std;

int n,k;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n;
	cin>>k;
	
	int s=1,e=k;
	while(s<e){
		int mid=(s+e)/2,temp=0;
		
		int i;
		for(i=1;i*i<=mid;i++){
			temp=temp+min(n,mid/i);
		}
		temp=temp*2-(i-1)*(i-1);
		
		if(temp<k) s=mid+1;
		else e=mid;
	}
	
	cout<<e<<'\n';
}
