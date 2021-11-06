#include<iostream>
#include<algorithm>

using namespace std;

int n, ans;
bool coin[20][20], r_flip[20];

void _solve(int rr){
	if(rr==n){
		int temp=0;
		for(int j=0;j<n;j++){
			int temp2=0;
			for(int i=0;i<n;i++){
				if(coin[i][j]&&r_flip[i]) temp2++;
				if(!coin[i][j]&&!r_flip[i]) temp2++;
			}
			temp+=min(temp2,n-temp2);
		}
		ans=min(ans,temp);
		return;
	}
	
	_solve(rr+1);
	r_flip[rr]=true;
	_solve(rr+1);
	r_flip[rr]=false;
}//row를 먼저 뒤집고 마지막에 col뒤집은거 계산 

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char temp;
			cin>>temp;
			if(temp=='H') coin[i][j]=true;
			else {
				coin[i][j]=false;
				ans++;
			}
		}
	}
	
	_solve(0);
	
	cout<<ans<<'\n';
}
