#include<cstdio>

int N,A[500][500],ans;
int dx[]={0,1,0,-1},dy[]={-1,0,1,0};

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) scanf("%d",&A[i][j]);
	
	int d=0,l=1,chk=0,cnt=0;
	int x=N/2,y=N/2;
	while(true){
		x=x+dx[d];y=y+dy[d];
		if(x==0&&y==-1) break;
		
		int total=A[x][y];
		int temp[]={total/100,(int)(total*0.02),(int)(total*0.05),(int)(total*0.07),total/10};
		int alpha=total-(temp[0]*2+temp[1]*2+temp[2]+temp[3]*2+temp[4]*2);
		A[x][y]=0;
		
		if(d==0){
			if(x-2<0) ans+=temp[1];
			else A[x-2][y]+=temp[1];
			
			if(x-1<0) ans+=(temp[4]+temp[3]+temp[0]);
			else{
				if(y-1<0) ans+=temp[4];
				else A[x-1][y-1]+=temp[4];
				A[x-1][y]+=temp[3];
				A[x-1][y+1]+=temp[0];
			}
			
			if(y-2<0) ans+=temp[2];
			else A[x][y-2]+=temp[2];
			
			if(y-1<0) ans+=alpha;
			else A[x][y-1]+=alpha;
			
			if(x+1>=N) ans+=(temp[4]+temp[3]+temp[0]);
			else{
				if(y-1<0) ans+=temp[4];
				else A[x+1][y-1]+=temp[4];
				A[x+1][y]+=temp[3];
				A[x+1][y+1]+=temp[0];
			}
			
			if(x+2>=N) ans+=temp[1];
			else A[x+2][y]+=temp[1];
		}
		else if(d==1){
			if(y-2<0) ans+=temp[1];
			else A[x][y-2]+=temp[1];
			
			if(y-1<0) ans+=(temp[4]+temp[3]+temp[0]);
			else{
				if(x+1>=N) ans+=temp[4];
				else A[x+1][y-1]+=temp[4];
				A[x-1][y-1]+=temp[0];
				A[x][y-1]+=temp[3];
			}
			
			if(x+2>=N) ans+=temp[2];
			else A[x+2][y]+=temp[2];
			
			if(x+1>=N) ans+=alpha;
			else A[x+1][y]+=alpha;
			
			if(y+1>=N) ans+=(temp[4]+temp[3]+temp[0]);
			else{
				if(x+1>=N) ans+=temp[4];
				else A[x+1][y+1]+=temp[4];
				A[x-1][y+1]+=temp[0];
				A[x][y+1]+=temp[3];
			}
			
			if(y+2>=N) ans+=temp[1];
			else A[x][y+2]+=temp[1];
		}
		else if(d==2){
			if(x-2<0) ans+=temp[1];
			else A[x-2][y]+=temp[1];
			
			if(x-1<0) ans+=(temp[4]+temp[3]+temp[0]);
			else{
				if(y+1>=N) ans+=temp[4];
				else A[x-1][y+1]+=temp[4];
				A[x-1][y]+=temp[3];
				A[x-1][y-1]+=temp[0];
			}
			
			if(y+2>=N) ans+=temp[2];
			else A[x][y+2]+=temp[2];
			
			if(y+1>=N) ans+=alpha;
			else A[x][y+1]+=alpha;
			
			if(x+1>=N) ans+=(temp[4]+temp[3]+temp[0]);
			else{
				if(y+1>=N) ans+=temp[4];
				else A[x+1][y+1]+=temp[4];
				A[x+1][y]+=temp[3];
				A[x+1][y-1]+=temp[0];
			}
			
			if(x+2>=N) ans+=temp[1];
			else A[x+2][y]+=temp[1];
		}
		else{
			if(y-2<0) ans+=temp[1];
			else A[x][y-2]+=temp[1];
			
			if(y-1<0) ans+=(temp[4]+temp[3]+temp[0]);
			else{
				if(x-1<0) ans+=temp[4];
				else A[x-1][y-1]+=temp[4];
				A[x][y-1]+=temp[3];
				A[x+1][y-1]+=temp[0];
			}
			
			if(x-2<0) ans+=temp[2];
			else A[x-2][y]+=temp[2];
			
			if(x-1<0) ans+=alpha;
			else A[x-1][y]+=alpha;
			
			if(y+1>=N) ans+=(temp[4]+temp[3]+temp[0]);
			else{
				if(x-1<0) ans+=temp[4];
				else A[x-1][y+1]+=temp[4];
				A[x][y+1]+=temp[3];
				A[x+1][y+1]+=temp[0];
			}
			
			if(y+2>=N) ans+=temp[1];
			else A[x][y+2]+=temp[1];
		}
		
		if(++cnt==l){
			cnt=0;
			d=(d+1==4)?0:d+1;
			if(++chk%2==0)
				l++;
		}
	}
	
	printf("%d\n",ans);
}
