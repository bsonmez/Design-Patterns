//============================================================================
// Name        : LAB12.cpp
// Author      : BurakSonmez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Visitor;
class Clerk;
class Director;
class President;
class Advisor; 		//New ConcreteElement class forward declaration
class Conditioner;  //New ConcreteElement class forward declaration
class Accountant;	//New ConcreteElement class forward declaration


// Element  (Element)
// defines an Accept operation that takes a visitor as an argument.

class Element {
public:
	virtual ~Element(){};
	virtual void Accept(Visitor* visitor) = 0;
protected:
	Element(){};
};

// "Visitor" declares a Visit operation for each class of ConcreteElement in the
// object structure. The operation's name and signature identifies the
// class that sends the Visit request to the visitor. That lets the
// visitor determine the concrete class of the element being visited.
// Then the visitor can access the elements directly through its particular
// interface
//
// "Visitor"
class Visitor {
public:
	 virtual ~Visitor(){};
	 virtual void Visit(Clerk* element) = 0;
	 virtual void Visit(Director* element) = 0;
	 virtual void Visit(President* element)= 0;
	 virtual void Visit(Advisor* element) = 0;
	 virtual void Visit(Conditioner* element) = 0;
	 virtual void Visit(Accountant* element)= 0;

protected:
	 Visitor(){};
};

// ConcreteElement  (Employee)
// implements an Accept operation that
// takes a visitor as an argument

class Employee : public Element {
private :
    string name;
    double income;
    int vacationDays;
public:
    // Constructor
    Employee(string name, double income, int vacationDays):
		name(name),income(income),vacationDays(vacationDays) {}
    string getName() {return name;};
    void setname(string value) {name = value;};
    double getIncome() {return income;};
    void setIncome(double value) {income = value;};
    int getVacationDays() {return vacationDays;};
    void setVacationDays(int value) {vacationDays = value;};
};

class Clerk : public Employee {
public:
	Clerk(string name,int salary, int vacation) :
		Employee(name, salary, vacation) {};
	void Accept(Visitor* visitor) {visitor->Visit(this);	}
};

class Director : public Employee {
public:
    Director(string name,int salary, int vacation) :
    	Employee(name, salary, vacation) {}
	void Accept(Visitor* visitor) {visitor->Visit(this);}
};

class President : public Employee {
public:
	President(string name,int salary, int vacation) :
		Employee(name, salary, vacation) {}
	void Accept(Visitor* visitor) { visitor->Visit(this);	}
};
//
//New ConcreteElements
//
class Advisor : public Employee {
public:
	Advisor(string name,int salary, int vacation) :
		Employee(name, salary, vacation) {}
	void Accept(Visitor* visitor) { visitor->Visit(this);	}
};
class Conditioner : public Employee {
public:
	Conditioner(string name,int salary, int vacation) :
		Employee(name, salary, vacation) {}
	void Accept(Visitor* visitor) { visitor->Visit(this);	}
};
class Accountant : public Employee {
public:
	Accountant(string name,int salary, int vacation) :
		Employee(name, salary, vacation) {}
	void Accept(Visitor* visitor) { visitor->Visit(this);	}
};


// ObjectStructure can enumerate its elements  may provide a
// high-level interface to allow the visitor to visit its elements
// may either be a Composite (pattern) or a collection such as a
// list or a set
//
// ObjectStructure  (Employees)
class Employees {
public:
	void Add(Employee* employee){ employees.push_back(employee);};
	void Remove(Employee* employee) {
		for (unsigned int i= 0; i< employees.size(); i++) {
			if (employees[i]->getName() == employee->getName()) {
				employees.erase(employees.begin()+i);
				return;
			}
		}
	}
	void Accept(Visitor* visitor) {
		// set argument to something that helps
		// tell the Observers what happened
		for (unsigned int i = 0; i < employees.size(); i++) {
			employees[i]->Accept(visitor);
		}
	}
private:
	vector<Employee*> employees;
};

// ConcreteVisitors (IncomeVisitor, VacationVisitor)
// implements each operation declared by Visitor. Each operation implements
// a fragment of the algorithm defined for the corresponding class or object
// in the structure. ConcreteVisitor provides the context for the algorithm
// and stores its local state. This state often accumulates results during
// the traversal of the structure.
//
// "ConcreteVisitor 2"
class IncomeVisitor : public Visitor {
public:
	//To calculate total salary
	double totalsalary = 0.0;
	//To calculate average salary
	double averagesalary = 0.0;
	//To get visited employee
	int visitedperson = 0;

