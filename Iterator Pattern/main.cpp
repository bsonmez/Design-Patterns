//============================================================================
// Name        : IteratorPattern2.cpp
// Description : Implements the Collection Iterator and the client code.
//============================================================================
#include "Iterator2.h"

using namespace std;

CollectionIterator::CollectionIterator(const Collection *collection) :
_collection(collection), _current(0) {
}
void CollectionIterator::First() {
    _current = 0;
}
void CollectionIterator::Next()  {
    _current++;
}
Item *CollectionIterator::CurrentItem() const {
    return (IsDone()?NULL:_collection->get(_current));
}
bool CollectionIterator::IsDone() const {
    return _current >= _collection->getCount();
}

void printAggregate(AbstractIterator& i) {
    cout << "Iterating over collection:" << endl;
    for(i.First();  !i.IsDone(); i.Next()) {
        cout << i.CurrentItem()->getName() << endl;
    }
    cout << endl;
}
int main()
{
    // Create Aggregate.
    AbstractAggregate *aggregate = new Collection();
    aggregate->add(new Item("Fight Club",1,15));
    aggregate->add(new Item("Kinder",2,5));
    aggregate->add(new Item("Cam Sil",3,1));

    
    // Create Iterator
    AbstractIterator *iterator = aggregate->CreateIterator();
    
    // Traverse the Aggregate.
    printAggregate(*iterator);
    delete iterator;
}
