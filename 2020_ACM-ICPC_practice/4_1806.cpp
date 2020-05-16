#include<iostream>
#include<algorithm>

using namespace std;

int n, s, arr[100001], sum[100001];
int ans=100001;

void _solve(int start){
	for(int i=start;i<=n;i++){
		if(sum[i]-sum[start-1]>=s) {
			ans=min(ans,i-start+1);
			return;
		}
	}
}

int main(){
	scanf("%d %d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		sum[i]=sum[i-1]+arr[i];
	}
	
	if(sum[n]<s) {
		printf("0\n");
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		_solve(i);
	}
	printf("%d\n",ans);
}
