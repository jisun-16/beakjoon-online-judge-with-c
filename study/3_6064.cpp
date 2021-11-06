#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int t, m, n, x, y;
//k번째 해는 <k%m, k%n>
int main(){
	cin >> t;
	while(t--){
		cin >> m >> n >> x >> y;
		
		int ans = -1;
		for(int i=0;i<n;i++){
			if((m*i+x)%n==y%n){
				ans=m*i+x;
				break;
			}
		}
		
		cout << ans << '\n';
	}
}
