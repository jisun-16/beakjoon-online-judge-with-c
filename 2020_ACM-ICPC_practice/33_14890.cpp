#include<cstdio>

int main(){
	int N,L,arr[100][100]={0,},ans=0;
	scanf("%d %d",&N,&L);
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			scanf("%d",&arr[i][j]);
	for(int i=0;i<N;++i){
		int c=1,j=0;
		for(;j<N-1;++j){
			int diff=arr[i][j+1]-arr[i][j];
			if(diff==0) ++c;
			else if(diff==-1&&c>=0) c=-L+1;
			else if(diff==1&&c>=L) c=1;
			else break;
		}
		if(j==N-1&&c>=0) ++ans;
	}
	for(int j=0;j<N;++j){
		int c=1,i=0;
		for(;i<N-1;++i){
			int diff=arr[i+1][j]-arr[i][j];
			if(diff==0) ++c;
			else if(diff==-1&&c>=0) c=-L+1;
			else if(diff==1&&c>=L) c=1;
			else break;
		}
		if(i==N-1&&c>=0) ++ans;
	}
	printf("%d\n",ans);
}
