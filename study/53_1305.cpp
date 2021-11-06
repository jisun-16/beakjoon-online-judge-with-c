#include<stdio.h>
using namespace std;
//kmp
int main(){
	int L,v[10001]={0,};
	char s[10002];
	scanf("%d",&L);
	scanf("%s",s);
	v[0]=-1;
	for(int i=1;i<L;++i){
		int j=v[i-1];
		while(s[i]!=s[j+1]&&j>=0)
			j=v[j];
		if(s[i]==s[j+1]) v[i]=j+1;
		else v[i]=-1;
	}
	printf("%d\n",L-1-v[L-1]);
}
