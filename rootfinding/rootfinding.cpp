//newton raphson
// #include<iostream>
// #include<math.h>
// #include<iomanip>
// #include <fstream>
// #include <iostream>
// #include <cstring>
#include <bits/stdc++.h> // has all the lib from above
#include "rootfinding.hpp"
using namespace std;

rootfinding :: rootfinding()
{

}
void rootfinding ::newtonRaphson_read()
{
    string myText, word;
    fstream file;
    float array[2];
    int i = 0;

    file.open("input_newtonRaphson.txt", ios::in);
    getline(file, myText);

    // converting to string-string format
    // speparating by spaces
    stringstream ss(myText);
    while (ss >> word)
    {
        array[i] = stof(word);
        i++;
    }
    this->a = array[0];
    this->allowed_error = array[1];
    file.close();
}
int rootfinding ::newtonRaphson_method()
{
    int iter = 1;
    fstream file;
    this->newtonRaphson_read();
    file.open("output_newtonRaphson.txt", ios::out);
    file << "initial values a :" << this->a << ", allowed errors are :" << this->allowed_error << endl;
    file << "Iteration no : " << iter << ", x = " << this->a << endl;
    while (1)
    {
        float h = ne_function(this->a) / ne_dfunction(this->a);
        float new_point = this->a - h;
        iter++;
        file << "Iteration no :" << setw(3) << iter << ", x =" << setw(9) << setprecision(6) << new_point << endl;
        if (fabs(h) < this->allowed_error)
        { // fabs used to calculate absolute value of h if h is less than error allowed we stop the method

            file << "after no :" << setw(3) << iter << " iterations, root =" << setw(8) << setprecision(6) << new_point << endl;
            return 1;
        }
        this->a = new_point;
    }
}
float rootfinding ::ne_function(const float x)
{
    return (x * x - 4 * x - 7);
}
float rootfinding ::ne_dfunction(const float x)
{
    return (2 * x - 4);
}


//fixed point

void rootfinding ::fixedpoint_read()
{
    string myText;
    fstream file;
    file.open("input_fixedPoint.txt", ios::in);
    getline(file, myText);

    // converting to string-string format
    // speparating by spaces
    stringstream ss(myText);
    string word;
    float array[2];
    int i = 0;
    while (ss >> word)
    {
        array[i] = stof(word);
        i++;
    }
    this->a = array[0];
    this->allowed_error = array[1];
    file.close();
}

int rootfinding ::fixedpoint_method()
{
    int iter = 1;
    fstream file;
    this->fixedpoint_read();
    file.open("output_fixedPoint.txt", ios::out);
    file << "initial values a :" << this->a << ", allowed errors are :" << this->allowed_error << endl;
    file << "Iteration no:  " << iter << ", x = " << this->a << endl;
    while (1)
    {
        float new_point = fix_function(this->a);
        float h = abs(new_point) - abs(this->a);
        iter++;
        file << "Iteration no :" << setw(3) << iter << ", x =" << setw(9) << setprecision(6) << new_point << endl;
        if (fabs(h) < this->allowed_error)
        { // fabs used to calculate absolute value of h if h is less than error allowed we stop the method

            file << "after no :" << setw(3) << iter << " iterations, root =" << setw(8) << setprecision(6) << new_point << endl;
            file.close();
            return 1;
        }
        this->a = new_point;
    }
}
float rootfinding ::fix_function(const float x)
{
    return (1 / (sqrt(x + 1)));
}

//bisection
void rootfinding ::bisection_read()
{
	string myText;
	fstream file;
	file.open("input_bisection.txt", ios::in);
	getline(file, myText);

	// converting to string-string format
	// speparating by spaces
	stringstream ss(myText);
	string word;
	float array[3];
	int i = 0;
	while (ss >> word)
	{
		// string to float
		array[i] = stof(word);
		i++;
	}
	this->a = array[0];
	this->b = array[1];
	this->allowed_error = array[2];
	file.close();
}

int rootfinding ::bisection_method()
{
	// bisection method
	// previous point
	float prev_mid;
	int iter = 1;
    this->bisection_read();
	this->mid_point = (this->a + this->b) / 2;

	fstream file;
	file.open("output_bisection.txt", ios::out);
	file << "initial values a :" << this->a << ", b :" << this->b << ", allowed errors are :" << this->allowed_error << endl;
	file << "Iteration no:  " << iter << ", mid point = " << this->mid_point << endl;
	prev_mid = this->mid_point;
	do
	{
		if (bi_function(this->a) * bi_function(this->mid_point) < 0)
			this->b = this->mid_point;
		else
			this->a = this->mid_point;
		this->mid_point = (this->a + this->b) / 2;
		++iter;
		file << "Iteration no:  " << iter << ", mid point = " << this->mid_point << endl;
		if (fabs(this->mid_point - prev_mid) < this->allowed_error)
		{
			file << "after " << iter << " iterations, root =" << setw(6) << setprecision(6) << this->mid_point << endl;
			file.close();
			return 1;
		}
		prev_mid = this->mid_point;
	} while (1);
}
float rootfinding ::bi_function(const float x)
{
	return (2 * x * x * x - 2 * x - 5);
}

