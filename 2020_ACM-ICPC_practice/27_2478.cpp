#include<cstdio>
using namespace std;

#define mxn 502
int a[mxn], b[mxn], n;

bool rev( int x ){
	a[0] = a[n];
    a[n+1] = a[1];
    if( (a[x]==1&&a[x-1]==n) || a[x]==a[x-1]+1 ) return 0;
    if( (a[x]==n&&a[x+1]==1) || a[x]+1==a[x+1] ) return 0;
    return 1;
}

int main(){
    scanf("%d",&n);
    for( int i=1; i<=n; i++ ) scanf("%d",&a[i]);
    int l1=n, l2=n, p[2]={0,0}, q[2]={0,0};

	for( int i=1; i<=n; i++ ){
        if( rev(i) ){
            int t = 0;
            if( p[t] ) t++;     // �̹� ������ ������ ������ 
            p[t] = q[t] = i;
            while( q[t]<n && rev(q[t]+1) ) q[t]++;
            i = q[t];
        }
    }
    if( p[1] ){     // ������ ������ �� ���� ���� �б� Ƚ�� �������
        l2 = n - p[1] + 1;
        for( int i=p[1]; i<=n; i++ ) b[i-p[1]+1] = a[i];
        for( int i=p[1]-1; i; i-- ) a[i+l2] = a[i];
        for( int i=1; i<=l2; i++ ) a[i] = b[i];
        q[0] += l2; // �̷� ��쿡�� ������ ������ �׻� [1,q[0]]����
    }
    // ������ ���� ���󺹱�
    for( int i=p[0]; i<=q[0]; i++ ) b[q[0]+p[0]-i] = a[i];
    for( int i=p[0]; i<=q[0]; i++ ) a[i] = b[i];
    
    // ù ��° ���� �б�� n�� ��� ��ġ�� �ִ����� �Ǻ�
    for( int i=1; i<n; i++ ) if( a[i]==n ) l1 = n-i;
    
    printf("%d\n%d %d\n%d",l1,p[0],q[0],l2);
    return 0;
}
