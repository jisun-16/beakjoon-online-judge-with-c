#include<cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int N,arr[20][20],ans=40000,total=0;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d",&arr[i][0]);
		for(int j=1;j<N;++j){
			scanf("%d",&arr[i][j]);
			arr[i][j]+=arr[i][j-1];
		}
		total+=arr[i][N-1];
	}
		 
	for(int x=0;x<N-2;++x)
		for(int y=1;y<N-1;++y)
			for(int d1=1;y-d1>=0&&x+d1<N-1;++d1)
				for(int d2=1;y+d2<N&&x+d1+d2<N;++d2){
					int a=0,b=0,c=0,d=0,e=0;
					
					for(int i=0;i<x;++i)
						a+=arr[i][y],b+=arr[i][N-1]-arr[i][y];
					for(int i=x+d1+d2+1;i<N;++i)
						c+=arr[i][y-d1+d2-1],d+=arr[i][N-1]-arr[i][y-d1+d2-1];
					for(int i=0;i<d1||i<=d2;++i){
						if(i<d1) a+=arr[x+i][y-i-1];
						if(i<=d2) b+=arr[x+i][N-1]-arr[x+i][y+i];
					}
					for(int i=0;i<=d2;++i)
						c+=arr[x+d1+i][y-d1+i-1];
					for(int i=1;i<=d1;++i)
						d+=arr[x+d2+i][N-1]-arr[x+d2+i][y+d2-i];
					e=total-(a+b+c+d);
					
					int M=max(a,max(b,max(c,max(d,e))));
					int m=min(a,min(b,min(c,min(d,e))));
					ans=min(ans,M-m);
				}
	
	printf("%d\n",ans);
}
