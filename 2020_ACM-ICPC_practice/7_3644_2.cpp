#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
string fibo[10001];

void _sum(string& res, string a, string b){
	int tt=0, i=0;
	
	if(a.size()<b.size()) 
		a=a+'0';
	res=a;
	
	while(i<a.size()){
		tt+=(a[i]-'0')+(b[i]-'0');
		res[i]=(tt%10)+'0';
		tt=tt/10;
		i++;
	}
	
	if(tt)
		res=res+(char)(tt+'0');
}

int main(){
	fibo[3]="4";
	fibo[4]="7";
	for(int i=5;i<=10000;i++){
		_sum(fibo[i],fibo[i-2],fibo[i-1]);
	}
	
	while(~scanf("%d",&n)){
		reverse(fibo[n].begin(),fibo[n].end());
		cout<<fibo[n]<<'\n';
		reverse(fibo[n].begin(),fibo[n].end());
	}
}
