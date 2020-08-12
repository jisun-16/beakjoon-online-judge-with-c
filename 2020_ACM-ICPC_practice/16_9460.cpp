#include<iostream>
#include<algorithm>

using namespace std;

const int Max=100000000,Min=-100000000;

int T, N, K;
pair<int,int> coor[10001];

int _chk(int x){
	int k=1;
	int M=coor[0].second,m=coor[0].second;
	for(int i=1;i<N;i++){
		if(M<coor[i].second) M=coor[i].second;
		if(m>coor[i].second) m=coor[i].second;
		
		if(M-m>x){
			k++;
			M=coor[i].second;
			m=coor[i].second;
		}
	}
	
	return k;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	cin>>T;
	while(T--){
		cin>>N>>K;
		for(int i=0;i<N;i++)
			cin>>coor[i].first>>coor[i].second;
			
		sort(coor,coor+N);
	
		int s=0,e=2*Max;
		while(s<e){
			int mid=(s+e)/2;
			int chk=_chk(mid);
			
			if(chk<=K) e=mid;
			else s=mid+1;
		}
		
		cout<<e/2.0<<'\n';
	}
}
