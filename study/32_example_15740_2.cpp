#include<iostream>
#include<string>

using namespace std;

string a,b;
int A[10001],B[10001],ans[10005];
bool am,bm;
int al,bl;

int main(){
	cin>>a>>b;
	if(a.length()-(a[0]=='-')<b.length()-(b[0]=='-')){
		string temp=a;
		a=b;
		b=temp;
	}
	else if(a.length()-(a[0]=='-')==b.length()-(b[0]=='-')){
		int aa=(a[0]=='-'),bb=(b[0]=='-');
		for(int i=0;i<a.length()-(a[0]=='-');i++){
			if(a[aa+i]<b[bb+i]){
				string temp=a;
				a=b;
				b=temp;
				break;
			}
			else if(a[aa+i]>b[bb+i]) break;
		}
	}
	//a가 절대값이 더 크도록 
	
	if(a[0]=='-') am=true;
	if(b[0]=='-') bm=true;
	
	al=a.length()-am;
	bl=b.length()-bm;
	for(int i=al+am-1,idx=0;i>=am;i--,idx++) A[idx]=a[i]-'0';
	for(int i=bl+bm-1,idx=0;i>=bm;i--,idx++) B[idx]=b[i]-'0';
	
	int idx=0,t=0;
	while(al>0||bl>0){
		if(am==bm){//a+b
			int temp=A[idx]+B[idx]+t;
			t=temp/10;
			ans[idx]=temp%10; 
		}
		else{//a-b
			int temp=A[idx]-B[idx]+t;
			
			if(temp%10==0){
				t=temp/10;
				ans[idx]=0;
			}
			else if(temp<0){
				t=temp/10-1;
				ans[idx]=-t*10+temp;
			}
			else{
				t=0;
				ans[idx]=temp;
			}
		}
		
		idx++;
		al--;bl--;
	}
	if(t>0) ans[idx++]=t;
	if(t<0) ans[idx++]=-t;
	
	bool chk=true;
	for(int i=0;i<idx;i++)
		if(ans[i]!=0){
			chk=false;break;
		}
		
	if(chk) printf("0");
	else{
		if(am) printf("-");
		for(int i=idx-1;i>=0;i--) {
			if(!chk&&ans[i]==0) continue;
			chk=true;
			printf("%d",ans[i]);
		}
	}
}
