#include <iostream>
#include <vector>
using namespace std;
//
// The classes and/or objects participating in this pattern are:
//
// 1. Command  (Command)
//		- declares an interface for executing an operation.
// 2. ConcreteCommand  (CalculatorCommand)
//		- defines a binding between a Receiver object and an action.
//		- implements Execute by invoking the corresponding operation(s) on Receiver
// 3. Client  (Calculator Application)
//		- creates a ConcreteCommand object and sets its receiver.
// 4. Invoker  (User)
//		- asks the command to carry out the request
// 5. Receiver  (Calculator)
//		- knows how to perform the operations associated with carrying out
//		  a request. Any class may serve as a Receiver.
//
//
// "Command"
//
class Command {
public:
	virtual void Execute() = 0;
	virtual void UnExecute() = 0;
protected:
	Command(){};
};
//
// "Receiver"
//
class Calculator {
public:
	Calculator() : current_value(0) {};
	void Action(char _operator, int operand) {
		switch(_operator) {
			case '+': current_value += operand; break;
			case '-': current_value -= operand; break;
			case '*': current_value *= operand; break;
			case '/': current_value /= operand; break;
			case '<': bool_result = ((current_value < operand) ? true : false); break;
			case '>': bool_result = ((current_value > operand) ? true : false); break;
			case '=': bool_result = ((current_value = operand) ? true : false); break;
		}
		cout << "Current value " << current_value << " (following "
			 << _operator << " " << operand << ")" << endl;
	}

		int getCurrentValue(){
			return current_value;
		};
		bool getBoolean(){
			return bool_result;
		};
private:
	int current_value;
	bool bool_result;
};
class Logical:public Command{
	virtual void Execute() = 0;
	virtual void UnExecute() = 0;
};
class CalculatorCommandSmall : public Logical {
public:
	// Constructor
	CalculatorCommandSmall(Calculator *calculator, int operand)
		: _calculator(calculator), _operator ('<'), _operand(operand) {}
	void Execute()   {
		_calculator->Action(_operator, _operand);
		cout<<_calculator->getBoolean()<<endl;
	}
	void UnExecute() {
		_calculator->Action(Undo(_operator), _operand);
	}
    // Private helper function. Needed to get the inverse operation.
private:
	char Undo(char _operator) {
		switch (_operator) {
			case '<': return '>';
			default : return ' ';
		}
	}
	Calculator*	_calculator;
	char 		_operator;
	int 		_operand;
};
class CalculatorCommandBig : public Logical {
public:
	// Constructor
	CalculatorCommandBig(Calculator *calculator, int operand)
		: _calculator(calculator), _operator ('>'), _operand(operand) {}
	void Execute()   {
		_calculator->Action(_operator, _operand);
		cout<<_calculator->getBoolean()<<endl;
	}
	void UnExecute() {
		_calculator->Action(Undo(_operator), _operand);
	}
    // Private helper function. Needed to get the inverse operation.
private:
	char Undo(char _operator) {
		switch (_operator) {
			case '>': return '<';
			default : return ' ';
		}
	}
	Calculator*	_calculator;
	char 		_operator;
	int 		_operand;
};
class CalculatorCommandEq : public Logical {
public:
	// Constructor
	CalculatorCommandEq(Calculator *calculator, int operand)
		: _calculator(calculator), _operator ('='), _operand(operand) {}
	void Execute()   {
		_calculator->Action(_operator, _operand);
		cout<<_calculator->getBoolean()<<endl;
	}
	void UnExecute() {
		_calculator->Action(Undo(_operator), _operand);
	}
    // Private helper function. Needed to get the inverse operation.
private:
	char Undo(char _operator) {
		cout<<"Its already equal"<<endl;
	}
	Calculator*	_calculator;
	char 		_operator;
	int 		_operand;
};
class Arithmetic: public Command{
public:
	virtual void Execute() = 0;
	virtual void UnExecute() = 0;

