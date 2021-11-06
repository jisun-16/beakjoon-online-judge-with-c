#include<iostream>
#include<algorithm>
#include<utility>
 
using namespace std;
 
int n, k, e_cnt[101], t, plug[101], cnt, shd[101], res;
 
int main(){
    cin >> n >> k;
 
    for(int i=1; i<=k; i++){
        cin >> t;
        e_cnt[t]++;
        shd[i] = t;
    }
    
    for(int i=1; i<=k; i++){
        if(plug[shd[i]]){
            e_cnt[shd[i]]--;
            continue;
        }
        
        if(cnt < n){
            plug[shd[i]] = 1;
            e_cnt[shd[i]]--;
            cnt++;
            continue;
		}
		
        int p = 0, last[110] = {0}, tmp = 0;
        for(int j=1; j<i; j++){
            if(plug[shd[j]]){
                if(e_cnt[shd[j]] == 0) p = shd[j];
            }
    	}
    	if(p == 0){
            for(int j=i+1; j<=k; j++) {
                if(plug[shd[j]] && last[shd[j]] == 0) last[shd[j]] = j;
            }
            for(int j=1; j<=k; j++){
                    if(last[shd[j]]) tmp = max(tmp, last[shd[j]]);
                }
        	p = shd[tmp];
        }
        
        plug[p] = 0;
        res++;
        plug[shd[i]] = 1;
        e_cnt[shd[i]]--;
    }
	
	cout << res << endl;
 
    return 0;
}
