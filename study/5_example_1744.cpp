#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n, arr[10001], ans;

bool cmp(int a, int b){
	return a>b;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	
	sort(arr,arr+n,cmp);
	
	for(int left=0, right=n-1;left<=right;){
		if(left==right){
			ans+=arr[left];
			break;
		}
		
		if(arr[left]>0){
			if(left+1<n&&arr[left]+arr[left+1]<arr[left]*arr[left+1]){
				ans+=arr[left]*arr[left+1];
				left+=2;
			}
			else{
				ans+=arr[left];
				left++;
			}
		}
		else{
			if(right-1>=0&&arr[right]+arr[right-1]<arr[right]*arr[right-1]){
				ans+=arr[right]*arr[right-1];
				right-=2;
			}
			else{
				ans+=arr[right];
				right--;
			}
		}
	}
	
	cout<<ans<<'\n';
}
