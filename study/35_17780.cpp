#include<cstdio>
#include<deque>

using namespace std;

int n,k,cb[12][12],d[10][3],cnt=0;
int dx[]={0,0,0,-1,1},dy[]={0,1,-1,0,0};
deque<int> h[12][12];

void mov(int idx){
	int x=d[idx][0],y=d[idx][1],dir=d[idx][2];
	//���� �Ʒ��� �ִ� ���� �ƴ� ��� �̵�x 
	if(h[x][y].front()!=idx) return;
	
	int nx=x+dx[dir],ny=y+dy[dir];
	
	//�Ķ�ĭ 
	if(nx<0||nx>=n||ny<0||ny>=n||cb[nx][ny]==2){
		//����ٲ� 
		dir=(dir==1||dir==2)?3-dir:7-dir;
		d[idx][2]=dir;
		nx=x+dx[dir],ny=y+dy[dir];
				
		//����ĭ�� �Ķ�ĭ�� ��� �̵����� �ʴ´� 
		if(nx<0||nx>=n||ny<0||ny>n||cb[nx][ny]==2) return;
		else mov(idx);
	}
	//����ĭ 
	else if(cb[nx][ny]==1){				
		while(!h[x][y].empty()){
			int temp=h[x][y].back();
			h[x][y].pop_back();
			d[temp][0]=nx,d[temp][1]=ny;
			h[nx][ny].push_back(temp);
			if(h[nx][ny].size()>=4) return;
		}
	}
	//��ĭ 
	else{
		while(!h[x][y].empty()){
			int temp=h[x][y].front();
			h[x][y].pop_front();
			d[temp][0]=nx,d[temp][1]=ny;
			h[nx][ny].push_back(temp);
			if(h[nx][ny].size()>=4) return;
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j) scanf("%d",&cb[i][j]);
	for(int i=0;i<k;++i){
		//���� x��ǥ,y��ǥ,���� 
		scanf("%d %d %d",&d[i][0],&d[i][1],&d[i][2]);
		h[--d[i][0]][--d[i][1]].push_back(i);
	}
	
	while(++cnt<=1000){
		//���� ���ʷ� �̵��Ѵ� 
		for(int i=0;i<k;++i) mov(i);
		
		//4�� �̻��� ���� �ִ� ĭ�� ���� ��� ���� 
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				if(h[i][j].size()>=4){
					printf("%d\n",cnt);
					return 0;
				}
	}
	
	printf("-1\n");
}

