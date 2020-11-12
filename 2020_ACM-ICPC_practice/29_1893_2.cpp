#include<iostream>
#include<cstring>

using namespace std;

int T,kmp[50001];
char A[64],W[50001],S[500001],num[123],ans[63];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>A>>W>>S;
		int a=strlen(A),w=strlen(W),s=strlen(S);
		
		for(int i=0;i<a;++i) num[A[i]]=i,ans[i]=0;
		for(int i=0;i<w;++i) W[i]=num[W[i]];
		for(int i=0;i<s;++i) S[i]=num[S[i]];
		
		if(w==1){
			int cnt=0;
			
			for(int i=0;i<s;++i)
				if(++ans[(S[i]-W[0]+a)%a]==1) ++cnt;
				else if(ans[(S[i]-W[0]+a)%a]==2) --cnt;
			
			if(cnt){
				if(cnt>1) cout<<"ambiguous: ";
				else cout<<"unique: ";
				for(int i=0;i<a;++i)
					if(ans[i]==1) cout<<i<<" ";
			}
			else cout<<"no solution";
			cout<<"\n";
			
			continue;
		}
		
		int Wa[w]={0,},Sa[s]={0,};
		for(int i=0;i<w-1;++i)
			Wa[i]=(W[i+1]-W[i]+a)%a;
		for(int i=0;i<s-1;++i)
			Sa[i]=(S[i+1]-S[i]+a)%a;
			
		int j=0;
		for(int i=1;i<w-1;++i){
			while(j&&Wa[i]!=Wa[j])
				j=kmp[j-1];
			if(Wa[i]==Wa[j]) kmp[i]=++j;
		}
		
		int cnt=0;
		j=0;
		for(int i=0;i<s-1;++i){
			while(j&&Sa[i]!=Wa[j]) j=kmp[j-1];
			if(Sa[i]==Wa[j]){
				if(j==w-2){
					if(++ans[(S[i]-W[j]+a)%a]==1)
						++cnt;
					else if(ans[(S[i]-W[j]+a)%a]==2)
						--cnt;
					j=kmp[j];
				}
				else ++j;
			}
		}
		
		if(cnt){
			if(cnt>1) cout<<"ambiguous: ";
			else cout<<"unique: ";
			for(int i=0;i<a;++i)
				if(ans[i]==1) cout<<i<<" ";
		}
		else cout<<"no solution";
		cout<<"\n";
	}
}
