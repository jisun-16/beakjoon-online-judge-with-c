#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int t,n,m;
bool visited[1001];

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second<b.second) return true;
	else if(a.second==b.second) return a.first<b.first;
	else return false;
}

int main(){
	
	cin>>t;
	while(t--){	
		pair<int, int> stu[1001];
		int ans=0;
		
		memset(visited,false,sizeof(visited));
		cin>>n>>m;
		for(int i=0;i<m;i++)
			cin>>stu[i].first>>stu[i].second;
		
		sort(stu,stu+m,cmp);
		
		for(int i=0;i<m;i++){
			for(int j=stu[i].first;j<=stu[i].second;j++){
				if(!visited[j]){
					visited[j]=true;
					ans++;
					break;
				}
			}
		}
		
		cout<<ans<<'\n';
	}
}
