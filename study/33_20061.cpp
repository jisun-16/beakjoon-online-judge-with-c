#include<stdio.h>

int n,ans,cnt;
int g[6][4],b[4][6];

void _fill(int blk,int x,int y){
	if(blk==1){
		int nx=0;
		while(nx<6&&g[nx][y]==0) nx++;
		nx--;
		g[nx][y]=1;
		
		int ny=0;
		while(ny<6&&b[x][ny]==0) ny++;
		ny--;
		b[x][ny]=1;
	}
	else if(blk==2){
		int nx=0;
		while(nx<6&&g[nx][y]==0&&g[nx][y+1]==0) nx++;
		nx--;
		g[nx][y]=2;g[nx][y+1]=3;
		
		int ny=0;
		while(ny<6&&b[x][ny]==0) ny++;
		ny--;
		b[x][ny-1]=2;b[x][ny]=3;
	}
	else{
		int nx=0;
		while(nx<6&&g[nx][y]==0) nx++;
		nx--;
		g[nx-1][y]=4;g[nx][y]=5;
		
		int ny=0;
		while(ny<6&&b[x][ny]==0&&b[x+1][ny]==0) ny++;
		ny--;
		b[x][ny]=4;b[x+1][ny]=5;
	}
}

bool _chk(){
	for(int i=2;i<6;i++){
		bool full=true;
		for(int j=0;j<4;j++)
			if(g[i][j]==0){
				full=false;
				break;
			}
		if(full){
			for(int j=0;j<4;j++) {
				if(g[i][j]==4)
					g[i+1][j]=1;
				if(g[i][j]==5)
					g[i-1][j]=1;
				g[i][j]=0;
			}
			for(int k=i;k>=1;--k){
				for(int j=0;j<4;++j)
					g[k][j]=g[k-1][j];
			}
			for(int j=0;j<4;++j)
				g[0][j]=0;
			return true;
		}
	}
	
	for(int j=2;j<6;j++){
		bool full=true;
		for(int i=0;i<4;i++)
			if(b[i][j]==0){
				full=false;
				break;
			}
		if(full){
			for(int i=0;i<4;i++) {
				if(b[i][j]==2)
					b[i][j+1]=1;
				if(b[i][j]==3)
					b[i][j-1]=1;
				b[i][j]=0;
			}
			for(int k=j;k>=1;--k)
				for(int i=0;i<4;++i)
					b[i][k]=b[i][k-1];
			for(int i=0;i<4;++i)
				b[i][0]=0;
			return true;
		}
	}
	
	return false;
}

void _clean2(){
	int cnt_g=0,cnt_b=0;
	for(int i=0;i<2;i++){
		int gg=0,bb=0;
		for(int j=0;j<4;j++){
			if(g[i][j])
				gg=1;
			if(b[j][i])
				bb=1;
		}
		cnt_g+=gg;
		cnt_b+=bb;
	}
	
	if(cnt_g){
		for(int i=5;i>=2;i--)
			for(int j=0;j<4;j++){
				g[i][j]=g[i-cnt_g][j];
				if(i==5&&g[i][j]==4) g[i][j]=1;
			}
		
		for(int i=0;i<2;i++)
			for(int j=0;j<4;j++) g[i][j]=0;
	}
	if(cnt_b){
		for(int j=5;j>=2;j--){
			for(int i=0;i<4;i++){
				b[i][j]=b[i][j-cnt_b];
				if(j==5&&b[i][j]==2) b[i][j]=1;
			}	
		}
		
		for(int j=0;j<2;j++)
			for(int i=0;i<4;i++)
				b[i][j]=0;	
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int blk,x,y;
		scanf("%d %d %d",&blk,&x,&y);
		_fill(blk,x,y);
		bool chk=_chk();
		 
		while(chk){
			ans+=chk;
			chk=_chk();
		}
		
		_clean2();
	}
	
	for(int i=0;i<6;i++)
		for(int j=0;j<4;j++){
			if(g[i][j]!=0) cnt++;
			if(b[j][i]!=0) cnt++;
		}
	
	printf("%d\n%d\n",ans,cnt);
	
	return 0;
}
