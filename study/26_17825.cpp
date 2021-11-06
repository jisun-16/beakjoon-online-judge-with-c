#include<iostream>
#include<algorithm>

using namespace std;

int num[10],pos[4],map[41],map_blue[41],ans;
bool blue[4];

bool mov(int idx,int dice){
	int now=pos[idx];
	int next=now;
	
	if(now==10||now==20||now==30||blue[idx]){
		if(now==30&&!blue[idx]){
			next=28;
			dice--;
		}
		blue[idx]=true;
		for(int i=0;i<dice;i++){
			if(next>40) break;
			next=map_blue[next];
		}
	}
	else {
		for(int i=0;i<dice;i++){
			if(next>40) break;
			next=map[next];
		}
	}
	
	//도착지점에 다른 말이 있는지 확인하기 
	for(int i=0;i<4;i++){
		if(i==idx) continue;
		if(pos[i]==next&&next<=40)
			if(blue[idx]==blue[i]||next==40) 
				return false;
	}
	
	//겹치지 않을 경우 말 이동시키고 return 
	pos[idx]=next;
	return true;
}

void _dfs(int cnt, int res){
	if(cnt==10){
		ans=max(ans,res);
		return;
	}
	
	for(int i=0;i<4;i++){
		//이미 도착한 말일 경우 
		if(pos[i]>40) _dfs(cnt+1,res); 
		else{
			int pp=pos[i];
			bool bb=blue[i];
			
			bool chk=mov(i,num[cnt]);
			if(chk){
				if(pos[i]<=40) _dfs(cnt+1,res+pos[i]);
				else _dfs(cnt+1,res);
			}
			
			pos[i]=pp;
			blue[i]=bb;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	for(int i=0;i<10;i++) cin>>num[i];
	
	for(int i=0;i<40;i+=2) map[i]=i+2;
	map[40]=41;
	
	for(int i=10;i<19;i+=3) map_blue[i]=i+3;
	map_blue[19]=25;
	for(int i=20;i<24;i+=2) map_blue[i]=i+2;
	map_blue[24]=25;
	for(int i=28;i>=26;i--) map_blue[i]=i-1;
	for(int i=25;i<40;i+=5) map_blue[i]=i+5;
	map_blue[40]=41;
	
	_dfs(0,0);
	
	cout<<ans<<'\n';
}
