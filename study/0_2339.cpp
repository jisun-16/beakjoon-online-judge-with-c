#include<iostream>
using namespace std;
int n,arr[20][20],ans;
int sol(int x1,int y1,int x2,int y2,int hori){
	int ret=0,imp=0,jem=0;
	for(int i=x1;i<=x2;++i)
		for(int j=y1;j<=y2;++j){
			if(arr[i][j]==1){
				++imp;
				if(hori){
					int k;
					for(k=x1;k<=x2;++k)
						if(arr[k][j]==2) break;
					if(k>x2)
						ret+=sol(x1,y1,x2,j-1,0)*sol(x1,j+1,x2,y2,0);
				}
				else{
					int k;
					for(k=y1;k<=y2;++k)
						if(arr[i][k]==2) break;
					if(k>y2)
						ret+=sol(x1,y1,i-1,y2,1)*sol(i+1,y1,x2,y2,1);
				}
			}
			else if(arr[i][j]==2) ++jem;
		}
	if(imp==0) return jem==1?1:0;
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>arr[i][j];
	ans=sol(0,0,n-1,n-1,0)+sol(0,0,n-1,n-1,1);
	if(ans) cout<<ans<<'\n';
	else cout<<-1<<'\n';
}
