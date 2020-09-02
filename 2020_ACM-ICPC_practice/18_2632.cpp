#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int size,mn[2],pizza[2][1001],ans;
int p_sum[2][1000001];

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>size;
	cin>>mn[0]>>mn[1];
	for(int idx=0;idx<2;idx++){
		int summ=0;
		for(int i=0;i<mn[idx];i++){
			cin>>pizza[idx][i];
			summ+=pizza[idx][i];
		}
		p_sum[idx][summ]++;
	}
	
	p_sum[0][0]=p_sum[1][0]=1;
	
	for(int idx=0;idx<2;idx++)
		for(int i=0;i<mn[idx];i++){
			int temp=0;
			for(int l=0;l<mn[idx]-1;l++){
				temp+=pizza[idx][(i+l)%mn[idx]];
				p_sum[idx][temp]++;
			}
		}
	
	for(int i=0;i<=size;i++)
		ans+=p_sum[0][i]*p_sum[1][size-i];
	
	cout<<ans<<'\n';
}
