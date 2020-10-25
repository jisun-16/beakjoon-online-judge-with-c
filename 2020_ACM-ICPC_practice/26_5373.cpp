#include<iostream>
#include<string>

using namespace std;

char c[6][9],color[6]={'w','y','r','o','g','b'};//u d f b l r

void _turn(char side){
	int s;
	if(side=='U'){
		s=0;
		char temp[3]={c[3][0],c[3][1],c[3][2]};
		int chg[4]={3,4,2,5};
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++) c[chg[i]][j]=c[chg[i+1]][j];
		for(int i=0;i<3;i++) c[chg[3]][i]=temp[i];
	}
	else if(side=='D'){
		s=1;
		char temp[3]={c[3][6],c[3][7],c[3][8]};
		int chg[4]={3,5,2,4};
		for(int i=0;i<3;i++)
			for(int j=6;j<9;j++) c[chg[i]][j]=c[chg[i+1]][j];
		for(int i=6;i<9;i++) c[chg[3]][i]=temp[i-6];
	}
	else if(side=='F'){
		s=2;
		char temp[3]={c[0][6],c[0][7],c[0][8]};
		c[0][6]=c[4][8];c[0][7]=c[4][5];c[0][8]=c[4][2];
		c[4][2]=c[1][8];c[4][5]=c[1][7];c[4][8]=c[1][6];
		c[1][6]=c[5][0];c[1][7]=c[5][3];c[1][8]=c[5][6];
		c[5][0]=temp[0];c[5][3]=temp[1];c[5][6]=temp[2];
	}
	else if(side=='B'){
		s=3;
		char temp[3]={c[0][2],c[0][1],c[0][0]};
		c[0][2]=c[5][8];c[0][1]=c[5][5];c[0][0]=c[5][2];
		c[5][8]=c[1][2];c[5][5]=c[1][1];c[5][2]=c[1][0];
		c[1][2]=c[4][0];c[1][1]=c[4][3];c[1][0]=c[4][6];
		c[4][0]=temp[0];c[4][3]=temp[1];c[4][6]=temp[2];
	}
	else if(side=='L'){
		s=4;
		char temp[3]={c[0][0],c[0][3],c[0][6]};
		c[0][0]=c[3][8];c[0][3]=c[3][5];c[0][6]=c[3][2];
		c[3][8]=c[1][8];c[3][5]=c[1][5];c[3][2]=c[1][2];
		c[1][8]=c[2][0];c[1][5]=c[2][3];c[1][2]=c[2][6];
		c[2][0]=temp[0];c[2][3]=temp[1];c[2][6]=temp[2];
	}
	else{
		s=5;
		char temp[3]={c[0][8],c[0][5],c[0][2]};
		c[0][8]=c[2][8];c[0][5]=c[2][5];c[0][2]=c[2][2];
		c[2][8]=c[1][0];c[2][5]=c[1][3];c[2][2]=c[1][6];
		c[1][0]=c[3][0];c[1][3]=c[3][3];c[1][6]=c[3][6];
		c[3][0]=temp[0];c[3][3]=temp[1];c[3][6]=temp[2];
	}
	
	char temp[9];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			temp[i*3+j]=c[s][(2-j)*3+i];
	for(int i=0;i<9;i++)
		c[s][i]=temp[i];	
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--){
		for(int i=0;i<6;i++)
			for(int j=0;j<9;j++)
				c[i][j]=color[i];
		
		int n;
		cin>>n;
		
		while(n--){
			string temp;
			cin>>temp;
			_turn(temp[0]);
			if(temp[1]=='-'){
				_turn(temp[0]);
				_turn(temp[0]);
			}
		}
		
		for(int i=0;i<9;i++){
			cout<<c[0][i];
			if(i%3==2) cout<<'\n';
		}
	}
}
