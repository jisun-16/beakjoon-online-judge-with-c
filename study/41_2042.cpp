#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll n,m,k,arr[1000001],seg[4000010];
ll _init(ll idx,ll l,ll r){
	if(l==r) seg[idx]=arr[l];
	else{
		ll mid=(l+r)/2;
		seg[idx]=_init(idx*2,l,mid)+_init(idx*2+1,mid+1,r);
	}
	return seg[idx];
}
void _update(ll p,ll val,ll idx,ll l,ll r){
	if(p<l||p>r) return;
	seg[idx]+=val;
	if(l==r) return;
	ll mid=(l+r)/2;
	_update(p,val,idx*2,l,mid);
	_update(p,val,idx*2+1,mid+1,r);
}
ll _sum(ll idx,ll x,ll y,ll l,ll r){
	if(x>r||y<l) return 0;
	if(x<=l&&r<=y) return seg[idx];
	ll mid=(l+r)/2;
	return _sum(idx*2,x,y,l,mid)+_sum(idx*2+1,x,y,mid+1,r);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i) cin>>arr[i];
	_init(1,1,n);
	for(int i=1;i<=m+k;++i){
		ll a,b,c;
		cin>>a>>b>>c;
		if(a==1) _update(b,c-arr[b],1,1,n),arr[b]=c;
		else cout<<_sum(1,b,c,1,n)<<'\n';
	}
}
