#include<iostream>
using namespace std;
int n,stu;
bool swi[101];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>swi[i];
	cin>>stu;
	while(stu--){
		int gen,idx;
		cin>>gen>>idx;
		if(gen==1){
			int i=1;
			while(idx*i<=n){
				swi[idx*i]=!swi[idx*i];
				++i;
			}
		}
		else{
			int i=0;
			while(idx-i>0&&idx+i<=n&&swi[idx-i]==swi[idx+i]) i++;
			--i;
			for(int j=idx-i;j<=idx+i;++j)
				swi[j]=!swi[j];
		}
	}
	for(int i=1;i<=n;++i){
        cout<<(swi[i]?1:0)<<' ';
        if(i%20==0) cout<<'\n';
    }
}
