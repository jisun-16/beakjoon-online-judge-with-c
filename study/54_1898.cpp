#include <iostream>
using namespace std;
int n,pos[50001],arr[50001];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		int temp;
		cin>>temp;
		pos[temp]=i;
	}
	arr[pos[n]]=n;
	for(int i=n-1;i;--i){
		if(pos[i]>pos[i+1]){
			arr[pos[i]]=i+1;
			arr[pos[i+1]]=i;
			pos[i]=987654321;
		}
		else arr[pos[i]]=i;
	}
	for(int i=0;i<n;++i) cout<<arr[i]<<'\n';
}
