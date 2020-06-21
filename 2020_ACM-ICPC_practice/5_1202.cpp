#include<iostream>
#include<algorithm>
#include<queue>

#define pii pair<int,int> 
using namespace std;

int n,k,c[300000];
pii jewelry[300000];
long long ans;

bool cmp(pii a, pii b){
	return a.first<b.first;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>k;
	
	for(int i=0;i<n;i++){
		cin>>jewelry[i].first>>jewelry[i].second;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
	}
	
	sort(jewelry,jewelry+n,cmp);
	sort(c,c+k);
	
	priority_queue<int> pq;
	int index=0;
	for(int i=0;i<k;i++){
		while(index<n&&jewelry[index].first<=c[i]){
			pq.push(jewelry[index].second);
			index++;
		}
		
		if(!pq.empty()){
			ans+=pq.top();
			pq.pop();
		}
	}//가능한 보석 중 가장 가치가 높은것 담기 
	
	cout<<ans<<'\n';
}
