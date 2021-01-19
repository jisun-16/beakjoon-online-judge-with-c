#include<cstdio>
double tx,ty;
void gp(double ax,double ay,double bx,double by,double cx,double cy){
	double x[]={ax+by-ay,ax+by-ay,ax+ay-by,ax+ay-by},y[]={ay+bx-ax,ay+ax-bx,ay+bx-ax,ay+ax-bx};
	double ab=(ax-bx)*(ax-bx)+(ay-by)*(ay-by),ctoab=(by-ay)*cx-(bx-ax)*cy-bx*(by-ay)+by*(bx-ax);
	for(int i=0;i<4;++i){
		double bd=(bx-x[i])*(bx-x[i])+(by-y[i])*(by-y[i]),dtoab=(by-ay)*x[i]-(bx-ax)*y[i]-bx*(by-ay)+by*(bx-ax);
		if(ctoab*dtoab<0&&bd==2*ab){
			tx=x[i],ty=y[i];
			return;
		}
	}
}
void isc(double a,double b,double c,double d,double e,double f){
	tx=(-c*e+b*f)/(a*e-b*d);
	ty=b==0?(-d*tx-f)/e:(-a*tx-c)/b;
}
int main(){
	int t;
	double ax,bx,cx,ay,by,cy,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy);
		double a,b,c,d,dx,dy,ex,ey;
		gp(ax,ay,bx,by,cx,cy);
		a=tx,b=ty;
		gp(ax,ay,cx,cy,bx,by);
		c=tx,d=ty;
		dx=(a+c)/2;dy=(b+d)/2;
		gp(bx,by,ax,ay,cx,cy);
		a=tx,b=ty;
		gp(bx,by,cx,cy,ax,ay);
		c=tx,d=ty;
		ex=(a+c)/2,ey=(b+d)/2;
		isc(dy-ay,-dx+ax,-ax*(dy-ay)+ay*(dx-ax),ey-by,-ex+bx,-bx*(ey-by)+by*(ex-bx));
		printf("%.4lf %.4lf\n",tx,ty);
	}
}

