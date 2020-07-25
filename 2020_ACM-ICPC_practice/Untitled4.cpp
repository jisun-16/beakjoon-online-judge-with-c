#include <cstdio>
#include <algorithm>
using namespace std;
 
// way�� true�� ������, false�� ����
// a1, a2�� �������� ��� y��ǥ, ������ ��� x��ǥ�̸� a1 < a2
// b�� �ٸ� ��ǥ
int Hilbert(int n, bool way, int a1, int a2, int b){
    if(a1>=a2 || b==0 || b==1<<n) return 0;
 
    int N = 1<<n, H = 1<<n-1, result = 0;
    // ������
    if(way){
        // ���� ���
        if(n == 1) return (a1==0 && a2>=1);
        if(b == H) return (a1<H);
        // ����
        if(b < H){
            if(a1 < H) result += Hilbert(n-1, true, a1, min(H, a2), b);
            if(a2 > H) result += Hilbert(n-1, false, max(a1-H, 0), a2-H, H-b);
        }
        // ������
        else{
            if(a1 < H) result += Hilbert(n-1, true, a1, min(H, a2), b-H);
            if(a2 > H) result += Hilbert(n-1, false, N-a2, min(H, N-a1), b-H);
        }
    }
    // ����
    else{
        // ���� ���
        if(n == 1) return (a1==0) + (a2==2);
        if(b == H) return (a1==0) + (a2==N);
        // ����, �����ʿ� ���� ����: �¿��Ī�� �κ��� �߶�
        if(a1<H && a2>H){
            // �ϴ�
            if(b < H){
                if(a1 <= N-a2){
                    result += Hilbert(n-1, false, a1, N-a2, b);
                    result += Hilbert(n-1, false, N-a2, H, b)*2;
                }
                else{
                    result += Hilbert(n-1, false, N-a2, a1, b);
                    result += Hilbert(n-1, false, a1, H, b)*2;
                }
            }
            // ���
            else{
                if(a1 <= N-a2){
                    result += Hilbert(n-1, true, a2-H, H-a1, b-H);
                    result += Hilbert(n-1, true, 0, a2-H, b-H)*2;
                }
                else{
                    result += Hilbert(n-1, true, H-a1, a2-H, b-H);
                    result += Hilbert(n-1, true, 0, H-a1, b-H)*2;
                }
            }
        }
        // ���� Ȥ�� �����ʿ��� ����
        else{
            // �ϴ�
            if(b < H){
                if(a1 < H) result += Hilbert(n-1, false, a1, min(H, a2), b);
                else result += Hilbert(n-1, false, max(a1-H, 0), a2-H, b);
            }
            // ���
            else{
                if(a1 < H) result += Hilbert(n-1, true, max(H-a2, 0), H-a1, b-H);
                else result += Hilbert(n-1, true, max(a1-H, 0), a2-H, N-b);
            }
        }
    }
    return result;
}
 
int main(){
    while(1){
        int n, x1, x2, y;
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d %d %d", &x1, &x2, &y);
        printf("%d\n", Hilbert(n, false, x1, x2, y));
    }
}
