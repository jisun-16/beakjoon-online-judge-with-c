#include<cstdio>
#include<cstring>
int n,k,cnt[55][36],alp[36];
char ans[55];
inline int ctoi(char c){return c<='9'?c-48:c-55;}
inline char itoc(int i){return i<=9?i+48:i+55;}
inline double pow(int n,int r){
	double ret=1;
	while(r--) ret*=n;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		char str[51];
		scanf(" %s",&str);
		for(int l=strlen(str)-1,t=0;l>=0;--l,++t)
			++cnt[t][ctoi(str[l])];
	}
	scanf("%d",&k);
	while(k--){
		int idx=-1;
		double val,max=0;
		for(int i=0;i<35;++i){
			if(alp[i]) continue;
			val=0;
			for(int t=0;t<55;++t)
				val+=cnt[t][i]*(35-i)*pow(36,t);
			if(max<val) idx=i,max=val;
		}
		if(idx>=0){
			alp[idx]=1;
			for(int i=0;i<50;++i)
				cnt[i][35]+=cnt[i][idx],cnt[i][idx]=0;
		}
		else break;
	}
	int sum;
	for(int i=0;i<55;++i){
		sum=0;
		for(int j=0;j<36;++j) sum+=j*cnt[i][j];
		ans[i+1]=(ans[i]+sum)/36;
		ans[i]=itoc((ans[i]+sum)%36);
	}
	int f=0;
	for(int i=54;i>=0;--i){
		if(ans[i]>'0'||i==0) ++f;
		if(f) putchar(ans[i]);
	}
}
