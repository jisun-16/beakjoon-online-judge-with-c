#include<cstdio>
#include<algorithm>

using namespace std;

int n,arr[1000],ans=1;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",&arr[i]);
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;++i){
		if(ans<arr[i]) break;
		ans+=arr[i];
	}
	
	printf("%d\n",ans);
}
