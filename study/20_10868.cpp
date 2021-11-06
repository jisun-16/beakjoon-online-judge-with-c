#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int inf=1e10;
int n,m,arr[100001],seg[400001];

int _init(int s,int e,int idx){
	if(s==e) return seg[idx]=arr[s];
	
	int mid=(s+e)/2;
	int l_min=_init(s,mid,idx*2);
	int r_min=_init(mid+1,e,idx*2+1);
	
	return seg[idx]=min(l_min,r_min);
}

int _min(int s,int e,int idx,int l,int r){
	if(e<l||s>r) return inf;
	if(s<=l&&e>=r) return seg[idx];
	
	int mid=(l+r)/2;
	int l_min=_min(s,e,idx*2,l,mid);
	int r_min=_min(s,e,idx*2+1,mid+1,r);
	
	return min(l_min,r_min);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	_init(1,n,1);
	
	for(int i=0;i<m;i++){
		int s,e;
		cin>>s>>e;
		cout<<_min(s,e,1,1,n)<<'\n';
	}
}
