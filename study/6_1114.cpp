#include<iostream>
#include<algorithm>

using namespace std;

int l,k,c,cut[10002],len[10002];

int _solve(int size){
	int cc=c, temp=0;
	
	for(int i=k;i>=0;i--){
		if(len[i]>size) return -1;//더이상 자를 수 없음 
		
		temp+=len[i];
		
		if(temp>size){
			cc--;
			temp=len[i];
		}
		
		if(cc==0){
			if(cut[i]>size) return -1;
			else return cut[i];
		}
	}
	
	return cut[0];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin>>l>>k>>c;
	for(int i=0;i<k;i++){
		cin>>cut[i];
	}
	cut[k]=l;
	
	sort(cut,cut+k+1);
	
	len[0]=cut[0];
	for(int i=1;i<=k;i++) 
		len[i]=cut[i]-cut[i-1];
	
	int m_len=l, f_cut=l;
	int start=1,end=l;
	while(start<=end){
		int mid=(start+end)/2;
		int loc=_solve(mid);
		if(loc>=0){
			m_len=mid;
			f_cut=loc;
			end=mid-1;
		}
		else start=mid+1;
	}//최대 길이에 대해 이분탐색. 
	
	cout<<m_len<<' '<<f_cut<<'\n';
}
