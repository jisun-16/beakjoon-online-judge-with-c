#include<cstdio>
#define swap(a,b,temp) temp=a;a=b;b=temp;

int n, k, t[10][10], temp, ans=987654321;

void permutation(int* a, int s, int e){
	if(s==e&&a[0]==k){
		int sum=0;
		for(int i=0;i<n-1;++i){
			sum+=t[a[i]][a[i+1]];
		}
		if(ans>sum) ans=sum;
	}
	else{
		for(int i=s;i<=e;++i){
			swap(a[s],a[i],temp);
			permutation(a,s+1,e);
			swap(a[s],a[i],temp);
		}
	}
}

int main(){
	int a[10]={0,};
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%d",&t[i][j]);
		}
		a[i]=i;
	}
	
	for(int k=0;k<n;++k)
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(t[i][j]>t[i][k]+t[k][j])
					t[i][j]=t[i][k]+t[k][j];
	
	permutation(a,0,n-1);
	
	printf("%d\n",ans);
}
