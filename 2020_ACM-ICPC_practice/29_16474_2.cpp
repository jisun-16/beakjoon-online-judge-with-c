#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n,m,k;
int l[2000],r[2000];
vector<int> adj[2000],ans;

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int idx;
		scanf("%d",&idx);
		l[idx-1]=i;
	}
	for(int i=0;i<m;i++){
		int idx;
		scanf("%d",&idx);
		r[idx-1]=i;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[l[a-1]].push_back(r[b-1]);
	}
	
	for(int i=0;i<n;i++){
		sort(adj[i].rbegin(),adj[i].rend());
		for(int y=0;y<adj[i].size();y++){
			int j=adj[i][y];
			if(ans.empty()||ans.back()<j)
				ans.push_back(j);
			else{
				vector<int>::iterator it=lower_bound(ans.begin(),ans.end(),j);
				*it=j;
			}
		}
	}
	
	printf("%d\n",k-ans.size());
}
