#include<cstdio>
#include<vector>

using namespace std;

int n,x[200000],r[200000];
double ans[200000];
vector<int> v;

double min(double a,double b){
	if(a<b) return a;
	else return b;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&x[i],&r[i]);
	
	ans[0]=r[0];
	v.push_back(0);
	for(int i=1;i<n;i++){
		ans[i]=r[i];
		
		while(!v.empty()){
			//r[i]보다 반지름이 작은 풍선 전부 제거 
			int j=v.back();
			ans[i]=min(ans[i],(0.25*(x[i]-x[j])*(x[i]-x[j]))/ans[j]);
			
			if(ans[j]-1e-5<ans[i]) v.pop_back();
			else break;
		}
		
		v.push_back(i);
	}
	
	for(int i=0;i<n;i++) printf("%.5f\n",ans[i]);
}
