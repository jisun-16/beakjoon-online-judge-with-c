#include<stdio.h>
int n,p[1001],ans;
char s[1002];
int f(int i){
	if(p[i]==i) return i;
	else return p[i]=f(p[i]);
}
void u(int a,int b){
	a=f(a);
	b=f(b);
	if(a>b) p[a]=b;
	else p[b]=a;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;++i) p[i]=i;
	for(int i=0;i<n;++i){
		if(s[i]=='E') u(i,i+1);
		else u(i,i-1);
	}
	bool visited[1001]={0,};
	for(int i=0;i<n;++i)
		if(!visited[p[i]]) visited[p[i]]=true,++ans;
    printf("%d\n",ans);
}
