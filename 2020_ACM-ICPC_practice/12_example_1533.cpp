#include<iostream>
#include<vector>

using namespace std;

const long long mod=1000003;

int map[11][11];

struct mat{
	int size;
	vector<vector<long long> > a;
	mat(): size(0){}
	mat(int size): size(size){
		a=vector<vector<long long> > (size,vector<long long>(size));
	}
	
	mat operator*(const mat &b){
		mat res(size);
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				for(int k=0;k<size;k++){
					res.a[i][j]+=a[i][k]*b.a[k][j];
					res.a[i][j]%=mod;
				}
		return res;
	}
};

mat power(mat m,int n){
	if(n==1) return m;
	mat res=power(m,n/2);
	res=res*res;
	if(n%2) res=res*m;
	return res;
}

int main(){
	int n,s,e,t;
	cin>>n>>s>>e>>t;
	s--;e--;
	
	mat m(n*5);
	for(int i=0;i<n;i++)
		for(int j=1;j<5;j++) m.a[i*5+j][i*5+j-1]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int temp;
			scanf("%1d",&temp);
			if(temp==1) m.a[i*5][j*5]=1;
			else if(temp>1) m.a[i*5][j*5+temp-1]=1;
		}
	}
	
	mat ans=power(m,t);
	cout<<ans.a[s*5][e*5]<<'\n';
}
