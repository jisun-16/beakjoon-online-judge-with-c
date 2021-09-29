#include <string>
#include <vector>
#include<iostream>

using namespace std;

int a_info[11],r_info[11];
int m_diff=0,arr[11];

void r_shoot(int idx,int rem){
	if(rem==0&&r_info[1]==2&&r_info[4]==1){
        int a_score=0,r_score=0;
        for(int i=0;i<11;++i){
            if(a_info[i]>=r_info[i]&&a_info[i]!=0) a_score+=10-i;
            else r_score+=10-i;
        }
        if(m_diff<r_score-a_score){
            m_diff=r_score-a_score;
            for(int i=0;i<11;++i)
                arr[i]=r_info[i];
        }
        return;
    }
    if(idx==-1) return;
    for(int j=rem;j>=0;--j){
        r_info[idx]=j;
        r_shoot(idx-1,rem-j);
        r_info[idx]=0;
    }
}
int main(){
	int n;
	vector<int> info(11,0);
    vector<int> answer(11,0);
    
	cin>>n;
	for(int i=0;i<11;++i) cin>>info[i];
    
    for(int i=0;i<11;++i) a_info[i]=info[i];
    r_shoot(10,n);
    
    if(m_diff==0) cout<<-1;
    else{
        for(int i=0;i<11;++i)
            cout<<arr[i]<<' ';
    }
}
