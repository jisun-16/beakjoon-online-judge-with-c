#include<iostream>
#include<algorithm>

using namespace std;

int n, score[10001];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>score[i];
	}
	
	sort(score,score+n);
	
	bool avail=true;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=score[i];
		if(sum<i*(i+1)/2){
			avail=false;
			break;
		}
	}
	if(sum!=n*(n-1)/2) avail=false;
	
	if(avail) cout<<1<<'\n';
	else cout<<-1<<'\n';
}
