#include<iostream>
using namespace std;
/*
성냥개비 개수 별 나타낼 수 있는 숫자 
2개 - 1
3개 - 7
4개 - 4
5개 - 2,3,5
6개 - 6,9,0
7개 - 8
*/ 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string mn="",mx="";
		cin>>n;
		for(int i=n;i>0;i-=2){
			if(i==3){
				mx="7"+mx;
				break;
			}
			else mx+="1";
		}
		for(int i=n;i>0;i-=7){
			if(i==2) mn="1"+mn;
			else if(i==3) mn="7"+mn;
			else if(i==4) mn="4"+mn;
			else if(i==5) mn="2"+mn;
			else if(i==6) mn="6"+mn;
			else if(i==8) mn="10"+mn,i=0;
			else if(i==10) mn="22"+mn,i=0;
			else if(i==11) mn="20"+mn,i=0;
			else if(i==17) mn="200"+mn,i=0;
			else mn+="8";
		}
		cout<<mn<<" "<<mx<<'\n';
	}
}
