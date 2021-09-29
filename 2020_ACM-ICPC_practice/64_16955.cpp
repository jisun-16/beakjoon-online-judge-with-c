#include<iostream>
#include<algorithm>
using namespace std;
char arr[10][12];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i=0;i<10;++i) cin>>arr[i];
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			if(arr[i][j]!='.') continue;
			arr[i][j]='X';
			for(int r=0;r<10;++r)
				for(int c=0;c<10;++c){
					bool chk=false;
					int l=0;
					while(r+l<10&&arr[r+l][c]=='X') l++;
					if(l>=5){
						cout<<1;
						return 0;
					}
					l=0;
					while(c+l<10&&arr[r][c+l]=='X') l++;
					if(l>=5){
						cout<<1;
						return 0;
					}
					l=0;
					while(r+l<10&&c+l<10&&arr[r+l][c+l]=='X') l++;
					if(l>=5){
						cout<<1;
						return 0;
					}
					l=0;
					while(r+l<10&&c-l>=0&&arr[r+l][c-l]=='X') l++;
					if(l>=5){
						cout<<1;
						return 0;
					}
				}
			arr[i][j]='.';
		}
	}
	cout<<0;
}
