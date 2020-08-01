#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin>>n;
	int arr[5]={0};
	bool ans=true;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		
		if(temp==1) arr[1]++;
		else if(temp%3==1) arr[4]++;
		else if(temp%3==2) arr[2]++;
	}
	
	while(ans&&(arr[1]||arr[2]||arr[4])){
		while(arr[1]>0){
			arr[1]--;
			if(arr[2]>0) arr[2]--;
			else if(arr[4]>0){
				arr[4]--;
				arr[2]++;
			}
			else {
				ans=false;
				break;
			}
		}
		
		while(arr[2]>0){
			arr[2]--;
			if(arr[1]>0) arr[1]--;
			else if(arr[4]>0) arr[4]--;
			else if(arr[2]>0){
				arr[2]--;
				arr[1]++;
			}
			else{
				ans=false;
				break;
			}
		}
		
		while(arr[4]>0){
			arr[4]--;
			if(arr[1]>0){
				arr[1]--;
				arr[2]++;
			}
			else if(arr[2]>0){
				arr[2]--;
			}
			else if(arr[4]>0){
				arr[4]--;
				arr[2]++;
			}
			else {
				ans=false;
				break;
			}
		}
	}
	
	if(ans) cout<<"YES\n";
	else cout<<"NO\n";
}
