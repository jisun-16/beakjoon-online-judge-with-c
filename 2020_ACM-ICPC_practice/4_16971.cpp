#include<iostream>
#include<algorithm>

using namespace std;

int n,m,a[1001][1001],col_sum[1001],row_sum[1001], total_sum;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			row_sum[i]+=a[i][j];
			col_sum[j]+=a[i][j];
			total_sum+=a[i][j];
		}
	}
	
	int ans=4*total_sum-2*(row_sum[0]+row_sum[n-1]+col_sum[0]+col_sum[m-1])+a[0][0]+a[0][m-1]+a[n-1][0]+a[n-1][m-1];
	
	for(int i=1;i<n-1;i++){
		int temp=4*total_sum-2*(row_sum[i]+row_sum[n-1]+col_sum[0]+col_sum[m-1])+(a[i][0]+a[i][m-1]+a[n-1][0]+a[n-1][m-1]);
		ans=max(ans,temp);
		temp=4*total_sum-2*(row_sum[0]+row_sum[i]+col_sum[0]+col_sum[m-1])+(a[0][0]+a[0][m-1]+a[i][0]+a[i][m-1]);
		ans=max(ans,temp);
	}
	
	for(int i=1;i<m-1;i++){
		int temp=4*total_sum-2*(row_sum[0]+row_sum[n-1]+col_sum[i]+col_sum[m-1])+(a[0][i]+a[0][m-1]+a[n-1][i]+a[n-1][m-1]);
		ans=max(ans,temp);
		temp=4*total_sum-2*(row_sum[0]+row_sum[n-1]+col_sum[0]+col_sum[i])+(a[0][0]+a[0][i]+a[n-1][0]+a[n-1][i]);
		ans=max(ans,temp);
	}
	
	cout<<ans<<'\n';
}
