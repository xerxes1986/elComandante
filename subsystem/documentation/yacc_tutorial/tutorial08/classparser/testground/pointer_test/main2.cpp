
#include <iostream>
#include <string>
using namespace std;

class super {
public:
	typedef enum {subA, subB} subtype_t;
	virtual string name() { return "super"; }
	virtual subtype_t type()=0;
};

class subA : public super {
public:
	virtual string name() { return "subA"; }
	virtual subtype_t type() { return super::subA; };
};

class subB : public super {
public:
	virtual string name() { return "subB"; }
	virtual subtype_t type() { return super::subB; };
};

void print(super* obj);	// these need to be here for print(super*) to know the others
void print(subA* obj);
void print(subB* obj);

void print(super* obj) {
	switch (obj->type()) {
	case super::subA: print(dynamic_cast<subA*>(obj)); break;
	case super::subB: print(dynamic_cast<subB*>(obj)); break;
	}
	return;
}

void print(subA* obj) {
	cout << "printA: " << obj->name() << endl;
}

void print(subB* obj) {
	cout << "printB: " << obj->name() << endl;
}

int main(void) {
	super* arr[3];
	arr[0] = new subA();
	arr[1] = new subB();
	print(arr[0]);
	print(arr[1]);
	return 0;
}