	void notification(){
		cout<<"Arithmetic Class"<<endl;
	}
};
//
// "ConcreteCommand"
//
class CalculatorCommandSum : public Arithmetic {
public:
	// Constructor
	CalculatorCommandSum(Calculator *calculator, int operand)
		: _calculator(calculator), _operator ('+'), _operand(operand) {}
	void Execute()   {
		_calculator->Action(_operator, _operand);
	}
	void UnExecute() {
		_calculator->Action(Undo(_operator), _operand);
	}
    // Private helper function. Needed to get the inverse operation.
private:
	char Undo(char _operator) {
		switch (_operator) {
			case '+': return '-';
			case '-': return '+';
			default : return ' ';
		}
	}
	Calculator*	_calculator;
	char 		_operator;
	int 		_operand;
};
class CalculatorCommandSub: public Arithmetic {
public:
	// Constructor
	CalculatorCommandSub(Calculator *calculator, int operand)
		: _calculator(calculator), _operator ('-'), _operand(operand) {}
	void Execute()   {
		_calculator->Action(_operator, _operand);
	}
	void UnExecute() {
		_calculator->Action(Undo(_operator), _operand);
	}
    // Private helper function. Needed to get the inverse operation.
private:
	char Undo(char _operator) {
		switch (_operator) {
			case '+': return '-';
			case '-': return '+';
			default : return ' ';
		}
	}
	Calculator*	_calculator;
	char 		_operator;
	int 		_operand;
};
class CalculatorCommandDiv: public Arithmetic {
public:
	// Constructor
	CalculatorCommandDiv(Calculator *calculator, int operand)
		: _calculator(calculator), _operator ('/'), _operand(operand) {}
	void Execute()   {
		_calculator->Action(_operator, _operand);
	}
	void UnExecute() {
		_calculator->Action(Undo(_operator), _operand);
	}
    // Private helper function. Needed to get the inverse operation.
private:
	char Undo(char _operator) {
		switch (_operator) {
			case '*': return '/';
			case '/': return '*';
			default : return ' ';
		}
	}
	Calculator*	_calculator;
	char 		_operator;
	int 		_operand;
};
class CalculatorCommandMul: public Arithmetic {
public:
	// Constructor
	CalculatorCommandMul(Calculator *calculator, int operand)
		: _calculator(calculator), _operator ('*'), _operand(operand) {}
	void Execute()   {
		_calculator->Action(_operator, _operand);
	}
	void UnExecute() {
		_calculator->Action(Undo(_operator), _operand);
	}
    // Private helper function. Needed to get the inverse operation.
private:
	char Undo(char _operator) {
		switch (_operator) {
			case '*': return '/';
			case '/': return '*';
			default : return ' ';
		}
	}
	Calculator*	_calculator;
	char 		_operator;
	int 		_operand;
};
// "Invoker"
class User {
public:
	User(): current(0) {};
	void Redo(int levels) {
		cout << "\n---- Redo " << levels << " levels " << endl;
		// Perform redo operations
		for (int i = 0; i < levels; i++) {
			if (current < _commands.size()) {
				Command *command = _commands[current++];
				command->Execute();
			}
		}
	}
	void Undo(int levels) {
		cout << "\n---- Undo " << levels << " levels " << endl;
		// Perform undo operations
		for (int i = 0; i < levels; i++) {
			if (current > 0) {
				Command *command = _commands[--current];
				command->UnExecute();
			}
		}
	}
	void Compute(Command *command) {
		command->Execute();
		// Add command to undo list
		_commands.push_back(command);
		current++;
	}
private:
	// Initializers.
	Calculator			*_calculator;
	vector<Command *>	_commands;
	unsigned int 				current;
};

int main()
{
	// Create user and let her compute
	Command *command = NULL;
	User *user = new User();
	Calculator *calculator = new Calculator();

	command = new CalculatorCommandSum(calculator, 100);
	user->Compute(command);
	command = new CalculatorCommandSub(calculator,  50);
	user->Compute(command);
	command = new CalculatorCommandMul(calculator,  10);
	user->Compute(command);
	command = new CalculatorCommandDiv(calculator, 2);
	user->Compute(command);
	command = new CalculatorCommandSmall(calculator, 88);
	user->Compute(command);
	command = new CalculatorCommandBig(calculator, 88);
	user->Compute(command);
	command = new CalculatorCommandEq(calculator, 250);
	user->Compute(command);
	user->Undo(4);
	// Undo 4 commands
	//user->Undo(4);
	// Redo 2 commands
	//user->Redo(2);
}

