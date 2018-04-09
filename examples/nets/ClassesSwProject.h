/******************************************************
 * File:         ClassesLwProject.h
 * Author:       Vasily I.Gurianov
 * Create date:  2018-04-02
 * Testing:      CodeGear C++Builder 2007
 *
 * Small-World Nets
 *
 * Using:
 *     Root *pWorld = new Root;
 *
 *     pWorld->Run();
 *     Label1->Caption = pWorld->probe.count;
 *     Label2->Caption = pWorld->probe.str;
 *
 * ***************************************************/

//---------------------------------------------------------------------------
#ifndef ClassesSwProjectH
#define ClassesSwProjectH

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
	 *  <<Substance>> Component class
	 *  The class is Component role in Composite pattern
	 *  ***
	 *  Concept = Social entity
	 * ***************************************************/
class Component {
public:
AnsiString name;

	virtual dataOfMeasurement measure() = 0;
	virtual void Run() = 0;
};

	/******************************************************
	 * Class:   <<Ontology Atom>> Leaf
	 *  The class is Leaf role in Composite pattern
	 *  ***
	 *  Concept = Agent
	 * ***************************************************/
class Leaf : public Component {
private:

public:
	Leaf() {
	}
	Leaf(AnsiString n) {
	name = n;
	}
	virtual void Run() {
	//ShowMessage("before: "+IntToStr(leftMessage)+"<"+IntToStr(state)+">"+IntToStr(rightMessage));
	//ShowMessage("after: <" + IntToStr(state) + ">");
	}
	virtual dataOfMeasurement measure() {
	dataOfMeasurement dm;
	dm.str = name;
	return dm;
	}

};

	/******************************************************
	 * Class:   <<Ontology Space>> Item
	 *  The class is one-to-many relation
	 *  ***
	 *  Concept = Cell of space
	 * ***************************************************/

class Item {
class Vector {
public:
	Item *link[10];  // array consist 10 points
	int link_size, max_size;
	Vector() {
	max_size = 10;
	for (int i = 0; i < max_size; i++) {
		link[i] = NULL;
	};
	link_size = 0;
	}
};
class ItemForQueue{
public:
	Item *previous, *next; // queue
	ItemForQueue() {
		previous = NULL; next = NULL;
	}
};

public:
bool visited1,visited2;
Vector *links;
ItemForQueue *iq;
Component *component;
bool marker; // marker of loop

	Item() {
	visited1 = false; visited2=false;
	marker = false;
	links = new Vector();
	iq = new ItemForQueue();
	component = NULL;
	}
	void add(Item *contact) {
		links->link[links->link_size] = contact;
		++links->link_size;
	}
};
	/******************************************************
	 *  Class:   <<Ontology Category>> Composite
	 *  The class is Composite role in Composite pattern
	 *  ***
	 *  Concept = Space of the Small-World
	 * ***************************************************/
class Composite : public Component {

public:
	//Item *finish ;
	int firs_value; int width_value; // for random
	Item *itm;  // free link

	Item *startOfGraph;

	void bfs(Item *item)  {  //  BFS (b-firstsearch)
	Item *head, *tail;  //queue
	head = item; tail = head;

	do {
		head->visited1 = true;
		ShowMessage( "Item = "+head->component->name);
		// do1() operation in node ----------------
		int random_number = firs_value + rand() % width_value;
		if (random_number <= 10) {  // to tear a near link
		itm = head; // itm is point of start DFS
		// to tear:
		Item *left = itm->links->link[0]; // left neighbor
		ShowMessage( "item = "+head->component->name +" tear of left with= "+ left->component->name);
		left->links->link[1] = NULL; --left->links->link_size;
		// start dfs process:
		do {
		dfs(head);
		dfs_restoring(head);  // restore item->visited2 attribute
		} while (itm != NULL); // while link is free
			  
		}
		// --------------------------
		// getContactList() and addContact() operations
		for (int i=0; i<head->links->link_size; i++)
			if (!head->links->link[i]->visited1)
			{
			tail->iq->next = head->links->link[i];
			tail = tail->iq->next;
			};
		head = head->iq->next; // shift head
	} while(head != tail && head != NULL);
	}

