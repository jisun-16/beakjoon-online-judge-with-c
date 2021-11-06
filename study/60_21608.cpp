#include<iostream>
using namespace std;
int n,m,arr[20][20],fav[401][4],sum;
void find_seat(int now){
	int mf=0,mb=0,mx=20,my=20;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			if(arr[i][j]) continue;
			int f=0,b=0,x=i,y=j;
			for(int k=0;k<4;++k){
				if(i>0&&arr[i-1][j]==fav[now][k]) ++f;
				if(i<n-1&&arr[i+1][j]==fav[now][k]) ++f;
				if(j>0&&arr[i][j-1]==fav[now][k]) ++f;
				if(j<n-1&&arr[i][j+1]==fav[now][k]) ++f;
			}
			if(i>0&&arr[i-1][j]==0) ++b;
			if(j>0&&arr[i][j-1]==0) ++b;
			if(i<n-1&&arr[i+1][j]==0) ++b;
			if(j<n-1&&arr[i][j+1]==0) ++b;
			if(mf<f||(mf==f&&mb<b)||(mf==f&&mb==b&&mx>x)||(mf==f&&mb==b&&mx==x&&my>y))
				mf=f,mb=b,mx=x,my=y;
		}
	arr[mx][my]=now;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n*n;++i){
		int num;
		cin>>num;
		for(int j=0;j<4;++j)
			cin>>fav[num][j];
		find_seat(num);
	}
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			int now=arr[i][j],chk=0;
			for(int k=0;k<4;++k){
				if(i>0&&arr[i-1][j]==fav[now][k]) ++chk;
				if(i<n-1&&arr[i+1][j]==fav[now][k]) ++chk;
				if(j>0&&arr[i][j-1]==fav[now][k]) ++chk;
				if(j<n-1&&arr[i][j+1]==fav[now][k]) ++chk;
			}
			if(chk==0) sum+=0;
			else if(chk==1) sum+=1;
			else if(chk==2) sum+=10;
			else if(chk==3) sum+=100;
			else sum+=1000;
		}
	cout<<sum<<'\n';
}
