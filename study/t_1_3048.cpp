#include<iostream>
#include<algorithm>
using namespace std;
int n1,n2,t,ord[26];
char arr[2][26],ans[26];
bool gone[26];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n1>>n2;
	cin>>arr[0]>>arr[1];
	cin>>t;
	for(int i=0;i<n1;++i){
		gone[arr[0][i]-'A']=true;
		ord[arr[0][i]-'A']=n1-1-i;
		ans[n1-1-i]=arr[0][i];
	}
	for(int i=0;i<n2;++i){
		ord[arr[1][i]-'A']=n1+i;
		ans[n1+i]=arr[1][i];
	}
	while(t--){
		for(int i=0;i<n1+n2-1;++i){
			if(!gone[ans[i]-'A']||gone[ans[i+1]-'A']) continue;
			int temp=ord[ans[i]-'A'];
			ord[ans[i]-'A']=ord[ans[i+1]-'A'];
			ord[ans[i+1]-'A']=temp;
			char temp2=ans[i];
			ans[i]=ans[i+1];
			ans[i+1]=temp2;
			i++;
		}
	}
	for(int i=0;i<n1+n2;++i)
		cout<<ans[i];
}
