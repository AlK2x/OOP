#include "stdafx.h"
#include <iostream>
using namespace std;

class foo {
public:
	foo(){ Moo(); }
	virtual ~foo(){ Boo(); }
	void Boo(){ Goo(); }
	virtual void Moo(){ cout << "1"; }
	virtual void Goo(){ cout << "2"; }
};

class Bar : public foo {
public:
	Bar(){}
	~Bar(){ Baz(); }
	void Baz(){ Boo(); cout << "3"; }
	virtual void Moo(){ cout << "4"; }
	virtual void Goo(){ cout << "5"; }
};

int main(int argc, char * argv[])
{
	Bar b;
	b.Baz();
	b.Moo();
	return 0;
}

