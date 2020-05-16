#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int n, prime[1000000], sum[1000000];

bool is_prime(int num){
	for(int i=2;i<=sqrt(num);i++){
		if(num%i==0) return false;
	}
	return true;
}

int main(){
	cin>>n;
	int index=1;
	for(int i=2;i<=n;i++){
		if(is_prime(i)){
			prime[index]=i;
			sum[index]=sum[index-1]+prime[index];
			index++;
		}
	}
	
	int ans=0;
	for(int i=1;i<index;i++){
		for(int j=i;j<index;j++){
			if(sum[j]-sum[i-1]>n) break;
			if(sum[j]-sum[i-1]==n) ans++;
		}
	}
	
	cout<<ans<<'\n';
}
