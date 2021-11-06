#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--){
		int sm,sc,si;
		string cmd,inp;
		
		cin>>sm>>sc>>si;
		cin>>cmd>>inp;
		
		int p[4096]={0,};
		stack<int> s;
		for(int i=0;i<sc;i++){
			if(cmd[i]=='[') 
				s.push(i);
			if(cmd[i]==']'){
				int pre=s.top();
				s.pop();
				p[pre]=i;
				p[i]=pre;
			}
		}
		
		int arr[100000]={0,};
		int i=0,cnt=0,ptr=0,j=0;
		while(cnt<=50000000&&i<sc){
			cnt++;
			
			switch(cmd[i]){
				case '-':{
					arr[ptr]=(arr[ptr]-1+256)%256;
					break;
				}
				case '+':{
					arr[ptr]=(arr[ptr]+1)%256;
					break;
				}
				case '<':{
					ptr=(ptr-1+sm)%sm;
					break;
				}
				case '>':{
					ptr=(ptr+1)%sm;
					break;
				}
				case '[':{
					if(arr[ptr]==0)
						i=p[i];
					break;
				}
				case ']':{
					if(arr[ptr]!=0)
						i=p[i];
					break;
				}
				case ',':{
					arr[ptr]=(j>=si)?255:inp[j];
					j++;
					break;
				}
			}
			
			i++;
		}
		
		if(cnt<=50000000)
			cout<<"Terminates\n";
		else{
			cnt=0;
			bool chk[4096]={0,};
			while(cnt<=50000000&&i<=sc){
				cnt++;
				
				switch(cmd[i]){
					case '-':{
						arr[ptr]=(arr[ptr]-1+256)%256;
						break;
					}
					case '+':{
						arr[ptr]=(arr[ptr]+1)%256;
						break;
					}
					case '<':{
						ptr=(ptr-1+sm)%sm;
						break;
					}
					case '>':{
						ptr=(ptr+1)%sm;
						break;
					}
					case '[':{
						if(arr[ptr]==0)
							i=p[i];
						break;
					}
					case ']':{
						if(arr[ptr]!=0)
							i=p[i];
						break;
					}
					case ',':{
						arr[ptr]=(j>=si)?255:inp[j];
						j++;
						break;
					}
				}
				i++;
				
				chk[i]=true;
			}
		
			int l1=-1,l2=-1;
			for(int i=0;i<sc;i++){
				if(chk[i]){
					if(l1==-1)
						l1=i-1;
					l2=i;
				}
			}
			
			cout<<"Loops "<<l1<<" "<<l2<<"\n";
		}
	}
}
