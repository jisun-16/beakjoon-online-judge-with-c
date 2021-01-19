#include<cstdio>
#include<cmath>
double min(double a,double b){return a<b?a:b;}
int x,y,d,t,j;
int main(){
	scanf("%d %d %d %d",&x,&y,&d,&t);
	double dist=sqrt(x*x+y*y);
    j=dist/d;
	printf("%.9lf\n",min(dist, min(j*t+dist-j*d, j==0?min(2*t,t+fabs(dist-d)):(j+1)*t)));
}
