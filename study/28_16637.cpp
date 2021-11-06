#include<iostream>
#include<vector>

using namespace std;

int n, num[10],ans;
char op[10];
bool chk[10];

void dfs(int idx){
	if(idx>=n/2){
		vector<int> nn;
		vector<char> oo;
		int calc=0;
		
		for(int i=0;i<n;i++){
			if(i%2==0){
				nn.push_back(num[i/2]);
			}
			else{
				if(chk[i/2]){
					nn.pop_back();
					int temp=num[i/2];
					switch(op[i/2]){
						case '+':{
							temp+=num[i/2+1];
							break;
						}
						case '-':{
							temp-=num[i/2+1];
							break;
						}
						case '*':{
							temp*=num[i/2+1];
							break;
						}
					}
					nn.push_back(temp);
					i++;
				}
				else{
					oo.push_back(op[i/2]);
				}
			}
		}
		
		calc+=nn[0];
		for(int i=0;i<oo.size();i++){
			switch(oo[i]){
				case '+':{
					calc+=nn[i+1];
					break;
				}
				case '-':{
					calc-=nn[i+1];
					break;
				}
				case '*':{
					calc*=nn[i+1];
					break;
				}
			}
		}
		
		if(ans<calc) ans=calc;
		return;
	}
	
	for(int i=idx;i<n/2;i++){
		dfs(i+1);
		chk[i]=true;
		dfs(i+2);
		chk[i]=false;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if(i%2==0)
			scanf("%1d",&num[i/2]);
		else
			scanf("%1c",&op[i/2]);
	}
	
	ans=num[0];
	for(int i=0;i<n/2;i++){
		if(op[i]=='+')
			ans+=num[i+1];
		else if(op[i]=='-')
			ans-=num[i+1];
		else if(op[i]=='*')
			ans*=num[i+1];
	}
	
	dfs(0);
	
	printf("%d\n",ans);
}
