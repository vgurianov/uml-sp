/******************************************************
 * File:         ClassesOfFractalProject.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-11-11
 * Testing:      CodeGear C++Builder 2007
 *
 * Multicellular organism simulation
 *
 * Axiom: A
 * Rules: xAy -> A, xAx -> B, yAy -> D, xBy -> B
 * Products: A => AA, B => BA (cell clones),
 * A -> xAy -> A => AA -> xAx yAy => B D =      (growth phase)
 * B -> xBy -> B => BA -> xBy yAy -> B D = B.   (adult organism)
 * Using:
 *     Root *pWorld = new Root;
 *
 *     pWorld->Run();
 *     Memo1->Lines->Add(pWorld->probe.str);
 *
 * ***************************************************/

#ifndef ClassesOfOrganismProjectH
#define ClassesOfOrganismProjectH

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>

//---------------------------------------------------------------------------
class dataOfMeasurement {
public:
	double length;
	int count;
	AnsiString str;
};
	/******************************************************
	 *  Class:   <<Substance>> Component
	 *  The class is Component role in Composite pattern
	 *  ***
	 *  Concept = Biont
	 * ***************************************************/
enum StateOption {A, B, D};  // states
enum Msgs {x, y};  // messages
class Component {
public:
StateOption state;
Msgs leftMessage, rightMessage;
	virtual dataOfMeasurement measure() = 0;

	virtual void Run() = 0;
};
class Dictionary {  // Concept = Genotype
	class Chain {
	public:
		Chain *next, *previous;
		Msgs leftKey, rightKey;
		StateOption keyOfState;
		StateOption value;
		Chain() {
			next = NULL; previous = NULL;
        }
	};
private:
	Chain *head;
public:
	Dictionary() {
	Chain *h1, *h2, *h3, *h4;
	 h1 = new Chain; h2 = new Chain; h3 = new Chain;h4 = new Chain;
		// it is the verification test
	 // Rules: xAy -> A, xAx -> A, yAy -> D,
	 // Products: A => AA (cell clones),
	 // A -> xAy -> A => AA -> xAx yAy => A D -> A.
	 h1->leftKey = x; h1->keyOfState = A; h1->rightKey = y; h1->value = A;
	 h2->leftKey = x; h2->keyOfState = A; h2->rightKey = x; h2->value = A;
	 h3->leftKey = y; h3->keyOfState = A; h3->rightKey = y; h3->value = D;
	 h4->leftKey = x; h4->keyOfState = B; h4->rightKey = y; h4->value = D;
	 /*
	 // Rules: xAy -> A, xAx -> B, yAy -> D, xBy -> B
	 // Products: A => AA, B => BA (cell clones),
	 // A -> xAy -> A => AA -> xAx yAy => B D =
	 // B -> xBy -> B => BA -> xBy yAy -> B D = B
	 h1->leftKey = x; h1->keyOfState = A; h1->rightKey = y; h1->value = A;
	 h2->leftKey = x; h2->keyOfState = A; h2->rightKey = x; h2->value = B;
	 h3->leftKey = y; h3->keyOfState = A; h3->rightKey = y; h3->value = D;
	 h4->leftKey = x; h4->keyOfState = B; h4->rightKey = y; h4->value = B;
	 */
	 h1->next = h2; h2->next = h3; h3->next = h4;
	 head = h1;
	}
	StateOption get( Msgs lk, Msgs rk, StateOption so) {
	StateOption state = so;
	Chain *c = head;
	while (c != NULL) {
	if (c->leftKey == lk && c->rightKey == rk && c->keyOfState == so) {state = c->value;};
	c = c->next;
	};
	return state;
	}

};
	/******************************************************
	 * Class:   <<Ontology Atom>> TreeLeaf
	 *  The class is Leaf role in Composite pattern
	 *  ***
	 *  Concept = Biological cell
	 * ***************************************************/
