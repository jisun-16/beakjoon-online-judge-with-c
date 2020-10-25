#include<cstdio>
#include<algorithm>

using namespace std;

int t,n;
int cnt[6],arr[10001];

int main(){
	scanf("%d",&t);
	
	cnt[0]=10000;
	int cycle=0,chk=0;
	for(int i=1;i<=10000;i++){
		if(chk>cycle*6){
			chk=1;
			cycle++;
		}
		
		bool nei[6]={0,};
		if(i<=5) arr[i]=i;
		else{
			if(chk==1){
				nei[arr[i-1]]=true;
				nei[arr[i-(cycle-1)*6]]=true;
			}
			else if(chk==cycle*6){
				nei[arr[i-1]]=true;
				nei[arr[i-cycle*6]]=true;
				nei[arr[i-cycle*6+1]]=true;
			}
			else if(chk%cycle==0){
				nei[arr[i-1]]=true;
				nei[arr[i-chk-(cycle-1)*6+(chk/cycle)*(cycle-1)]]=true;
			}
			else{
				nei[arr[i-1]]=true;
				nei[arr[i-chk-(cycle-1)*6+(chk/cycle)*(cycle-1)+chk%cycle]]=true;
				nei[arr[i-chk-(cycle-1)*6+(chk/cycle)*(cycle-1)+chk%cycle-1]]=true;
			}
			
			arr[i]=0;
			for(int j=1;j<=5;j++){
				if(nei[j]) continue;
				if(cnt[arr[i]]>cnt[j]) arr[i]=j;
			}
		}
		
		chk++;
		cnt[arr[i]]++;
	}
	
	while(t--){
		scanf("%d",&n);
		printf("%d\n",arr[n]);
	}
}
