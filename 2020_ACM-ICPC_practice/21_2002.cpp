#include<iostream>
#include<string>

using namespace std;

int n,in_out[1001][2],ans;
string num[1001];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num[i];
		in_out[i][0]=i;
	}
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		for(int j=0;j<n;j++)
			if(temp==num[j]){
				in_out[i][1]=j;
				break;
			}
	}
	
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(in_out[i][1]>in_out[j][1]){
				ans++;
				break;
			}
	
	cout<<ans<<'\n';
}
