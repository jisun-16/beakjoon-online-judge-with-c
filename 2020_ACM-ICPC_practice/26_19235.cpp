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

int _chk(){
	int ret=0;
	for(int i=2;i<6;i++){
		bool full=true;
		for(int j=0;j<4;j++)
			if(g[i][j]==0){
				full=false;
				break;
			}
		if(full){
			ret++;
			for(int j=0;j<4;j++) {
				if(g[i][j]==4)
					g[i+1][j]=1;
				if(g[i][j]==5)
					g[i-1][j]=1;
				g[i][j]=0;
			}
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
			ret++;
			for(int i=0;i<4;i++) {
				if(b[i][j]==2)
					b[i][j+1]=1;
				if(b[i][j]==3)
					b[i][j-1]=1;
				b[i][j]=0;
			}
		}
	}
	
	return ret;
}

void _clean(){
	for(int i=4;i>=0;i--)
		for(int j=0;j<4;j++){
			if(g[i][j]==1){
				int nx=i+1;
				while(nx<6&&g[nx][j]==0) nx++;
				nx--;
				if(nx!=i){
					g[nx][j]=1;
					g[i][j]=0;
				}
			}
			else if(g[i][j]==2){
				int nx=i+1;
				while(nx<6&&g[nx][j]==0&&g[nx][j+1]==0) nx++;
				nx--;
				if(nx!=i){
					g[i][j]=0;g[i][j+1]=0;
					g[nx][j]=2;g[nx][j+1]=3;
				}
			}
			else if(g[i][j]==3){
				int nx=i+1;
				while(nx<6&&g[nx][j]==0&&g[nx][j-1]==0) nx++;
				nx--;
				if(nx!=i){
					g[i][j]=0;g[i][j-1]=0;
					g[nx][j-1]=2;g[nx][j]=3;
				}
			}
			else if(g[i][j]==5){
				int nx=i+1;
				while(nx<6&&g[nx][j]==0) nx++;
				nx--;
				if(nx!=i){
					g[i][j]=0;g[i-1][j]=0;
					g[nx][j]=5;g[nx-1][j]=4;
				}
			}
		}
	
	for(int j=4;j>=0;j--)
		for(int i=0;i<4;i++){
			if(b[i][j]==1){
				int ny=j+1;
				while(ny<6&&b[i][ny]==0) ny++;
				ny--;
				if(ny!=j){
					b[i][j]=0;
					b[i][ny]=1;
				}
			}
			else if(b[i][j]==3){
				int ny=j+1;
				while(ny<6&&b[i][ny]==0) ny++;
				ny--;
				if(ny!=j){
					b[i][j-1]=0;b[i][j]=0;
					b[i][ny-1]=2;b[i][ny]=3;
				}
			}
			else if(b[i][j]==4){
				int ny=j+1;
				while(ny<6&&b[i][ny]==0&&b[i+1][ny]==0) ny++;
				ny--;
				if(ny!=j){
					b[i][j]=0;b[i+1][j]=0;
					b[i][ny]=4;b[i+1][ny]=5;
				}
			}
			else if(b[i][j]==5){
				int ny=j+1;
				while(ny<6&&b[i-1][ny]==0&&b[i][ny]==0) ny++;
				ny--;
				if(ny!=j){
					b[i-1][j]=0;b[i][j]=0;
					b[i-1][ny]=4;b[i][ny]=5;
				}
			}
		}
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
		int chk=_chk();
		 
		while(chk>0){
			ans+=chk;
			_clean();
			chk=_chk();
		}
		
		_clean2();
		/*for(int k=0;k<6;k++){
			for(int l=0;l<4;l++) printf("%d ",g[k][l]);
			printf("\n");
		}
		for(int k=0;k<4;k++){
			for(int l=0;l<6;l++) printf("%d ",b[k][l]);
			printf("\n");
		}*/
	}
	
	for(int i=0;i<6;i++)
		for(int j=0;j<4;j++){
			if(g[i][j]!=0) cnt++;
			if(b[j][i]!=0) cnt++;
		}
	
	printf("%d\n%d\n",ans,cnt);
	
	return 0;
}