	void bfs_restoring(Item *item)  {  //  BFS (b-firstsearch)
	Item *head, *tail;  //queue
	head = item; tail = head;

	do {
		head->visited1 = false;
		ShowMessage( "- Item = "+head->component->name);
		for (int i=0; i<head->links->link_size; i++)
			if (head->links->link[i]->visited1)
			{
			tail->iq->next = head->links->link[i];
			tail = tail->iq->next;
			};
		head = head->iq->next; // u больше не доступно
	} while(head != tail && head != NULL);
	itm = NULL;
	}

	void dfs(Item *item)  {  //  DFS (depth-firstsearch)
	//ShowMessage( "Item = "+item->component->name);
	if (item->visited2)  // Если мы здесь уже были, то тут больше делать нечего
	{
		return;
	}
	//ShowMessage( "Process/Item = "+item->component->name);
	/*
	if (item == finish)
	{
		ShowMessage( The path was found Item = "+item->component->name);
		return;
	};
	*/
	item->visited2 = true;   // mark it node
	int random_number = firs_value + rand() % width_value;
	if (random_number <= 80) {
	// do2() operation
		ShowMessage( "New link/Item = "+item->component->name+" with "+ itm->component->name);
		// is there link ?
		bool there_is_link = false;
		for (int i = 0; i < itm->links->link_size; ++i)
		{  if (item == itm->links->link[i]) there_is_link = true;
		};
		if (item ==itm) there_is_link = true;
		if (!there_is_link) {
			item->add(itm);   // itm is attribute of class and  initiator of dfs process
			itm->links->link[0]=item;  //erase old link (i.e.left) and make new link
			itm = NULL;
		} else ShowMessage( "There is link = "+item->component->name);;
		return;
	} else {  };

	for (int i = 0; i < item->links->link_size; ++i)
	{
		dfs(item->links->link[i]);
		return;
	};
	return;
	}

	void dfs_restoring(Item *item)  {  //  DFS (depth-firstsearch)
	//ShowMessage( "Item = "+item->component->name);
	if (!item->visited2)
	{
		return;
	}
	item->visited2 = false;
	for (int i = 0; i < item->links->link_size; ++i)
	{
		dfs_restoring(item->links->link[i]);
		return;
	};
	return;
	}

};

	/******************************************************
	 * Class:   <<Ontology System>> Node
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Small-World
	 * ***************************************************/
class Node : public Composite {
private:
	Item *rf[10]; // for  measure()

public:

	Node() {
	// start with regular lattice with N nodes, K nearest neighbours (node degree)
	// N = 10, K = 2

		startOfGraph = new Item(); startOfGraph->component = new Leaf("0");
		startOfGraph->visited1 = false; startOfGraph->visited2 = false;
		startOfGraph->marker = true; rf[0] = startOfGraph;
		Item *t, *n;
		startOfGraph->add(NULL); t = startOfGraph; int x = 0;
		for (int i = 0; i < 9; i++) {
			n = new Item(); n->component = new Leaf(IntToStr(i+1));
			n->visited1 = false; n->visited2 = false;
			++x; rf[x] = n;   // заполняем СК
			t->add(n);  // n is right for t
			n->add(t);  // t is left for n
			t = n;
		};
		t->add(startOfGraph);   startOfGraph->links->link[0] = t;// loop
		itm = NULL; // free link
		//finish = rf[7];
		firs_value = 0; width_value = 100; // for random

		name ="Group";
	}
	virtual void Run() {
	randomize();
		//itm = startOfGraph;
		bfs(startOfGraph);
		bfs_restoring(startOfGraph);
	}



	virtual dataOfMeasurement measure() {
		double eps = 0.0; int n = 0; AnsiString s = "";
		Item *item = startOfGraph;
		for (int i = 0; i < 10; i++) {
			n++; s = s + IntToStr(rf[i]->links->link_size) + ", " ;
		};
		dataOfMeasurement d; d.length = eps; d.count = n; d.str = s;
		return d;
	}

};
	/******************************************************
	 * Class:   <<Ontology Context>> Root
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Environment
	 * ***************************************************/
class Root : public Composite {
public:
	dataOfMeasurement probe;
	Root() {
		startOfGraph = new Item;
		startOfGraph->component = new Node;
	}
	virtual dataOfMeasurement measure() {
		dataOfMeasurement d;
		d = startOfGraph->component->measure();
		return d;
		}

	virtual void Run() {

	startOfGraph->component->Run();
	probe = startOfGraph->component->measure();
	}

};
//---------------------------------------------------------------------------
#endif
