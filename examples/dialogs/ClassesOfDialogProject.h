/******************************************************
 * File:         ClassesOfDialogProject.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-07-22
 * Testing:      CodeGear C++Builder 2007
 *
 * Dialogue simulation
 *
 * Dialogue is a written or spoken conversational exchange
 * between two or more people.
 *
 * Using:
 *     Root *pWorld = new Root;
 *     pWorld->probe = ""; Memo1->Clear();
 *
 *     pWorld->Run();
 *     Edit1->Text = pWorld->probe; Memo1->Lines->Add(pWorld->probe);
 *
 * ***************************************************/

#ifndef ClassesOfDialogProjectH
#define ClassesOfDialogProjectH
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>

//========================================================================

	/******************************************************
	 *  Class:   <<Substance>> Component
	 *  The class is Component role in Composite pattern
	 *  ***
	 *  Concept = Subject (Subject of communication)
	 * ***************************************************/

class Component { // Concept = Subject of communication
private:
public:
AnsiString name;
AnsiString probe; //* <<Tool>> {Concept = Probe}
Component *next;
	void virtual Run() = 0;
// if this operation put to Component, then Component is Subject of communication
	AnsiString virtual getMessage() { //# {Concept = Send message} #//
	AnsiString rr = "?";
	return rr;
}
	void virtual putMessage(AnsiString s) { //$ {Concept = Resept message} $//
	}
};

	/******************************************************
	 * Class:   <<Ontology Atom>> TreeLeaf
	 *  The class is Leaf role in Composite pattern
	 *  ***
	 *  Concept = Human
	 * ***************************************************/

class Leaf : public Component { // Concept = Human
	class DialogList {
	public:
		AnsiString value;
		DialogList *next;
		DialogList(){
		value = ""; next = NULL;
		}
	};
private:
	DialogList *memory, *cm;
	AnsiString msg;
public:
	Leaf(AnsiString s) {
	name = s;
	memory = new DialogList;
	cm = memory;
	cm->value = "Good morning. How are you?.";
	cm->next = new DialogList;
	cm->next->value = "Not bad, thank you";
	cm = memory;
}
	void virtual Run() {// <<Exist>>
	if (msg.Length() != 0) cm = cm->next;
}
	AnsiString virtual getMessage() { //# {Concept = Send message} #//
	AnsiString rr;
	if (cm != NULL) rr = cm->value; else rr = "<end dialog>";
	return rr;
	}
	void virtual putMessage(AnsiString s) { //$ {Concept = Resept message} $//
	this->msg = s;
	}

};
	/******************************************************
	 *  Class:   <<Ontology Category>> Composite
	 *  The class is Composite role in Composite pattern
	 *  ***
	 *  Concept = Dialogue space
	 * ***************************************************/

class Composite : public Component {
private:
protected:
	Component *pl;
public:
	Composit() {
	}
};


	/******************************************************
	 * Class:   <<Ontology System>> Node
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Greeting dialog
	 * ***************************************************/

class Node : public Composite {
private:
	AnsiString msg;
	void nextItem(){
	pl = pl->next;
	}
public:
	Node() {
	pl = new Leaf("Goldsmith");
	pl->next = new Leaf("Brown");
	msg="";
	}
//
void Run() { // ** <<Exist>>
	if (pl != NULL) {
	pl->putMessage(msg); pl->Run(); msg = pl->getMessage();
	probe = pl->name +": "+  msg; // measurement
	this->nextItem();
	} else probe = "<close dialog>";
}
};
	/******************************************************
	 * Class:   <<Ontology Context>> Root
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Environtment
	 * ***************************************************/

class Root : public Composite {
private:
public:
	Root() {
	this->pl = new Node;
	}
	void Run() { //** <<Exist>>
	this->pl->Run();
	this->probe = this->pl->probe;
	}
};



//---------------------------------------------------------------------------
#endif
