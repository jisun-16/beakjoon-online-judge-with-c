#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, p_num;
vector<int> ans;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>p_num;
		
		if(ans.empty()||ans.back()<p_num) 
			ans.push_back(p_num);
		else{
			vector<int>::iterator temp=lower_bound(ans.begin(),ans.end(),p_num);
			*temp=p_num;
		}
	}
	
	cout<<ans.size()<<'\n';
}
