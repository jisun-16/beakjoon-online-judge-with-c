#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int _gcd(int a,int b){
	if(a<b){
		int temp=a;a=b;b=temp;
	}
	
	while(b){
		int n=a%b;
		a=b;
		b=n;
	}
	
	return a;
} 

pair<int,int> _calc(int a,int b,int c,int d){
	int x=_gcd(a*d+b*c,b*d);
	return {(a*d+b*c)/x,b*d/x};
}

int main(){
	//ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	 
	int a,b,c;
	//¿¬·á¿ë·®,½Â°´ÀÌ ÁöºÒÇÏ´Â µ·,1°¶·± ´ç ÁÖÇà°Å¸® 
	cin>>a>>b>>c;
	
	int n;
	cin>>n;
	map<string,pair<int,int> > Map;
	for(int i=0;i<n;i++){
		string temp="";
		int x=0,y=0,cnt=0;
		while(true){
			string temp2;
			cin>>temp2;
			
			if(temp2[0]>='0'&&temp2[0]<='9'){
				int temp3=0;
				for(int j=0;j<temp2.size();j++){
					temp3+=temp2[j]-'0';
					temp3*=10;
				}
				temp3/=10;
				
				if(cnt==0){
					x=temp3;
					cnt++;
				}
				else{
					y=temp3;
					break;
				}
			}
			else{
				if(temp.size()==0) temp+=temp2;
				else{
					temp+=' ';
					temp+=temp2;
				}
			}
		}
		Map[temp]={x,y};
	}
	
	map<string,int> GS;
	for(int i=0;i<3;i++){
		string temp="";
		int x=0;
		while(true){
			string temp2;
			cin>>temp2;
			
			if(temp2[0]>='0'&&temp2[0]<='9'){
				int temp3=0;
				for(int j=0;j<temp2.size();j++){
					temp3+=temp2[j]-'0';
					temp3*=10;
				}
				temp3/=10;
				
				x=temp3;
				break;
			}
			else{
				if(temp.size()==0) temp+=temp2;
				else{
					temp+=' ';
					temp+=temp2;
				}
			}
		}
		
		GS[temp]=x;
	}
	
	int k;
	cin>>k;
	vector<pair<string,int> > pass;
	int money=0;
	pair<int,int> gas;gas={a,1};
	bool chk=false,full=false;
	int x=Map["Taxi Garage"].first,y=Map["Taxi Garage"].second;
	while(k--){
		//cout<<gas.first<<"/"<<gas.second<<' '<<money<<'\n';
		string temp;
		
		if(full||gas.first<0){
			getline(cin,temp);
			continue;
		}
		
		cin>>temp;
		if(temp=="Go"){
			cin>>temp;
			getline(cin,temp);
			
			temp.erase(temp.begin());temp.erase(temp.end()-1);
			
			int nx=Map[temp].first,ny=Map[temp].second;
			
			if((abs(nx-x)+abs(ny-y))*gas.second>gas.first*c){
				gas.first=-1;
				continue;
			}
			
			if(temp=="Taxi Garage"&&k==0) chk=true;
			
			gas=_calc(gas.first,gas.second,-(abs(nx-x)+abs(ny-y)),c);
			for(int i=0;i<pass.size();i++) {
				pass[i].second+=abs(nx-x)+abs(ny-y);
				if(pass[i].first==temp){
					money+=pass[i].second*b;
					pass.erase(pass.begin()+i);
					i--;
				}
			}
			x=nx;y=ny;
			
			if(GS.find(temp)!=GS.end()){
				pair<int,int> C=_calc(a,1,-gas.first,gas.second);
				int cost=GS[temp]*C.first/C.second;
				
				if(money>=cost){
					money-=cost;
					gas={a,1};
				}
				else{
					gas=_calc(gas.first,gas.second,money,GS[temp]);
					money=0;
				}
			}
		}
		else if(temp=="Pickup"){
			for(int i=0;i<4;i++) cin>>temp;
			getline(cin,temp);
			temp.erase(temp.begin());temp.erase(temp.end()-1);
			
			if(pass.size()==3){
				full=true;
				continue;
			}
			
			pass.push_back({temp,0});
		}
	}
	
	if(gas.first<0) cout<<"OUT OF GAS\n";
	else if(full) cout<<"CAPACITY FULL\n";
	else if(!chk) cout<<"NOT IN GARAGE\n";
	else if(pass.size()) cout<<"REMAINING PASSENGER\n";
	else cout<<money<<"\n";
}
