#include<cstdio>
#include<queue>
using namespace std;
int main(){
	int N;
	queue<int> q;
	scanf("%d",&N);
	for(int i=1;i<=N;++i) q.push(i);
	while(true){
		int temp=q.front();
		q.pop();
		if(q.empty()){
			printf("%d\n",temp);
			break;
		}
		temp=q.front();
		q.pop();
		q.push(temp);
	}
}
