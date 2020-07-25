#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;
typedef vector<vector<ll> > mat;

const ll mod=1234567891;
int n,l;

mat operator*(const mat& a,const mat& b){
	mat ret(2,vector<ll>(2,0));
	
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++){
				ret[i][j]+=(a[i][k]*b[k][j])%mod;
				ret[i][j]%=mod;
			}
			
	return ret;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>n>>l;
	set<int> s;
	int a=0,b=0,c=0,d=0;//4-4, 7-4, 4-7, 7-7
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		
		if(s.count(temp)) continue;
		else s.insert(temp);
		
		bool gold=true,s_4=true,e_4=true;
		if(temp%10==4) e_4=true;
		else if(temp%10==7) e_4=false;
		else continue;
		 
		while(temp){
			if(temp%10!=4&&temp%10!=7){
				gold=false;break;
			}
			
			if(temp/10==0){
				if(temp==4) s_4=true;
				else if(temp==7) s_4=false;
				else gold=false;
			}
			
			temp/=10;
		}
		
		if(!gold) continue;
		
		if(s_4&&e_4) a++;
		if(!s_4&&e_4) b++;
		if(s_4&&!e_4) c++;
		if(!s_4&&!e_4) d++;
	}
	
	mat p(2,vector<ll>(2,0));
	p[0][0]=a;p[0][1]=b;p[1][0]=c;p[1][1]=d;
	
	mat ans(2,vector<ll>(2,0));
	ans[0][0]=ans[1][1]=1;
	while(l){
		if(l%2) ans=ans*p;
		p=p*p;
		l/=2;
	}
	
	cout<<(ans[0][0]+ans[0][1]+ans[1][0]+ans[1][1])%mod<<'\n';
}
