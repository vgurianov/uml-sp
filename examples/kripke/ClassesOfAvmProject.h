/******************************************************
 * File:         ClassesOfAvmProject.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-10-22
 * Testing:      CodeGear C++Builder 2007
 *
 * Virtual machine
 *
 * Using:
 *     List *pWorld = new List;
 *
 *     pWorld->Run();
 *     Label1->Caption = IntToStr(pWorld->face->value);
 *
 * ***************************************************/

#ifndef ClassesOfAvmProjectH
#define ClassesOfAvmProjectH

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
namespace Data_Process {

class Component {
public:
	virtual void Run() = 0;
};
enum Values {Jane_likes_pizza, Jane_likes_not_pizza};  // for Leaf
class Node;
class Leaf : public Component {
public:
	Values value;

	Leaf() {
	value = Jane_likes_not_pizza;
	}
	virtual void Run() {}

};
class Composite : public Component {
public:
	Component *component;


};
class Node : public Composite {
private:
public:
Leaf *data;

	Node() {
		 data = new Leaf;  data->value = Jane_likes_not_pizza;
		 component = data;
	}
	virtual void Run() {
	}

};

class Root : public Composite {
public:
    Root() {
		component = new Node;
    }
	virtual void Run() {
	//component->Run();
	}

};


} //namespace Data_Process

namespace Abstract_Virtual_Machine {
using namespace Data_Process;  // it is <<import>> but need <<access>>

class Avm {
private:
	AnsiString output;
	// it is memory of virtual machine
	Leaf *data;
	void program() {
		data->Run(); // it is authorized operation for data
		output = IntToStr(data->value);
    }
public:

	Avm() {
	}
	void Run(){  // it is processor and its run
		this->program();
	}
	void input(Leaf *leaf) {
	data = leaf;
	}
	AnsiString getOutput() {
	return output;
	}
};
class Console {
private:
	Avm *avm;
	Leaf *d;
public:
AnsiString probe;

	Console() {
		avm = new Avm();
		d = new Leaf;
	}
	void Run(){ //it is macros
		avm->input(d);  // load data
		avm->Run();    // processing
		probe = avm->getOutput(); // print result
	}
};
} //namespace Abstract_Virtual_Machine
//---------------------------------------------------------------------------
#endif
