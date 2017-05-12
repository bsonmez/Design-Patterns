//============================================================================
// Name        : LAB10.cpp
// Author      : Burak Sonmez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Investor;
// 'Subject' ==> Stock
class Stock {
public:
	virtual ~Stock(){};
	Stock(string stock_brand, double price) : stock_brand(stock_brand), _price(price) {};
	Stock(){};
	virtual void Attach (Investor* investor);
	virtual void Detach (Investor* investor);
	virtual void Notify(int _type);//Notify method takes parameter, so we can notify observers as updated and deleted
	string	getstock_brand() {return stock_brand;}
	void	setstock_brand(string value) {stock_brand = value;}
	virtual double	getPrice() {return 0;};
	virtual void setPrice(double value) {};
protected:
	string stock_brand;          // Internal Subject state
	double _price;			// Internal Subject state
	vector<Investor*> investors;
};

// 'ConcreteSubject' ==> IBM
class IBM : public Stock {
public:
	// Constructor
	IBM(string stock_brand, double price): Stock (stock_brand, price){};
	double getPrice() {return _price;}
	void setPrice(double value) {
		// Whenever a change happens to _price, notify
		// observers.
		_price = value;
		//Notification '_type' 1 is notification for an update.
	}
    ~IBM(){
		cout << "IBM stock has been deleted." << endl;
		//Notify method takes 0 as a parameter which refers for deletion.
		Notify(0);
    }

};
// 'Observer'  ==> Abstract Observer.
class Observer {
public:
	virtual ~Observer(){};
	virtual void Update(double price, string stock_brand) = 0;
	virtual void setStockPrice(Stock* stock, double price) = 0;
};
// 'ConcreteObserver' ==> Investor
class Investor : public Observer {
private:
	 Stock *_stock;
	 string _investor_name;
	 string _stock_name;     // Internal Observer state
	 double _stock_price;	 // Internal Observer state
    // Constructor
public:
	 Investor(string name): _investor_name(name) {};
	 void Update(double price, string stock_brand){
		 //takes price and stock_brand as parameter directly instead referencing
         _stock_price = price;
		 _stock_name = stock_brand;
		 cout << "Notified " + _investor_name + " of " + stock_brand + "'s " + "change to " << price << "\n";
	 }
	 Stock getStock() { return *_stock; }
	 void setStock(Stock *value) { _stock = value; }
	 string getName() { return _investor_name; }
	 //setStockPrice, observer triggers the update.
	 void setStockPrice(Stock* stock, double price) {
        cout << "Investor " << _investor_name << " changed the price to " << price << endl;
        stock -> setPrice(price);
        stock -> Notify(1);
    }
    //Notifies update after 3 changes in price.
    void ChangePriceManyTimes(Stock* stock){
    stock -> setPrice(115.5);
    stock -> setPrice(118.5);
    stock -> setPrice(111.5);
    stock -> Notify(1);
    }
};

// Register the Observers
void Stock::Attach(Investor* investor) {
      investors.push_back(investor);
}
// Unregister from the list of Observers.
void Stock::Detach(Investor* investor) {
	for (unsigned int i= 0; i< investors.size(); i++) {
		if (investors[i]->getName() == investor->getName()) {
			investors.erase(investors.begin()+i);
			return;
		}
	}
}
// Notify the Observers.
void Stock::Notify(int _type) {
	// set argument to something that helps
	// tell the Observers what happened
	//1 for update
	if(_type==1){
		for (unsigned int i = 0; i < investors.size(); i++) {
				investors[i]->Update(_price, stock_brand);
			}
	}
	//0 for deletion
	if(_type==0){
		for (unsigned int i = 0; i < investors.size(); i++) {
			investors[i]=NULL;
		cout << "All investors are notified that " << stock_brand << " is deleted." << endl;
		}
	}

}

int main() {
	  Investor* i1 = new Investor("Burak");
	  Investor* i2 = new Investor("Yaşar");

	  IBM* ibm = new IBM("IBM", 120.00);
	  ibm->Attach(i1);
      ibm->Attach(i2);

	   i1->setStockPrice(ibm,214.2);

       ibm->setPrice(121.00);
       ibm->Notify(1);
       ibm->setPrice(122.00);
       ibm->setPrice(124.00);
       ibm->Notify(1);
       ibm->Detach(i1);

       ibm->setPrice(414.1);

       delete ibm;

}
