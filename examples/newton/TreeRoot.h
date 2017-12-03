/******************************************************
 * File:         TreeRoot.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-11-21
 * Testing:      CodeGear C++Builder 2007
 *
 * Сlassical mechanics
 *
 * Using:
 *     TreeRoot *pWorld = new TreeRoot; int iTime = 0;
 *     ObserverX *eProbe = pWorld->headOfList->something->eProbe;
 *
 *     pWorld->Run();
 *     Memo1->Lines->Add(IntToStr(eProbe->iTime)+","+IntToStr(eProbe->x)+","+
 *     IntToStr(eProbe->x2)+","+IntToStr(eProbe->v)+","+eProbe->kinetic_energy+
 *     ","+eProbe->potential_energy);
 *     iTime++;
 *
 * ***************************************************/

//---------------------------------------------------------------------------


#ifndef TreeRootH
#define TreeRootH

#include "Models.h"


// ================ контекст ==========================
class TreeRoot: public Composite  {
// <<Ontology Context>> Concept = Вселенная Ньютона
// задает граничные и начальные условия
private:
	//AbstractTreeNode *mechanical_system;   // система
	//void replace(ListItem *b, Component *p) {}
	virtual void absorb(Carrier *f) {}
	virtual Component *getA() {}
	virtual Component *getB() {}
public:
int observe;  // <- наблюдение

	TreeRoot(){
		this->headOfList = new ListItem;
		this->headOfList->something = new Simple; // One particle
		//this->headOfList->something = new Spring; // Spring, one particle
		//this->headOfList->something = new SimpleCouple; //two particles
	};
	void Prepare(int r,int k1,int k2,int r1,int r2,int r3) {
	//this->headOfList->something = new AbstractTreeNode;
	//this->headOfList->something->Prepare(r,k1,k2,r1,r2,r3);
	}
	void Run() {
	this->headOfList->something->Run();
	}

	void actuate() {}
	void doImpact(Carrier *) {}
	//void move() {}
	Skip *getListOfSkip(){return 0;}
};



//---------------------------------------------------------------------------
#endif
