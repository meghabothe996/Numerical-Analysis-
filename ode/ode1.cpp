#include<iostream>
#include"ode1.hpp"
#include<math.h>
using namespace std;
#define e 2.7181




double ODE :: eulersCauchy(double x0,double y0,double xn,double h)
{
	double y=y0,x=x0,yn,k1,k2,k3;
	for(double i=x0+h;i<=xn;i+=h)
	{
		k1=h*functionY(x,y);
		k2=h*functionY(x+h,y+k1);
		yn=y+(k1+k2)/2;
		y=yn;
		x=i;
        cout<<i<<"\t"<<yn<<endl;

	}
	// err=abs (e-yn);

//cout<<"error:"<<err<<endl;

	return yn;
}


double ODE :: Heun(double x0,double y0,double xn,double h)
{
	double y=y0, yn,k1,k2,k3;
	for(double i=x0+h;i<=xn;i+=h)
	{
		k1=h*functionY(i-h,y);
		k2=h*functionY(((i-h)+((1/3)*h)),(y+((1/3)*k1)));
		k3=h*functionY((i-h+(2/3)*h),(y+(2/3)*k2));
		yn=y+(k1+3*k3)/4;
		y=yn;
		printf("%f\t%f\n",i,yn);
	}
	return yn;
}



double ODE :: RungeKutta(double x0,double y0,double xn,double h)
{
	double y=y0,yn,k1,k2,k3,k4;
	for(double i=x0+h;i<=xn;i+=h)
	{
		k1=h*functionY(i-h,y);
		k2=h*functionY(((i-h)+((1/3)*h)),(y+((1/3)*k1)));
		k3=h*functionY((i-h+(2/3)*h),(y-(1/3)*k1+k2));
		k4=h*functionY(i,y+k1-k2+k3);
		yn=y+(k1+3*k2+3*k3+k4)/8;
		y=yn;
		printf("%f\t%f\n",i,yn);
	}
	return yn;
}

double ODE :: eulermethod(double x0,double y0,double xn,double h)
{
	double y=y0,x=x0,yn,k1,k2,k3;
	for(double i=x0+h;i<=xn;i+=h)
	{
		
		yn=y+h*functionY(i-h,y);
		y=yn;
		x=i;
		printf("%f\t%f\n",i,yn);
	}
	return yn;
}



double ODE :: functionY(double x,double y)
{
	return pow(e,-10*x); //return the value of equation
	}