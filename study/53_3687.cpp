#include<iostream>
using namespace std;
/*
���ɰ��� ���� �� ��Ÿ�� �� �ִ� ���� 
2�� - 1
3�� - 7
4�� - 4
5�� - 2,3,5
6�� - 6,9,0
7�� - 8
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
