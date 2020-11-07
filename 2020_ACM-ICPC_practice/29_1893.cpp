#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int n,al,wl,sl;
char A[63],W[50001],S[500001],alp[62];

bool kmp(char S2[]){
	int cnt=0;
	int j=0;
	vector<int> w(wl,0);
	for(int i=1;i<wl;i++){
		while(j>0&&W[i]!=W[j])
			j=w[j-1];
		if(W[i]==W[j])
			w[i]=++j;
	}
	
	j=0;
	for(int i=0;i<sl;i++){
		while(j>0&&S2[i]!=W[j])
			j=w[j-1];
		if(S2[i]==W[j]){
			if(j==wl-1){
				cnt++;
				j=w[j];
			}
			else
				j++;
		}
	}
	
	if(cnt==1) return true;
	else return false;
}

int main(){
	for(int i=0;i<62;i++){
		if(i<26)
			alp[i]=i+'A';
		else if(i<52)
			alp[i]=i-26+'a';
		else
			alp[i]=i-52+'0';
	}
	
	scanf("%d",&n);
	while(n--){
		scanf("%s",A);
		scanf("%s",W);
		scanf("%s",S);
		
		al=strlen(A);wl=strlen(W);sl=strlen(S);
		
		int idx[63]={0,};
		for(int i=0;i<al;i++){
			if(A[i]>='A'&&A[i]<='Z') idx[A[i]-'A']=i;
			else if(A[i]>='a'&&A[i]<='z') idx[26+A[i]-'a']=i;
			else idx[52+A[i]-'0']=i;
		}
		
		vector<int> ans;
		for(int i=0;i<al;i++){
			char S2[500001];
			strcpy(S2,S);
			if(i){
				for(int j=0;j<sl;j++){
					int k;
					if(S[j]>='A'&&S[j]<='Z') k=idx[S[j]-'A']; 
					else if(S[j]>='a'&&S[j]<='z') k=idx[26+S[j]-'a'];
					else k=idx[52+S[j]-'0'];
					S2[j]=A[(k+i)%al];
				}
			}
			if(kmp(S2))
				ans.push_back((al-i)%al);
		}
		
		if(ans.size()==0)
			printf("no solution\n");
		else if(ans.size()==1)
			printf("unique: %d\n",ans[0]);
		else{
			printf("ambiguous: ");
			sort(ans.begin(),ans.end());
			for(int i=0;i<ans.size();i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
}
