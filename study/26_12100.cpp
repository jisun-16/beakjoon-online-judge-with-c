#include<stdio.h>

int n,board[21][21],ans;

//dir: up(0), down(1), left(2), right(3)
void mov(int dir){
	if(dir==0){
		for(int j=0;j<n;j++){
			bool avail=true;
			for(int i=1;i<n;i++){
				if(board[i][j]==0) continue;
				
				int k=i-1;
				while(k>=0&&board[k][j]==0) k--;
				
				if(k<0||!avail||board[i][j]!=board[k][j]){
					k++;
					if(k==i) continue;
					board[k][j]=board[i][j];
					board[i][j]=0;
					avail=true;
				}
				else{
					board[k][j]+=board[i][j];
					board[i][j]=0;
					avail=false;
				}
			}
		}
	}
	else if(dir==1){
		for(int j=0;j<n;j++){
			bool avail=true;
			for(int i=n-2;i>=0;i--){
				if(board[i][j]==0) continue;
				
				int k=i+1;
				while(k<n&&board[k][j]==0) k++;
				
				if(k>=n||!avail||board[i][j]!=board[k][j]){
					k--;
					if(k==i) continue;
					board[k][j]=board[i][j];
					board[i][j]=0;
					avail=true;
				}
				else{
					board[k][j]+=board[i][j];
					board[i][j]=0;
					avail=false;
				}
			}
		}
	}
	else if(dir==2){
		for(int i=0;i<n;i++){
			bool avail=true;
			for(int j=1;j<n;j++){
				if(board[i][j]==0) continue;
				
				int k=j-1;
				while(k>=0&&board[i][k]==0) k--;
				
				if(k<0||!avail||board[i][j]!=board[i][k]){
					k++;
					if(k==j) continue;
					board[i][k]=board[i][j];
					board[i][j]=0;
					avail=true;
				}
				else{
					board[i][k]+=board[i][j];
					board[i][j]=0;
					avail=false;
				}
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			bool avail=true;
			for(int j=n-2;j>=0;j--){
				if(board[i][j]==0) continue;
				
				int k=j+1;
				while(k<n&&board[i][k]==0) k++;
				
				if(k>=n||!avail||board[i][j]!=board[i][k]){
					k--;
					if(k==j) continue;
					board[i][k]=board[i][j];
					board[i][j]=0;
					avail=true;
				}
				else{
					board[i][k]+=board[i][j];
					board[i][j]=0;
					avail=false;
				}
			}
		}
	}
}

void _dfs(int cnt){
	if(cnt==5){
		int mm=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(mm<board[i][j]) mm=board[i][j];
		if(mm>ans) ans=mm;
		return;
	}
	
	for(int dir=0;dir<4;dir++){
		int temp[21][21]={0,};
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				temp[i][j]=board[i][j];
		
		mov(dir);
		_dfs(cnt+1);
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				board[i][j]=temp[i][j];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&board[i][j]);
	
	/*mov(0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
	mov(1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
	mov(2);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
	mov(3);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}*/
	
	_dfs(0);
	
	printf("%d\n",ans);
	
	return 0;
}
