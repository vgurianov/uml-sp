/******************************************************
 * File:         ClassesOfFractalProject.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-10-30
 * Testing:      CodeGear C++Builder 2007
 *
 * Koch's snowflake
 *
 * Using:
 *     Root *pWorld = new Root;
 *
 *     pWorld->Run();
 *     dataM dm = pWorld->probeM;
 *     Label1->Caption = "eps = "+FloatToStr(dm.length )+ ", n="+IntToStr(dm.count)
 *     +", d="+FloatToStr(log(dm.count)/log(1/dm.length) );
 *
 * ***************************************************/

//---------------------------------------------------------------------------

#ifndef ClassesOfFractalProjectH
#define ClassesOfFractalProjectH

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <math.h>

//---------------------------------------------------------------------------
class dataM {
public:
	double length;
	int count;
};
	/******************************************************
	 *  Class:   <<Substance>> Component
	 *  The class is Component role in Composite pattern
	 *  ***
	 *  Concept = Topological Space
	 * ***************************************************/
class Component {
public:
	bool marker;  // end curve
	AnsiString probe;
	Component *left, *right;
	virtual dataM measure() = 0;

	virtual void Run() = 0;
};
	/******************************************************
	 * Class:   <<Ontology Atom>> TreeLeaf
	 *  The class is Leaf role in Composite pattern
	 *  ***
	 *  Concept =
	 * ***************************************************/
//enum MyColor {Blonde, Redhead, Brown};  // for Leaf
class Leaf : public Component {
public:
//	MyColor peculiarity;
//	Node *image;
//	bool result;

	Leaf() {
//	peculiarity = Brown;
	}
//	void deepCopy(Node *p);
	virtual void Run();

};
	/******************************************************
	 *  Class:   <<Ontology Category>> Composite
	 *  The class is Composite role in Composite pattern
	 *  ***
	 *  Concept = Metric Space
	 * ***************************************************/
class Composite : public Component {
public:
	double lenght;
	Component *component;

};
	/******************************************************
	 * Class:   <<Ontology System>> TreeNode
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Generator
	 * ***************************************************/
class Node : public Composite {
private:
public:
//Component *lowerTier;
	int tierNumber;
	bool isLeaf;

	Node() {
	   isLeaf = true;
	   component = NULL;
	   marker = false;
	}
	virtual void Run() {
	this->rewrite();
	probe = IntToStr(tierNumber);
	}
	void rewrite() {
	if (isLeaf) {
	Node *a, *b, *c, *d;
	a = new Node; b = new Node; c = new Node; d = new Node;
	a->tierNumber = tierNumber+1; b->tierNumber = tierNumber+1; c->tierNumber = tierNumber+1; d->tierNumber = tierNumber+1;
	double lt = lenght/3;
	a->lenght = lt; b->lenght = lt; c->lenght = lt; d->lenght = lt;
	a->right = b; b->right = c; c->right = d; d->right = NULL; // ломанная
	d->left = c; c->left = b; b->left = a; a->left = NULL;
	// восстанавливаем связанность с текущим ярусом:
	//a->left = left; d->right = right;
	//left = a; right = d;
	component = a;
	isLeaf = false;
	//ShowMessage("Create new tier # "+IntToStr(tierNumber+1));
	} else {
		Component *e = component;
		for (int i = 0; i < 4; i++) {
		e->Run();
		e = e->right;
		};
	};
	}
	virtual dataM measure() {
		double eps = 0.0; int n = 0;
		if (!isLeaf) {
		Component *e = component;
		for (int i = 0; i < 4; i++) {
		eps = e->measure().length; n= n+ e->measure().count;
		e = e->right;
		};
		} else {
		eps = this->lenght;
		n = 1;
		};
		dataM d; d.length = eps; d.count = n;
		return d;

	}

};
	/******************************************************
	 * Class:   <<Ontology Context>> TreeRoot
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Initiator
	 * ***************************************************/
class Root : public Composite {
public:
	dataM probeM;
	Root() {
		Node *a,*b,*c;
		a = new Node; b = new Node; c = new Node;
		a->tierNumber = 0; b->tierNumber = 0; c->tierNumber = 0;
		a->lenght =1.0; b->lenght =1.0; c->lenght =1.0;
		a->right = b; b->right = c; c->right = a; // triangle
		c->left = b; b->left = a; a->left = c;
		a->marker = true; // begin and end of broken line
		component = a;
	}
	virtual dataM measure() {
		double eps = 0.0; int n = 0;
		Component *e = component; int param = 3; // param = 1 - Koch curve, 3 - Koch snowflake
		for (int i = 0; i < param; i++) {
		eps = e->measure().length; n = n + e->measure().count;
//ShowMessage("eps= "+FloatToStr(eps)+", n= "+IntToStr(e->measure().count));
		e = e->right;
		};
		dataM d; d.length = eps; d.count = n;
		return d;
		}

	virtual void Run() {

	Component *c = component;
	do {
	c->Run();
	c = c->right;
	} while (!c->marker);
		  
	probeM = measure();
	}

};
//---------------------------------------------------------------------------
#endif
