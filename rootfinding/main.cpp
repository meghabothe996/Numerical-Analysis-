#include<iostream>
#include"rootfinding.hpp"
using namespace std;

int main()
{
	rootfinding obj;
	obj.newtonRaphson_method();
	cout << "newton method is executed successfully"<<endl;
	obj.bisection_method();
	cout << "bisection method is executed successfully" << endl;
	obj.fixedpoint_method();
	cout << "fixed point method is executed sucessfully" << endl;
	return 0;
}
