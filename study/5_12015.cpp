#include<iostream>
#include<algorithm>
#include<vector>
#define Max 987654321

using namespace std;

int n;
vector<int> arr;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	arr.push_back(Max);
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(arr.back()<temp){
			arr.push_back(temp);
		}
		else{
			*lower_bound(arr.begin(),arr.end(),temp)=temp;
		}
	}
	
	cout<<arr.size()<<'\n';
}
