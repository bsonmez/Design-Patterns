// Iterator.h
//
// Iterator pattern:
//
// Provide a way to access the elements of an aggregate object
// sequentially without exposing its underlying representation.
//
// The classes and/or objects participating in this pattern are:

// 1. Iterator  (AbstractIterator)
//		defines an interface for accessing and traversing elements.
// 2. ConcreteIterator  (Iterator)
//		implements the Iterator interface.
//		keeps track of the current position in the traversal of the aggregate.
// 3. Aggregate  (AbstractCollection)
//		defines an interface for creating an Iterator object
// 4. ConcreteAggregate  (Collection)
//		implements the Iterator creation interface to return an instance of the proper ConcreteIterator
//
#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iostream>
#include <vector>
using namespace std;

//
// Our concrete collection consists of Items.
//

class Item {
public:
    Item(string name,int type,float price): _name(name) {
        type = _type;
        price = _price;
        
    };
    
    string getName() { return _name;};

private:
    string _name;
    float _price;
    int _type;
};
class Book:public Item {
public:
    Book(string name,int type,float price):Item(name,1,price){};
};
class Food:public Item{
public:
    Food(string name,int type,float price):Item(name,2,price){};

};
class Cleaning:public Item{
public:
    Cleaning(string name,int type,float price):Item(name,3,price){};
};
//
// This is the abstract "Iterator".
//		AbstractIterator
//

class AbstractIterator {
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone () const = 0;
    virtual Item* CurrentItem() const = 0 ;
protected:
    AbstractIterator(){};
};

// Forward Declaration of Collection

class Collection;
//
// This is the "concrete" Iterator for collection.
//		CollectionIterator
//

class CollectionIterator : public AbstractIterator {
public:
    CollectionIterator(const Collection *collection);
    void First();
    void Next();
    Item* CurrentItem() const;
    bool IsDone()const ;
private:
    const Collection *_collection;
    int _current;
};

//
// This is the abstract "Aggregate".
//			AbstractAggregate
//

class AbstractAggregate {
public:
    virtual ~AbstractAggregate(){};
    virtual AbstractIterator* CreateIterator() = 0;
    virtual void add(Item *) = 0; 		// Not needed for iteration.
    virtual int getCount () const = 0; // Needed for iteration.
    virtual Item * get(int) const = 0; // Needed for iteration.
protected:
    AbstractAggregate(){};
};

//
// This is the concrete Aggregate.
//			Collection
//

class Collection : public AbstractAggregate {
private:
    vector<Item*> _items;
public:
    CollectionIterator* CreateIterator() {
        return new CollectionIterator(this);
    }
    int getCount () const {return _items.size(); }
    void add(Item *item) {_items.push_back(item);};
    Item * get(int index) const { return _items[index];};
};

#endif /* ITERATOR_H_ */
