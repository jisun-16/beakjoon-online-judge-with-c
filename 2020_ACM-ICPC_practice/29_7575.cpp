#include<cstdio>
#include<algorithm>

using namespace std;

int n,k,l[100],p[100][1000];

bool chk(int s,int e){	
	int q[1000]={0,},j=0;
	
	for(int i=1;i<k;i++){
		while(j>0&&p[0][s+i]!=p[0][s+j])
			j=q[j-1];
		if(p[0][s+i]==p[0][s+j])
			q[i]=++j;
	}
	
	for(int i=1;i<n;i++){
		if(k>l[i]) return false;
		
		bool isexist=false;
		int jj=0;
		for(int j=0;j<l[i];j++){
			while(jj>0&&p[i][j]!=p[0][s+jj])
				jj=q[jj-1];
			if(p[i][j]==p[0][s+jj]){
				if(jj==k-1){
					isexist=true;
					break;
				}
				else
					jj++;
			}	
		}
		
		if(!isexist){
			jj=0;
			for(int j=l[i]-1;j>=0;j--){
				while(jj>0&&p[i][j]!=p[0][s+jj])
					jj=q[jj-1];
				if(p[i][j]==p[0][s+jj]){
					if(jj==k-1){
						isexist=true;
						break;
					}
					else
						jj++;
				}
			}
		}
		
		if(!isexist)
			return false;
	}
	
	return true;
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&l[i]);
		for(int j=0;j<l[i];j++) scanf("%d",&p[i][j]);
	}
	
	for(int i=0;i<=l[0]-k;i++)
		if(chk(i,i+k-1)){
			printf("YES\n");
			return 0;
		}
	
	printf("NO\n");
	return 0;
}
