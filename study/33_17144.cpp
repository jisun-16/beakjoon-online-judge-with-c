#include<cstdio>

using namespace std;

int R,C,T,arr[2][50][50],u,d;

int main(){
    scanf("%d %d %d",&R,&C,&T);
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j){
            scanf("%d",&arr[0][i][j]);
			if(arr[0][i][j]==-1){
				if(!u) u=i;
				else d=i;
			}
		}
	
	int t=0,p=1;
	while(T--){
		for(int i=0;i<R;++i)
			for(int j=0;j<C;++j) arr[p][i][j]=0;
		arr[p][u][0]=arr[p][d][0]=-1;
		for(int i=0;i<R;++i)
			for(int j=0;j<C;++j)
				if(arr[t][i][j]>0){
					int k=arr[t][i][j],m=k/5;
					if(i>0&&arr[t][i-1][j]>=0) arr[p][i-1][j]+=m,k-=m;
					if(j>0&&arr[t][i][j-1]>=0) arr[p][i][j-1]+=m,k-=m;
					if(i<R-1&&arr[t][i+1][j]>=0) arr[p][i+1][j]+=m,k-=m;
					if(j<C-1&&arr[t][i][j+1]>=0) arr[p][i][j+1]+=m,k-=m;
					arr[p][i][j]+=k;
				}
		t=p,p^=1;
		
		for(int i=u-1;i>0;--i)
			arr[t][i][0]=arr[t][i-1][0];
		for(int j=0;j<C-1;++j)
			arr[t][0][j]=arr[t][0][j+1];
		for(int i=0;i<u;++i)
			arr[t][i][C-1]=arr[t][i+1][C-1];
		for(int j=C-1;j>0;--j)
			arr[t][u][j]=arr[t][u][j-1];
		arr[t][u][1]=0;
		
		for(int i=d+1;i<R-1;++i)
			arr[t][i][0]=arr[t][i+1][0];
		for(int j=0;j<C-1;++j)
			arr[t][R-1][j]=arr[t][R-1][j+1];
		for(int i=R-1;i>d;--i)
			arr[t][i][C-1]=arr[t][i-1][C-1];
		for(int j=C-1;j>0;--j)
			arr[t][d][j]=arr[t][d][j-1];
		arr[t][d][1]=0;	
	}
	
	int ans=0;
	for(int i=0;i<R;++i)
		for(int j=0;j<C;++j)
			ans+=arr[t][i][j];
	
    printf("%d\n",ans+2);
}
