/*-----------------------------------------------------------------------*
 * Simulation Model "Greeting"
 *
 * filename - main.cpp
 * Author: Vasily I. Gurianov
 * Create: 2017-07-22, Last modification: 2022-06-25
 * Version: 2.0
 * Testing: Dev C++
 *
 *  Base classes definitions for Application by SimpleExample
 *
 *-----------------------------------------------------------------------*/


#include <iostream>
using namespace std;

/*-----------------------------------------------------------------------*
 * name - class Component
 *
 *  Abstract class for Composite pattern
 *  Concept = Subject of communication
 *-----------------------------------------------------------------------*/
class Component { 
private:
public:
string name;
string probe; //* <<Tool>> {Concept = Probe}
Component *next;

	void virtual Run() = 0;
// if this operation put to Component, then Component is Subject of communication
	string virtual getMessage() { //# {Concept = Send message} #//
	return 0;
}
	void virtual putMessage(string s) { //$ {Concept = Resept message} $//
	}
};
 
/*-----------------------------------------------------------------------*
 * name - class Leaf
 *
 *  Leaf class for Composite pattern
 *  Concept = Human
 *-----------------------------------------------------------------------*/
class Leaf : public Component { 
	class DialogList { // Concept = Dialogue protocol, i.e. general knowledge
	public:
		string value;
		DialogList *next;
		
		DialogList(){
		value = ""; next = NULL;
		}
	};
private:
	DialogList *memory, *cm;
	string msg;
public:
	Leaf(string s) {
	name = s;
	memory = new DialogList;
	cm = memory;
	cm->value = "Good morning. How are you?.";
	cm->next = new DialogList;
	cm->next->value = "Not bad, thank you";
	cm = memory;
	this->next = NULL;
}
	void virtual Run() {// <<Exist>>
	if (msg.size() != 0) cm = cm->next;
}
	string virtual getMessage() { //# {Concept = Send message} #//
	string rr;
	if (cm != NULL) rr = cm->value; else rr = "<end dialog>";
	return rr;
	}
	void virtual putMessage(string s) { //$ {Concept = Resept message} $//
	this->msg = s;
	}

};

/*-----------------------------------------------------------------------*
 * name - class Composite
 *
 *  Composite class for Composite pattern
 *  Concept = Dialog space
 *
 *-----------------------------------------------------------------------*/

class Composite : public Component {
private:
protected:
public:
	Component *place; // Concept = The speaker place 
	
	Composite() {
	}
};


/*-----------------------------------------------------------------------*
 * name - class Node
 *
 *  Concrete class for Composite pattern
 *  Concept = Greeting
 *-----------------------------------------------------------------------*/
class Node : public Composite {
private:
	string msg;
	void nextItem(){
	place = place->next;
	}
public:
	Node() {
	place = new Leaf("Goldsmith");
	place->next = new Leaf("Brown");
	msg="";
	}
//
void Run() { // <<Exist>>
	if (place != NULL) {
	place->putMessage(msg); place->Run(); msg = place->getMessage();
	probe = place->name + ": " + msg; // measurement (observation)
	this->nextItem();
	} else probe = "close dialog";
}
};

/*-----------------------------------------------------------------------*
 * name - class Root
 *
 *  Concrete class for Composite pattern
 *  Concept = The street (Define initial and boundary conditions for Node class)
 *
 *-----------------------------------------------------------------------*/
class Root : public Composite {
private:
public:
	Root() {
	this->place = new Node();
	}
	void Run() { // <<Exist>>
	this->place->Run();
	this->probe = this->place->probe;
	}
};

// -----------------------------------------------------------------------
// main enter point
int main(int argc, char** argv) {
	
	Composite *root = new Root();
	cout << "Step 1 " << endl;
	root->Run();
	cout << root->probe << endl;
	cout << "Step 2 " << endl;
	root->Run();
	cout << root->probe << endl;	
	cout << "Step 3 " <<  endl;
	root->Run();
	cout << root->probe << endl;	
	
	return 0;
}