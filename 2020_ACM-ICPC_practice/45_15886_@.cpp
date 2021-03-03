#include<cstdio>
int main(){
	int n,ans=0;
	char a[1001];
	scanf("%d",&n);
	scanf("%s",a);
	for(int i=0;i<n-1;++i)
		if(a[i]=='E'&&a[i+1]=='W') ++ans;
	printf("%d\n",ans);
}
