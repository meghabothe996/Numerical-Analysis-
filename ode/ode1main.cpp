#include<iostream>
#include"ode1.hpp"
#define e 0.00004539
using namespace std;

int main()
{
	ODE ode;
	int op;
	double x0,y0,h,xn,ans,err;
	
	x0=0;
	y0=1;
	h=1;
	xn=1;
	
	
	cout<<"\n\tY("<<x0<<")="<<y0<<endl;
	cout<<"\tY("<<xn<<")=?"<<endl;
	
	do{
	cout<<"\n\n**********MENU**********\n\n Second Order Methods :  \n\t1)Euler's Cauchy Method\n Third Order Methods : \n\t2)Heun Method\n Fourth Order Methods : \n\t3)Runge Kutta Method\n 4)Euler series\n Enter your choice : ";
	cin>>op;
	
	switch(op)
	{
		case 1 :
			ans=ode.eulersCauchy(x0,y0,xn,h);
			break;
		case 2 :
			ans=ode.Heun(x0,y0,xn,h);
			break;
		
		case 3 :
			ans=ode.RungeKutta(x0,y0,xn,h);
			break;
		case 4 :
			ans=ode.eulermethod(x0,y0,xn,h);
			break;
		default : 
			cerr<<"You Choose Wrong Option"<<endl;
            return 0;
	}
    cout<<"\n\tResult :: Y(" <<xn<< ") = "<<ans<<endl;	
	err=abs(e-ans);
	cout<<"\n\t error :: "<<err<<endl;		
	}while(op!=0);
	return 0;
}