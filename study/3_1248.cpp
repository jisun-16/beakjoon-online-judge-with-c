#include<iostream>
#include<algorithm>

using namespace std;

int n, ans[11], op[11][11];

bool _check(int here){
	int sum=0;
	for(int i=here;i>=0;i--){
		sum+=ans[i];
		if(op[i][here]>0&&sum<=0) return false;
		if(op[i][here]<0&&sum>=0) return false;
		if(op[i][here]==0&&sum!=0) return false;
	}
	return true;
}

bool _solve(int pos){
	if(pos==n){
		return true;
	}
	if(op[pos][pos]=='0') {
		ans[pos]=0;
		return _check(pos)&&_solve(pos+1);
	}
	for(int i=1;i<=10;i++){
		ans[pos]=op[pos][pos]*i;
		if(_check(pos)&&_solve(pos+1)) return true;
	}
	return false;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++) {
			char x;
			cin>>x;
			if(x=='+') op[i][j]=1;
			if(x=='-') op[i][j]=-1;
			if(x=='0') op[i][j]=0;
		}
	}
	_solve(0);
	for(int i=0;i<n;i++) cout<<ans[i]<<' ';
}
