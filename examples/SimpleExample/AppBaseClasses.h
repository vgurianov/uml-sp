/*-----------------------------------------------------------------------*
 * filename - AppBaseClasses.h
 * Autor: Vasily I. Gurianov
 *
 *  Base classes definitions for Application by SimpleExample
 *
 *-----------------------------------------------------------------------*/

#ifndef AppBaseClassesH
#define AppBaseClassesH
//---------------------------------------------------------------------------

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>

//---------------------------------------------------------------------------
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

class Composite : public Component {
private:
protected:
	Component *pl;
public:
	Composit() {
	}
};

class Node : public Composite {
private:
	AnsiString msg;
public:
	Node() {
	pl = new Leaf("Goldsmith");
	pl->next = new Leaf("Brown");
	msg="";
	}
//
void Run() { // <<Exist>>
	if (pl != NULL) {
	pl->putMessage(msg); pl->Run(); msg = pl->getMessage();
	pl = pl->next;
	probe = msg; // measurement
	} else probe = "<close dialog>";
}
};
//
class Root : public Composite {
private:
public:
	Root() {
	this->pl = new TreeNode;
	}
	void Run() { // <<Exist>>
	this->pl->Run();
	this->probe = this->pl->probe;
	}
};



//---------------------------------------------------------------------------
#endif