class Leaf : public Component {
private:
	Dictionary *dict;
public:
	Leaf() {
	state = A;
	dict = new Dictionary;
	}
	Leaf(const Component &c) {
	   state = A;
	   dict = new Dictionary;
	}
	virtual void Run() {
	//ShowMessage("before: "+IntToStr(leftMessage)+"<"+IntToStr(state)+">"+IntToStr(rightMessage));
	state = dict->get(leftMessage,rightMessage, state);
	//ShowMessage("after: <" + IntToStr(state) + ">");
	}
	virtual dataOfMeasurement measure() {
	dataOfMeasurement dm;
	return dm;
	}

};
class Item {
public:
Component *component;
Item *left, *right;
	Item() {
	left = NULL; right = NULL;
	}
};
	/******************************************************
	 *  Class:   <<Ontology Category>> Composite
	 *  The class is Composite role in Composite pattern
	 *  ***
	 *  Concept = Holobiont
	 * ***************************************************/
class Composite : public Component {
public:
	Item *headOfList;

};
	/******************************************************
	 * Class:   <<Ontology System>> Node
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Multicellular organism
	 * ***************************************************/
enum TOption {InformationPhase, FissionPhase};  // biotime
class Node : public Composite {
private:
	TOption iTime;
public:

	Node() {
		headOfList = new Item;
		headOfList->component = new Leaf;
		iTime = InformationPhase;
	}
	virtual void Run() {
	Item *item;
	if (iTime == InformationPhase) {
	// information phase
	item = headOfList;
	do {
		if (item->left != NULL) {item->left->component->rightMessage = x;
		} else item->component->leftMessage = x;  // himself
		if (item->right != NULL) {item->right->component->leftMessage = y;
		} else item->component->rightMessage = y; // himself
		item = item->right;
	} while (item !=NULL);
	item = headOfList;
	do {
		item->component->Run();
		item = item->right;
	} while (item !=NULL);

	} else { // iTime == FissionPhase
	// fission phase
	item = headOfList;
	do {
		// insert (Concept = fission cell)
		// Products: A => AA, B => BA (cell clones),
		if (item->component->state == A || item->component->state == B) {
		Component *x, *y;
		x = item->component;
		y = new Leaf;
		Item *i = new Item; i->component = y;
		i->right = item->right; item->right = i; i->left = item;
		item =i;
		};
		//  delete (Concept = apoptosis cell)
		if (item->component->state == D) {
		delete item->component;
		//if (item->left == NULL && item->right == NULL) {delete item;}
		//else {
			if (item->left != NULL) {item->left->right = item->right;
			} else item->right->left = NULL;
			if (item->right != NULL) {item->right->left = item->left;
			} else item->left->right = NULL;
		//};
		};  //if (item->component->state == D)
		
		item = item->right;
	} while (item !=NULL);
	}; // end if (iTime == InformationPhase)

	if (iTime == InformationPhase) {iTime = FissionPhase;
	} else {iTime = InformationPhase;};
	
	}
	virtual dataOfMeasurement measure() {
		double eps = 0.0; int n = 0; AnsiString s = "";
		Item *item = headOfList;
		do {
			n++; s = s + IntToStr(item->component->state);
			item = item->right;
		} while (item !=NULL);

		dataOfMeasurement d; d.length = eps; d.count = n; d.str = s;
		return d;
	}

};
	/******************************************************
	 * Class:   <<Ontology Context>> TreeRoot
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Umwelt
	 * ***************************************************/
class Root : public Composite {
public:
	dataOfMeasurement probe;
	Root() {
		headOfList = new Item;
		headOfList->component = new Node;
	}
	virtual dataOfMeasurement measure() {
		dataOfMeasurement d;
		d = headOfList->component->measure();
		return d;
		}

	virtual void Run() {

	headOfList->component->Run();
	probe = measure();
	}

};
//---------------------------------------------------------------------------
#endif