	void Visit(Clerk* element){
		element->setIncome(element->getIncome() * 1.10);
		cout << element->getName() + "'s new income:";
		cout << element->getIncome() << endl;
		totalsalary+=element->getIncome();
		visitedperson ++;
		averagesalary = totalsalary / visitedperson;
		cout <<"Average Salary is :"<< averagesalary << endl;
	};
	void Visit(Director* element){
		element->setIncome(element->getIncome() * 1.50);
		cout << element->getName() + "'s new income:";
		cout << element->getIncome() << endl;
		totalsalary+=element->getIncome();
		visitedperson ++;
		averagesalary = totalsalary / visitedperson;
		cout <<"Average Salary is :"<< averagesalary << endl;
	};
	void Visit(President* element){
		element->setIncome(element->getIncome() * 2.0);
		cout << element->getName() + "'s new income:";
		cout << element->getIncome() << endl;
		totalsalary+=element->getIncome();
		visitedperson ++;
		averagesalary = totalsalary / visitedperson;
		cout <<"Average Salary is :"<< averagesalary << endl;
	};
	void Visit(Advisor* element){
		element->setIncome(element->getIncome() * 2.0);
		cout << element->getName() + "'s new income:";
		cout << element->getIncome() << endl;
		totalsalary+=element->getIncome();
		visitedperson ++;
		averagesalary = totalsalary / visitedperson;
		cout <<"Average Salary is :"<< averagesalary << endl;
	};
	void Visit(Conditioner* element){
			element->setIncome(element->getIncome() * 2.0);
			cout << element->getName() + "'s new income:";
			cout << element->getIncome() << endl;
			totalsalary+=element->getIncome();
			visitedperson ++;
			averagesalary = totalsalary / visitedperson;
			cout <<"Average Salary is :"<< averagesalary << endl;
		};
	void Visit(Accountant* element){
			element->setIncome(element->getIncome() * 2.0);
			cout << element->getName() + "'s new income:";
			cout << element->getIncome() << endl;
			totalsalary+=element->getIncome();
			visitedperson ++;
			averagesalary = totalsalary / visitedperson;
			cout <<"Average Salary is :"<< averagesalary << endl;
		};
};
// "ConcreteVisitor 2"

class VacationVisitor : public Visitor {
public:
	void Visit(Clerk* element){
		// Provide 3 extra vacation days
		if(element->getIncome()>300000){
			element->setVacationDays(element->getVacationDays() + 3);
		}
		cout << element->getName() + "'s new vacation days:";
		cout << element->getVacationDays() << endl;
	};
	void Visit(Director* element){
		// Provide 5 extra vacation days
		if(element->getIncome()>300000){
			element->setVacationDays(element->getVacationDays() + 3);
		}
		cout << element->getName() + "'s new vacation days:";
		cout << element->getVacationDays() << endl;
	};
	void Visit(President* element){
		// Provide 7 extra vacation days
		if(element->getIncome()>300000){
			element->setVacationDays(element->getVacationDays() + 3);
		}
		cout << element->getName() + "'s new vacation days:";
		cout << element->getVacationDays() << endl;
	};
	//Implementation for operation for newly added ConcreteElement Conditioner.
	void Visit(Advisor* element){
		// Provide 7 extra vacation days
		if(element->getIncome()>300000){
			element->setVacationDays(element->getVacationDays() + 3);
		}
		cout << element->getName() + "'s new vacation days:";
		cout << element->getVacationDays() << endl;
	};
	//Implementation for operation for newly added ConcreteElement Conditioner.
	void Visit(Conditioner* element){
		// Provide 7 extra vacation days
		element->setVacationDays(element->getVacationDays() + 3);
		cout << element->getName() + "'s new vacation days:";
		cout << element->getVacationDays() << endl;
	};
	//Implementation for operation for newly added ConcreteElement Conditioner.
	void Visit(Accountant* element){
		// Provide 7 extra vacation days
		if(element->getIncome()>300000){
			element->setVacationDays(element->getVacationDays() + 3);
		}
		cout << element->getName() + "'s new vacation days:";
		cout << element->getVacationDays() << endl;
	};

};

int main() {

	// Setup employee collection
	Employees* e = new Employees();
	e->Add(new Clerk("Fatih Terim",200000,10));
	e->Add(new Director("Adnan Sezgin",300000,20));
	e->Add(new Accountant("Adnan Polat",400000,30));

	// Employees are 'visited'
	e->Accept(new IncomeVisitor());
	e->Accept(new VacationVisitor());

	return 0;
}
