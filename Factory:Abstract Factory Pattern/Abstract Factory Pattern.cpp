//============================================================================
// Name        : LAB6.cpp
// Author      : Burak Sonmez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class CarParts{
public:
		virtual void displayPartDetails() = 0;
		virtual ~CarParts(){};
};
// An 'Abstract Product Engine' class
class Engine : public CarParts{
	public:
		virtual void displayPartDetails(){
			cout<<"Engine"<<endl;
		}
		virtual ~Engine(){};
};
// An 'Abstract Product Transmission' class
class Transmission :public CarParts{
	public:
		virtual void displayPartDetails() {
			cout<<"Transmission"<<endl;
		}
		virtual ~Transmission(){};
};
// A 'ConcreteProduct OpelEngine' class
class OpelEngine : public  Engine{
	public:
		void displayPartDetails() {
			cout << "Opel Engine"<< endl;
	}
		 ~OpelEngine(){};
};
// A 'ConcreteProduct MercedesEngine' class
class MercedesEngine : public  Engine{
	public:
		void displayPartDetails() {
			cout << "Mercedes Engine"<< endl;
	}
		~MercedesEngine(){}
};
// An 'Abstract Product OpelTransmission' class
class OpelTransmission : public  Transmission{
	public:
		void displayPartDetails() {
			cout << "Opel Transmission"<< endl;
	}
		~OpelTransmission(){}
};
// An 'Abstract Product MercedesTransmission' class
class MercedesTransmission : public  Transmission{
	public:
		void displayPartDetails() {
			cout << "Mercedes Transmission"<< endl;
	}
};

// An 'Abstract Factory' class
class CarFactory {
public:
	virtual Transmission* Transmission() = 0;
	virtual Engine* Engine() = 0;
	virtual ~CarFactory(){};
};
// Both 'Concrete Factory' classes
class OpelFactory : public CarFactory {
	OpelTransmission* Transmission() {
		return new OpelTransmission();
	}
	OpelEngine* Engine() {
		return new OpelEngine();
	}
};
class MercedesFactory : public CarFactory {
	MercedesTransmission* Transmission() {
		return new MercedesTransmission();
	}
	MercedesEngine* Engine() {
		return new MercedesEngine();
	}
};
class Car{
	private:
		vector <CarParts*> parts;
	public:
		vector<CarParts*> getParts(){
			return this->parts;
		}
		Car(CarFactory *F){
			parts.push_back(F->Transmission());
			parts.push_back(F->Engine());
		}

};

Car* build(CarFactory *cf){
	Car *c = new Car(cf);
	return c;
}
int main() {
   CarFactory* Opel = new OpelFactory;
   Car* o1 =  build(Opel);
   vector<CarParts*> partsofo1 = o1->getParts();
   for(unsigned int i=0; i < partsofo1.size() ;i++){
	   partsofo1[i]->displayPartDetails();
	}


}
