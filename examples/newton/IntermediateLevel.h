/******************************************************
 * File:         IntermediateLevel.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-11-21
 * Testing:      CodeGear C++Builder 2007
 *
 * Сlassical mechanics
 *
 *  IntermediateLevel:
 *     class SpecialTreeNode
 *
 *     class OrdinaryTreeNode
 *
 * ***************************************************/

 //---------------------------------------------------------------------------

#ifndef IntermediateLevelH
#define IntermediateLevelH

#include "AppBaseClasses.h"

// ============== классы промежуточного слоя =========================

// исследование движения одной частицы
// Одна из двух частиц имеет бесконечную массу
class SpecialTreeNode: public AbstractTreeNode {
public:

	SpecialTreeNode() {

int r = 990;
this->buildSpace(r);

TreeLeaf *p;
// массивная частица
p = new TreeLeaf;
p->headItemOfSkip = new Skip;
p->headItemOfSkip->next = p->headItemOfSkip; // бесконечная масса
p->currentItemOfSkip = p->headItemOfSkip;
p->number = 0;
p->headItemOfJump = NULL; p->currentItemOfJump = p->headItemOfJump;
this->headOfList->left->something = p;   // в левой граничной ячейки; около базы пространства

// центр инерции
//headItemOfJump = new Jump; //headItemOfJump->direction = FORWARD;
currentItemOfJump = headItemOfJump;
//headItemOfSkip = headOfList->something->headItemOfSkip;
headItemOfSkip = new Skip; //headItemOfSkip->next = new Skip;
headItemOfSkip->next = headItemOfSkip; // тоже бесконечная масса
currentItemOfSkip = headItemOfSkip;
this->hasStableState = true;
this->isActive = false;

// система отсчета
frame = new ConcreteSubject(headOfList,0,"K0");
this->eProbe = new ObserverX(frame);
frame->observerX = eProbe;
} // SpecialTreeNode()
// ----------------------------------
	// квант существования системы
	Skip *getListOfSkip() {  // инертность системы
	// особый случай с бескончной массой
	return headItemOfSkip;
	}

};  // SpecialTreeNode class
// --------------------- /


// ============== классы промежуточного слоя =========================
// исследование движения двух частиц
// центр инерции покоится
class OrdinaryTreeNode: public AbstractTreeNode {
protected:
	int X0; // центр инерции
public:

	OrdinaryTreeNode() {
int r = 150;
this->buildSpace(r);



// система отсчета
frame = new ConcreteSubject(headOfList,0,"K0");
this->eProbe = new ObserverX(frame);
frame->observerX = eProbe;
} // SpecialTreeNode()
// ----------------------------------
Skip *getListOfSkip() {  // инертность системы
	// особый случай с бескончной массой
	return headItemOfSkip;
	}

};  //  class Couple



//---------------------------------------------------------------------------
#endif
