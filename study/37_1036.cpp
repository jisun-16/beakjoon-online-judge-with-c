#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n,k,gt[36];
string num[50],digit[36];
bool zee[36];

string sum(string A,string B){
	int i=A.length(),j=B.length();
	int up=0;
	string T;
	
	while(i&&j){
		--i;--j;
		
		int a=A[i]>='A'?A[i]-'A'+10:A[i]-'0';
		int b=B[j]>='A'?B[j]-'A'+10:B[j]-'0';
		int temp;
		
		if(a+b+up>=36){
			temp=(a+b+up)%36;
			up=(a+b+up)/36;
		}
		else{
			temp=a+b+up;
			up=0;
		}
		
		if(temp<10)
			T=(char)(temp+'0')+T;
		else
			T=(char)(temp-10+'A')+T;
	}
	while(i--){
		int temp=A[i]>='A'?A[i]-'A'+10:A[i]-'0';
		
		if(temp+up<36){
			temp=temp+up;
			up=0;
		}
		else{
			int temp2=temp+up;
			temp=temp2%36;
			up=temp2/36;
		}
		
		if(temp<10)
			T=(char)(temp+'0')+T;
		else
			T=(char)(temp-10+'A')+T;
	}
	while(j--){
		int temp=B[j]>='A'?B[j]-'A'+10:B[j]-'0';
		
		if(temp+up<36){
			temp=temp+up;
			up=0;
		}
		else{
			int temp2=temp+up;
			temp=temp2%36;
			up=temp2/36;
		}
		
		if(temp<10)
			T=(char)(temp+'0')+T;
		else
			T=(char)(temp-10+'A')+T;
	}
	while(up){
		int temp=up%36;
		up/=36;
		char u=temp<10?(char)(temp+'0'):(char)(temp-10+'A');
		T=u+T;
	}
	
	return T;
}

bool cmp(int a,int b){
	string A=digit[a],B=digit[b];
	
	if(A.length()>B.length()) return true;
	else if(A.length()<B.length()) return false;
	else{
		int l=A.length(),i=0;
		while(i++<l-1){
			int x=A[i]>='A'?A[i]-'A'+10:A[i]-'0';
			int y=B[i]>='A'?B[i]-'A'+10:B[i]-'0';
			
			if(x>y) return true;
			else if(x<y) return false;
		}
		return false;
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	for(int i=0;i<36;++i) gt[i]=i;
	
	cin>>n;
	for(int i=0;i<n;++i) cin>>num[i];
	cin>>k;
	
	for(int i=0;i<n;++i){
		string z;
		for(int j=num[i].length()-1;j>=0;--j){
			if(num[i][j]!='Z'){
				int idx=num[i][j]>='A'?num[i][j]-'A'+10:num[i][j]-'0';
				char diff=35-idx<10?(char)(35-idx+'0'):(char)(35-idx-10+'A');
				digit[idx]=sum(digit[idx],diff+z);
			}
			z=z+'0';
		}
	}
	
	sort(gt,gt+36,cmp);
	
	for(int i=0;i<k;++i) zee[gt[i]]=true;
	for(int i=0;i<n;++i)
		for(int j=0;j<num[i].length();++j){
			int idx=num[i][j]>='A'?num[i][j]-'A'+10:num[i][j]-'0';
			if(zee[idx]) num[i][j]='Z';
		}
	
	for(int i=0;i<n;i++) cout<<num[i]<<'\n';
	
	string ans;
	for(int i=0;i<n;++i) ans=sum(ans,num[i]);
	
	cout<<ans<<'\n';
}
