#include<iostream>

using namespace std;

int n,m,arr[5000];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) 
		scanf("%d",&arr[i]);
	
	int s=0,e=10000;
	while(s<e){
		int mid=(s+e)/2;
		bool chk=true;
		
		int mm=1,min=arr[0],max=arr[0];
	
		for(int i=1;i<n;i++){
			if(arr[i]<min) min=arr[i];
			if(arr[i]>max) max=arr[i];
		
			if(max-min>mid){
				mm++;
				min=arr[i];
				max=arr[i];
			}
			
			if(mm>m){
				chk=false;
				break;
			}
		}
		
		if(!chk) s=mid+1;
		else e=mid;
	}
	
	printf("%d\n",e);
}
