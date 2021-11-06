#include<iostream>
#include<algorithm>
using namespace std;
int n,k,rcp[10][10],ky[20],mn[20],arr[10],ans;
int ord[3][3]={{0,0,1},{1,0,1},{0,0,0}};
void perm(int idx){
	if(ans) return;
	if(idx==n){
		int ki=0,mi=0,i=0,a=2,b=0,cnt[3]={0,};
		while(i<n){
			int aa=a==0?ky[ki++]:a==1?mn[mi++]:arr[i++];
			int bb=b==0?ky[ki++]:b==1?mn[mi++]:arr[i++];
			int winner=(rcp[aa][bb]==2?a:rcp[aa][bb]==1&&ord[a][b]?a:b);
			cnt[winner]++;
			if(cnt[winner]==k) break;
			int c=a!=0&&b!=0?0:a!=1&&b!=1?1:2;
			a=winner;
			b=c;
		}
		if(cnt[2]==k) 
			ans=1;
		return;
	}
	for(int i=idx;i<n;++i){
		swap(arr[i],arr[idx]);
		perm(idx+1);
		swap(arr[i],arr[idx]);
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>rcp[i][j];
	for(int i=0;i<20;++i) cin>>ky[i],ky[i]--;
	for(int i=0;i<20;++i) cin>>mn[i],mn[i]--;
	for(int i=0;i<n;++i) arr[i]=i;
	perm(0);
	cout<<ans<<'\n';
}
