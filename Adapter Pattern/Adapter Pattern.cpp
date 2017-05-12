//============================================================================
// Name        : LAB8.cpp
// Author      : Burak Sonmez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
// This is the "Adaptee" class.
class DisplayInterface {
public:
	virtual void adapteeConnect()=0;
	virtual void connection()=0;
};
//MiniHDMI inherited from DisplayInterface class.
class MiniHDMI : public DisplayInterface {
public:
    void adapteeConnect(){
		cout << "This is mini HDMI"<<endl;
	}
    void connection(){
    	cout << "Mini HDMI is connecting " << endl;
    }
};
//DisplayPort inherited from DisplayInterface class.
class DisplayPort : public DisplayInterface {
public:
    void adapteeConnect(){
		cout << "This is DisplayPort"<<endl;
	}
    void connection(){
    	cout << "DisplayPort is connecting " << endl;
    }
};
//DisplayPort inherited from DisplayInterface class.
class DVI : public DisplayInterface {
public:
    void adapteeConnect(){
		cout << "This is DVI"<<endl;
	}
    void connection(){
    	cout << "DVI is connecting " << endl;
    }
};



// This the  "Target" class.
class DisplayConnector {
public:
	virtual void connect()= 0;
};

class ConnectInterfaceAdapter:public DisplayConnector{
public:
	ConnectInterfaceAdapter (DisplayInterface *adaptee): _adaptee(adaptee) {};
	void connect(){
		_adaptee->adapteeConnect();
		_adaptee->connection();
	    }
protected:
	DisplayInterface *_adaptee;
};

// This is the "Adapter" class. HDMIConnecter.
class HDMIConnecter : public DisplayConnector{
public:
	void connect(){
		_adapter->connect();
    }
	HDMIConnecter (string adaptee){
		if(adaptee == "MiniHDMI"){
			 _adapter = new ConnectInterfaceAdapter(new MiniHDMI());
		}else if(adaptee == "DIV"){
			 _adapter = new ConnectInterfaceAdapter(new DVI());
		}else if(adaptee == "DisplayPort"){
			 _adapter = new ConnectInterfaceAdapter(new DisplayPort());
		}
	};
protected:
	ConnectInterfaceAdapter *_adapter;
};



int main() {

	// This is DIV
	DisplayConnector *socket2 = new ConnectInterfaceAdapter(new DVI());
	socket2->connect();


}
