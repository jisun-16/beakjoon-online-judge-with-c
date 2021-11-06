#include<iostream>
#include<algorithm>

using namespace std;

int n, arr[12], op[4], choose[11], ans;//1=+ 2=- 3=* 4=/
int mn=1000000000, mx=-1000000000;
bool visited[11];

void _calc(int cnt){
	if(cnt==n-1){
		int sum=arr[0];
		for(int i=1;i<n;i++){
			if(choose[i-1]==1) sum+=arr[i];
			if(choose[i-1]==2) sum-=arr[i];
			if(choose[i-1]==3) sum*=arr[i];
			if(choose[i-1]==4) sum/=arr[i];
		}
		mn=min(mn,sum);
		mx=max(mx,sum);
		return;
	}
	
	for(int i=0;i<4;i++){
		if(op[i]){
			choose[cnt]=i+1;
			op[i]--;
			_calc(cnt+1);
			op[i]++;
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	int x=0;
	for(int i=0;i<4;i++) cin>>op[i];
	
	_calc(0);
	
	cout<<mx<<'\n';
	cout<<mn<<'\n';
	
	return 0;
}
