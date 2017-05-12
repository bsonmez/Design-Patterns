//============================================================================
// Name        : LAB9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::swap;

class Sort{
protected:
	vector <int> numbers;
public:
	 bool checkInput(int c){
		return (c > 0);
	};
	 void getInput(){
		int b;
		cout << "Enter Numbers; ";
		cin >> b;
		while(checkInput(b)){
			numbers.push_back(b);
			cout << "Enter Numbers; ";
			b =  NULL;
			cin >> b;
		}
		cout<<"terminating..."<<endl;
		return;


	}
	 void display(){
		 for(int i=0;i<numbers.size();i++){
		 			cout<<"Numbers :"<<numbers[i]<<endl;;
		 }
	 }
	 virtual void compare()=0;
	 //Template Class
	 virtual void sort(){
		 getInput();
		 compare();
		 display();
	 };
};
class AscendingSort:public Sort{
	virtual void compare(){
		for(int i=1;i<=numbers.size();i++){
			for(int j=0;j<numbers.size()-1;j++){
			if(numbers[j]>numbers[j+1]){
				int temp;
				temp=numbers[j];
				numbers[j]=numbers[j+1];
				numbers[j+1]=temp;
				}
			}
		}
	}
};
class DescendingSort:public Sort{
	virtual void compare(){
			for(int i=1;i<=numbers.size();i++){
				for(int j=0;j<numbers.size()-1;j++){
				if(numbers[j]<numbers[j+1]){
					int temp;
					temp=numbers[j];
					numbers[j]=numbers[j+1];
					numbers[j+1]=temp;
				}
			}
		}
	}
};
int main() {
	AscendingSort *a1=new AscendingSort();
	a1->sort();
	DescendingSort *d1= new DescendingSort();
	d1->sort();

}
