#include<cstdio>

using namespace std;

#define pii pair<int,int>
#define x first
#define y second

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int N,M,R,C,D;
char arr[50][50];

int main(){
	scanf("%d %d",&N,&M);
	scanf("%d %d %d",&R,&C,&D);
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			int a;
			scanf("%d",&a);
			arr[i][j]=a+'0';
		} 
	}
	
	bool fin=false;
	
	int ans=1;
	arr[R][C]='2';
	
	while(!fin){
		if(arr[R][C]=='0'){
			++ans;
			arr[R][C]='2';
		}
		
		int i=1,nr,nc,d;
		for(;i<=4;i++){
			d=D-i<0?D-i+4:D-i;
			nr=R+dx[d];nc=C+dy[d];
			
			if(arr[nr][nc]=='0')
				break;
		}
		
		if(i<=4&&(nr!=R||nc!=C)){
			R=nr;C=nc;D=d;
			continue;
		}
		
		if(arr[R-dx[D]][C-dy[D]]==1)
			fin=true;
		else{
			R=R-dx[D];C=C-dy[D];
		}
	}
	
	printf("%d\n",ans);
}
