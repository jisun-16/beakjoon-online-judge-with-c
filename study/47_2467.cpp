#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n, arr[100000];
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	int l=0,r=n-1,a=arr[0],b=arr[n-1];
	int sum=a+b;
	while(l<r-1){
		if(arr[l]+arr[r]<0) l++;
		else if(arr[l]+arr[r]>0) r--;
		else break;
		if(abs(sum)>abs(arr[l]+arr[r])){
			sum=arr[l]+arr[r];
			a=arr[l],b=arr[r];
		}
	}
	cout<<a<<" "<<b<<'\n';
}
