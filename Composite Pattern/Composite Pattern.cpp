//============================================================================
// Name        : CompositePattern.cpp
// Description :
//============================================================================

#include <iostream>
#include <vector>

using namespace std;
//
// The classes and/or objects participating in this pattern are:
// 1. Component   (DrawingElement)
//		Declares the interface for objects in the composition. Implements
//      default behavior for the interface common to all classes, as
//      appropriate. declares an interface for accessing and managing its
//		child components.
// 2. Leaf   (PrimitiveElement)
//		represents leaf objects in the composition. A leaf has no children.
//	    Defines behavior for primitive objects in the composition.
// 3. Composite   (CompositeElement)
//		defines behavior for components having children. Stores child
//		components. Implements child-related operations in the Component interface.
// 4. Client  (CompositeApp)
//		Manipulates objects in the composition through the Component interface.

// This is the "Component". (i.e tree node.)

class DrawingElement {
public:
	virtual ~DrawingElement(){};
	virtual void Remove(DrawingElement *d) {};
	virtual void Display(int indent) {};
	virtual void Delete(){};
	string getName() {return name;};
protected:
	DrawingElement(string name)
						:name(name){};
private:
	string name;
};

// This is the "Leaf".

 class PrimitiveElement : public DrawingElement {
 public:
	PrimitiveElement(string name) : DrawingElement(name) {};

	void Display(int indent) {
		for(int i = 1;i <= indent;i++) { cout <<"-";}
		cout << " " << getName() << endl;
	}
		~PrimitiveElement(){
			cout << " Deleting.." << getName() << endl;
		}
};

// This is the "Composite"

class CompositeElement : public DrawingElement {

public:
	CompositeElement(string name) : DrawingElement(name) {};

	void Add(DrawingElement* d) {elements.push_back(d);};

	void Remove(DrawingElement* d) {
			for (unsigned int i= 0; i< elements.size(); i++) {
				if (elements[i]->getName() == d->getName()) {
					elements[i]->Delete();
					delete elements[i];
					elements.erase(elements.begin()+i);
					return;
				}
			}
		}
	~CompositeElement(){
				cout << " Deleting.." << getName() << endl;
			}
	void Display(int indent) {
		for(int i = 1;i <= indent;i++) { cout <<"-";}
		cout <<  "+ " + getName() << endl;

		// Display each child element on this node
		for (unsigned int i= 0; i< elements.size(); i++) {
			elements[i]->Display(indent+2);
		}
	}

	void Delete(){
		for (unsigned int i= 0; i< elements.size(); i++) {
					elements[i]->Delete();
					delete elements[i];
				}
	}
private:
	vector<DrawingElement*> elements;
};

int main()
{
	// Create a tree structure
	CompositeElement* root = new CompositeElement("Picture");
	root->Add(new PrimitiveElement("Red Line"));
	root->Add(new PrimitiveElement("Blue Circle"));
	root->Add(new PrimitiveElement("Green Box"));

	CompositeElement* comp = new CompositeElement("Two Circles");
	comp->Add(new PrimitiveElement("Black Circle"));
	comp->Add(new PrimitiveElement("White Circle"));
	root->Add(comp);
	CompositeElement* comp2 = new CompositeElement("Ziya");
			comp2->Add(new CompositeElement("Baþar"));
			comp2->Add(new CompositeElement("Özer"));
			comp->Add(comp2);

	// Add and remove a PrimitiveElement
	CompositeElement* pe = new CompositeElement("Yellow Line");
	pe->Add(new PrimitiveElement("Red Line"));
	comp2->Add(pe);

	root->Display(1);
	root->Remove(comp);
	cout << endl;
	cout << "After deletion " <<endl;
	root->Display(1);
	return 0;
}

