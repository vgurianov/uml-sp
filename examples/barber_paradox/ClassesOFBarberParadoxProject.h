/******************************************************
 * File:         ClassesOFBarberParadoxProject.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-10-03
 * Testing:      CodeGear C++Builder 2007
 *
 * Paradox of barber by Bertrand Russell
 * Rule is “one who shaves all those, and those only, who do not shave themselves.”
 * The question is, does the barber shave himself?
 *
 * Using:
 *     pWorld = new Node;
 *
 *     pWorld->Run();
 *	   Label1->Caption = pWorld->man->name+", beard="+IntToStr(pWorld->man->beard);
 *
 * ***************************************************/
#ifndef ClassesOFBarberParadoxProjectH
#define ClassesOFBarberParadoxProjectH

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class Component { // <<Substance>>
public:
	virtual void Run() = 0;
};
enum BeardOption {He_have_beard, He_haved};
class Leaf : public Component { //<<Ontology Atom>>
public:
	AnsiString name;
	BeardOption beard;
	Leaf *next;

	Leaf() {
	name = "?"; beard = He_haved;
	next = NULL;
	}
	Leaf(AnsiString nm) {
	name = nm; beard = He_haved;
	next = NULL;
	}
	virtual void Run() { //<<Exist>>
	beard = He_have_beard;
	}
};
class Singleton : public Leaf { //<<Ontology Atom>>
public:
	Singleton(AnsiString nm) {
	name = nm; beard = He_haved;
	next = NULL;
	}
	void shave(Leaf *client) {
		client->beard = He_haved;
	}
};
class Composite : public Component { // <<Ontology Category>>
public:
	Leaf *man;
};
class Node : public Composite { // <<Ontology System>>
private:
	Singleton *barber;
public:
	Node() {
		this->man = new Leaf("The village male");
		this->barber = new Singleton("The barber");
		man->next = barber;
		man->next->next = man;
	}
	virtual void Run() {
		man->Run();
		barber->shave(man);
		man = man->next;
	}
};

//---------------------------------------------------------------------------
#endif
