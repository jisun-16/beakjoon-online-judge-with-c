#include<iostream>
#include<algorithm>

using namespace std;

int n,m,mar[301];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int s=1,e=0;
	
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>mar[i];
		s=max(s,mar[i]);
		e+=mar[i];
	}
	
	while(s<e){
		int mid=(s+e)/2;
		
		int temp=mar[0],cnt=1;
		for(int i=1;i<n;i++){
			temp+=mar[i];
			if(temp>mid){
				temp=mar[i];
				cnt++;
			}
		}
		
		if(cnt>m) s=mid+1;
		else e=mid;
	}
	
	cout<<e<<'\n';
	int temp=0,size=0;
	for(int i=0;i<n;i++){
		temp+=mar[i];
		if(temp>e){
			cout<<size<<' ';
			temp=mar[i];
			m--;
			size=0;
		}
		size++;
		if(n-i==m){
			cout<<size<<' ';
			m--;
			break;
		}
	}
	while(m--) cout<<1<<' ';
}
