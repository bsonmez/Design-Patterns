//============================================================================
// Name        : LAB7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//Client
class Mean{
public:
	double Total(vector<int>inputs){
		int total = 0;
		for(int i;i<inputs.size();i++){
			total+=inputs[i];
		}
		return total/inputs.size();
	}
};
//Subsystem 1.
class Derivation{
public:
	double Total(vector<int>inputs,double input_mean){
			int derivation = 0;
			for(int i=0;i<inputs.size();i++){
				derivation=+(inputs[i]-input_mean)*(inputs[i]-input_mean);
			}
			return derivation;
		}
};
//Subsystem 2.
class Variance{
public:
	double Total(vector<int>inputs,double input_mean){
				int variance = 0;
				for(int i;i<inputs.size();i++){
					variance=+(((inputs[i]-input_mean)*(inputs[i]-input_mean))/input_mean);
				}
				return variance;
			}
};
//Subsystem 3.
class StandardDerivaiton{
public:
	double Total(vector<int>inputs,double input_mean){
					int sderivation = 0;
					for(int i;i<inputs.size();i++){
						sderivation=+(((inputs[i]-input_mean)*(inputs[i]-input_mean))/input_mean);
					}
					return sqrt(sderivation);
				}
};
//Facade Class

class Input{
public:
	vector<int>inputs;
	void enterInput(){
		do{
		cout<<"ENTER"<<endl;
		int num;
		cin>>num;
		if(num==-1) break;
		inputs.push_back(num);
		}while(true);
	}

};

class AbstractFacade{
private:
	Mean mean;
	Derivation derivation;
	Variance variance;
	StandardDerivaiton sderivation;

public:

	double Total(){
		Input x;
		x.enterInput();
		double a = mean.Total(x.inputs);
		double b= variance.Total(x.inputs,a);
		double c = derivation.Total(x.inputs,a);
		double d = sderivation.Total(x.inputs,a);
	}

};



int main() {
	Mean m;
	Derivation d;
	Variance v;
	StandardDerivaiton s;

	vector<int>enter;


	enter.push_back(3);
	enter.push_back(4);
	enter.push_back(5);
	enter.push_back(6);

	double mean,derivation,variance,sderivaiton;

	mean = m.Total(enter);
	cout<<"mean is"<<mean;

	AbstractFacade af;
	af.Total();



}
