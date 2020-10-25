#include <iostream>
#include <sstream>
//#include<string>

using namespace std;
string trans_order[10];
	
string trans(string order){
	string ret="";
	int idx=0;
	for(int i=0;i<order.length();i++){
		if(order[i]=='R'||order[i]=='G'||order[i]=='B'){
			if(i+1<order.length()&&order[i+1]=='('){
				char pre=order[i];
				i++;
				int cnt=0,jump=0;
				while(true){
					cnt++;
					if(order[i+cnt]=='(')
						jump++;
					else if(order[i+cnt]==')'){
						if(jump)
							jump--;
						else
							break;
					}
				}
				
				string inside=trans(order.substr(i+1,cnt-1));
				
				for(int j=0;j<inside.length();j+=2)
					inside.insert(j,1,pre);
				
				ret+=inside;
				i+=cnt;
			}
			else
				ret+=order[i];
		}
		else if(order[i]>='1'&&order[i]<='9'){
			int rec=order[i]-'0';
			i++;
			
			if(order[i]=='('){
				int cnt=0,jump=0;
				while(true){
					cnt++;
					if(order[i+cnt]=='(')
						jump++;
					else if(order[i+cnt]==')'){
						if(jump)
							jump--;
						else
							break;
					}
				}
				
				string inside=trans(order.substr(i+1,cnt-1));
				
				while(rec--)
					ret+=inside;
				i+=cnt;
			}
			else{
				while(rec--)
					ret+=order[i];
			}
		}
	}
	
	return ret;
}

void solution(int numOfOrder, string *orderArr) {
	for(int i=0;i<numOfOrder;i++){
		string order=orderArr[i];
		trans_order[i]=trans(order);
	}
	
	for(int i=0;i<numOfOrder;i++)
		cout<<trans_order[i]<<'\n';
}

struct input_data {
  int numOfOrder;
  string *orderArr;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfOrder;

  inputData.orderArr = new string[inputData.numOfOrder];
  for (int i = 0; i < inputData.numOfOrder; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    iss >> inputData.orderArr[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfOrder, inputData.orderArr);
  return 0;
}
