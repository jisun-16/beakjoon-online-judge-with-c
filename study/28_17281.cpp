#include<iostream>
#include<algorithm>

#define swap(a,b,temp) temp=a;a=b;b=temp;

using namespace std;

int n,hitter[50][9],ans;
int temp,ord[9],base[3];

int calc(){
	int score=0,now=0;
	for(int in=0;in<n;in++){
		int o=0;
		base[0]=base[1]=base[2]=-1;
		while(o<3){
			switch(hitter[in][ord[now]]){
				case 0:{
					o++;
					break;
				}
				case 1:{
					score+=(base[2]!=-1)?1:0;
					base[2]=base[1];
					base[1]=base[0];
					base[0]=ord[now];
					break;
				}
				case 2:{
					score+=(base[1]!=-1)?1:0;
					score+=(base[2]!=-1)?1:0;
					base[2]=base[0];
					base[1]=ord[now];
					base[0]=-1;
					break;
				}
				case 3:{
					score+=(base[0]!=-1)?1:0;
					score+=(base[1]!=-1)?1:0;
					score+=(base[2]!=-1)?1:0;
					base[2]=ord[now];
					base[1]=base[0]=-1;
					break;
				}
				case 4:{
					score++;
					score+=(base[0]!=-1)?1:0;
					score+=(base[1]!=-1)?1:0;
					score+=(base[2]!=-1)?1:0;
					base[0]=base[1]=base[2]=-1;
					break;
				}
			}
			now=(now+1)%9;
		}
	}
	return score;
}

void permutaion(int s,int e){
	if(s==e){
		if(ord[3]!=0) return;
		
		int c=calc();
		ans=max(ans,c);
		
		return;
	}
	
	for(int i=s;i<=e;i++){
		swap(ord[s],ord[i],temp);
		permutaion(s+1,e);
		swap(ord[s],ord[i],temp);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<9;j++)
			scanf("%d",&hitter[i][j]);
	
	for(int i=0;i<9;i++)
		ord[i]=i;
	permutaion(0,8);
	
	printf("%d\n",ans);
}
