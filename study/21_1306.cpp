#include<iostream>
#include<algorithm>

using namespace std;

int n,m,arr[1000001],seg[2000001];

int _update(int s,int e,int idx){
	if(s==e) return seg[idx]=arr[s];
	
	int mid=(s+e)/2;
	int l_max=_update(s,mid,idx*2);
	int r_max=_update(mid+1,e,idx*2+1);
	
	return seg[idx]=max(l_max,r_max);
}

int _query(int s,int e,int l,int r,int idx){
	if(e<l||s>r) return 0;
	if(s<=l&&e>=r) return seg[idx];
	
	int mid=(l+r)/2;
	int l_max=_query(s,e,l,mid,idx*2);
	int r_max=_query(s,e,mid+1,r,idx*2+1);
	
	return max(l_max,r_max);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	_update(1,n,1);
	
	for(int i=m;i+m-1<=n;i++){
		cout<<_query(i-m+1,i+m-1,1,n,1)<<' ';
	}
}
