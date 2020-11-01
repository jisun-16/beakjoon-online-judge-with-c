#include<iostream>
#include<algorithm>

using namespace std;

int arr[10][10],ans=100,paper[6]={-1,5,5,5,5,5};

void dfs(int r,int c,int cnt){
	bool fin=true;
	for(int i=r;fin&&i<10;i++)
		for(int j=0;fin&&j<10;j++)
			if(arr[i][j]){
				r=i;c=j;
				fin=false;
			}
	
	if(fin){
		ans=min(ans,cnt);
		return;
	}
	
	for(int i=1;i<=5;i++){
		if(!paper[i]) continue;
		
		bool chk=true;
		for(int x=r;x<r+i;x++){
			for(int y=c;y<c+i;y++){
				if(x>=10||y>=10||arr[x][y]==0){
					chk=false;
					break;
				}
			}
			if(!chk) break;
		}
		
		if(chk){
			paper[i]--;
			for(int x=r;x<r+i;x++)
				for(int y=c;y<c+i;y++)
					arr[x][y]=0;
			dfs(r,c,cnt+1);
			paper[i]++;
			for(int x=r;x<r+i;x++)
				for(int y=c;y<c+i;y++)
					arr[x][y]=1;
		}
		else break;
	}
}

int main(){
	int chk=0;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]) chk++;
		}
	
	if(chk==0){
		printf("0\n");
		return 0;
	}
	else if(chk>275){
		printf("-1\n");
		return 0;
	}
	
	dfs(0,0,0);
	
	if(ans==100) printf("-1\n");
	else printf("%d\n",ans);
}
