#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, a[4001],b[4001],c[4001],d[4001];
vector<int> sumab, sumcd;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sumab.push_back(a[i]+b[j]);
			sumcd.push_back(c[i]+d[j]);
		}
	}
	
	sort(sumab.begin(),sumab.end());
	long long ans=0;
	for(int i=0;i<n*n;i++){
		ans+=upper_bound(sumab.begin(),sumab.end(),-sumcd[i])-lower_bound(sumab.begin(),sumab.end(),-sumcd[i]);
	}
	
	cout<<ans<<'\n';
}
