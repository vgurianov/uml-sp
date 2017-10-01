/******************************************************
 * File:         ClassesOfMinskyProject.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-09-29
 * Testing:      CodeGear C++Builder 2007
 *
 * Minsky's cube model
 *
 * Using:
 *     List *pWorld = new List;
 *
 *     pWorld->Run();
 *     Label1->Caption = IntToStr(pWorld->face->value);
 *
 * ***************************************************/
#ifndef ClassesOfMinskyProjectH
#define ClassesOfMinskyProjectH

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>

//---------------------------------------------------------------------------
	// values to Item
	enum Values {A, B, C, D, EMPTY};

    /******************************************************
	 * Class:   <<Ontology Atom>> ItemOfList
     * 
     * Class is an item of linked list
     * ** this class is a slot facet of the "List" frame
     * 
     * ***************************************************/
	class ItemOfList  {
		public:
		 ItemOfList *left, *right;
		 Values value;
		 ItemOfList() {
			value = EMPTY;
			left = NULL; right = NULL;
		}
		ItemOfList(Values s) {
			this->value = s;
			left = NULL; right = NULL;
        }

	};
    /******************************************************
	 * Class:   <<Ontology system>> List
     * 
     *	Class is a main class
     * ** this class is a model of cube
     * ***************************************************/
	class List {
		private:
		 void next() { //** move
			currentItem = currentItem->right;
		}
		 void previouse() { //** back move
			currentItem = currentItem->left;
		}
		public:
		ItemOfList *currentItem;  // ** face

		List() {
		ItemOfList *a, *b, *c, *d;
		a = new ItemOfList(A); b = new ItemOfList(B); c = new ItemOfList(C); d = new ItemOfList(D);
		a->right = b; b->right = c; c->right = d; d->right = a;
		a->left = d; b->left = a; c->left = b; d->left = c;
		currentItem = a;
		}
		void Run() { // <<Exist>>
			//ShowMessage( "Visible: "+IntToStr(a->value));
			this->next();
		}
	};
//---------------------------------------------------------------------------
#endif
