#include<cstdio>
#include<cstring>

using namespace std;

char a[10001],b[10001],ans[10002];

int main(){
	scanf("%s %s",a,b);
	int al=strlen(a),bl=strlen(b),t=0,idx=0;
	if(a[0]!='-'&&b[0]!='-'){
		while(al&&bl){
			al--;bl--;
			int temp=a[al]-'0'+b[bl]-'0'+t;
			t=temp/10;
			ans[idx++]=temp%10+'0';
		}
		while(al--){
			int temp=a[al]+t;
			t=temp/10;
			ans[idx++]=temp%10+'0';
		}
		while(bl--){
			int temp=b[bl]+t;
			t=temp/10;
			ans[idx++]=temp%10+'0';
		}
		if(t) ans[idx++]=t+'0';
		for(int i=idx-1;i>=0;i--) printf("%c",ans[i]);
	}
	else if (a[0]=='-'&&b[0]=='-'){
		while(al>1&&bl>1){
			al--;bl--;
			int temp=a[al]-'0'+b[bl]-'0'+t;
			t=temp/10;
			ans[idx++]=temp%10+'0';
		}
		while(al-->1){
			int temp=a[al]+t;
			t=temp/10;
			ans[idx++]=temp%10+'0';
		}
		while(bl-->1){
			int temp=b[bl]+t;
			t=temp/10;
			ans[idx++]=temp%10+'0';
		}
		if(t) ans[idx++]=t+'0';
		printf("-");
		for(int i=idx-1;i>=0;i--) printf("%c",ans[i]);	
	}
	else if((a[0]=='-'&&b[0]!='-')){
		if(al-1<bl){
			char* temp=a;
			a=b;
			b=temp;
		}
		
		while(al&&bl){
			al--;bl--;
			if(a[al]=='-'||b[bl]=='-') break;
			if(a[al]+t>=b[bl]){
				ans[idx++]=a[al]+t-b[bl]+'0';
				t=0;
			}
			else{
				ans[idx++]=10+a[al]+t-b[bl]+'0';
				t=-1;
			}
		}
		while(al--){
			if(a[al]=='-') break;
			if(a[al]+t>='0'){
				ans[idx++]=a[al]+t;
				t=0;
			}
			else{
				ans[idx++]=10+a[al]+t;
				t=-1;
			}
		}
		bool chk=false;
		while(bl-->1){
			if(b[bl]=='-') break;
			chk=true;
			if(b[bl]-t<10){
				ans[idx++]=b[bl]-t;
			}
			int temp=b[bl]+t;
			t=temp/10;
			ans[idx++]=temp%10+'0';
		}
		if(chk) printf("-");
		for(int i=idx-1;i>=0;i--) printf("%c",ans[i]);
	}
}
