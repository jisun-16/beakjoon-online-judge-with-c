#include<iostream>
#include<algorithm>

#define swap(a,b,temp) temp=a;a=b;b=temp;

using namespace std;

int temp;
int n,m,k,ans=987654321;
int a[51][51],rot[7][3],ord[7];

void permutation(int s,int e){
	if(s==e){
		int A[51][51]={0,};
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				A[i][j]=a[i][j];
		
		for(int i=1;i<=k;i++){
			int r,c,s;
			r=rot[ord[i]][0];c=rot[ord[i]][1];s=rot[ord[i]][2];
			
			for(int j=1;j<=s;j++){
				int temp=A[r-j][c-j];
				for(int l=r-j;l<r+j;l++)
					A[l][c-j]=A[l+1][c-j];
					
				for(int l=c-j;l<c+j;l++)
					A[r+j][l]=A[r+j][l+1];
					
				for(int l=r+j;l>r-j;l--)
					A[l][c+j]=A[l-1][c+j];
					
				for(int l=c+j;l>c-j+1;l--)
					A[r-j][l]=A[r-j][l-1];
				A[r-j][c-j+1]=temp;
			}
		}
		
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=m;j++)
				sum+=A[i][j];
			ans=min(ans,sum);
		}
		return;
	}
	
	for(int i=s;i<=e;i++){
		swap(ord[s],ord[i],temp);
		permutation(s+1,e);
		swap(ord[s],ord[i],temp);
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&rot[i][0],&rot[i][1],&rot[i][2]);
		ord[i]=i;
	}
	
	permutation(1,k);
	
	printf("%d\n",ans);
}
