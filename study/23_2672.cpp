#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int n;
double sq[30][4],xx[61],yy[61],ans;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin>>n;
	int cnt1=0,cnt2=0;
	for(int i=0;i<n;i++){
		cin>>sq[i][0]>>sq[i][1]>>sq[i][2]>>sq[i][3];
		sq[i][2]+=sq[i][0];sq[i][3]+=sq[i][1];
		
		xx[cnt1++]=sq[i][0];
		xx[cnt1++]=sq[i][2];
		yy[cnt2++]=sq[i][1];
		yy[cnt2++]=sq[i][3];
	}
	
	sort(xx,xx+cnt1);
	sort(yy,yy+cnt2);
	
	for(int i=1;i<cnt1;i++){
		for(int j=1;j<cnt2;j++){
			double x1=xx[i-1],x2=xx[i];
			double y1=yy[j-1],y2=yy[j];
			
			bool chk=false;
			for(int k=0;k<n;k++)
				if(x1>=sq[k][0]&&x2<=sq[k][2])
					if(y1>=sq[k][1]&&y2<=sq[k][3]){
						chk=true;
						break;
					}
			
			if(chk) ans+=(x2-x1)*(y2-y1);
		}
	}
	
	if((long long)ans==ans) printf("%lld\n",(long long)ans);
	else printf("%.2lf",ans);
}
