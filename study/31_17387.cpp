#include<cstdio>
#include<algorithm>

#define pll pair<long long, long long>
#define f first
#define s second

using namespace std;

pll p1,p2,p3,p4;

int sol(pll a,pll b,pll c){
	long long ret=(a.s-b.s)*(c.f-a.f)-(a.f-b.f)*(c.s-a.s);
	if(ret<0) return -1;
	else if(ret==0) return 0;
	else return 1;
}

int main(){
	scanf("%lld %lld %lld %lld",&p1.f,&p1.s,&p2.f,&p2.s);
	scanf("%lld %lld %lld %lld",&p3.f,&p3.s,&p4.f,&p4.s);
	
	if(p1>p2) swap(p1,p2);
	if(p3>p4) swap(p3,p4);
	
	int chk=sol(p1,p2,p3)*sol(p1,p2,p4);
	int chk2=sol(p3,p4,p1)*sol(p3,p4,p2);
	
	bool ans=(chk<=0&&chk2<=0);
	
	if(chk==0&&chk2==0){
		if(p1<=p4&&p2>=p3) ans=true;
		else ans=false;
	}
	
	if(ans) printf("1\n");
	else printf("0\n");
}
