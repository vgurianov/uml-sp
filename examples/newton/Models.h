/******************************************************
 * File:         IntermediateLevel.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-11-21
 * Testing:      CodeGear C++Builder 2007
 *
 * Сlassical mechanics
 * body with infinite mass
 * Concrete classes of models:
 *     classSimple - costant force
 *
 *     TreeNodeForSpringProject  - spring
 *
 *     class SimpleCouple - two particles interact as costant force
 *
 * ***************************************************/


//---------------------------------------------------------------------------

#ifndef ModelsH
#define ModelsH

#include "IntermediateLevel.h"
// ============== конкретные классы ===================
// прямое взаимодействие
class Simple: public SpecialTreeNode {
private:
public:
// ---------------------------------------
// самое простое взаимодействие
//Затем был выполнен эксперимент с разрешением l = 10, m = 10 , t = 50.
//Тогда m=10 г (1 элм), сила F=9800 дин (980 актов взм.).
	//void interact() {ShowMessage( "->х = ");}
	void interact() { //Concept = Взаимодействовать
// агент силы
Carrier *f = new Carrier; f->direction = FORWARD;

ListItem *b; Component *p;
//  в базе (headOfList->left) находится перая (массивная) частица
//  1. ишем вторую (легкую) частицу
b = headOfList; bool done = true;
do {
		if (b->something != NULL) { // есть частица
			p = b->something;
			done = false;
		};
b = b->right;
} while (done);
for (int i = 0; i < 10000; i++) {  //390
// пара взаимодействия
p->doImpact(f);  // изменил напрвление
headOfList->left->something->doImpact(f);  // вернулся к исходному
};
delete f;
} // end void interact()

	Simple():SpecialTreeNode() {
// частица
TreeLeaf *p; p = new TreeLeaf(500); // ед. масса
p->currentItemOfSkip = p->headItemOfSkip;
p->number = 1;
p->currentItemOfJump = p->headItemOfJump;  // покоится
this->headOfList->something = p; // в базе
	}
};

// модель пружины
class TreeNodeForSpringProject: public SpecialTreeNode {
private:
public:
// ---------------------------------------
	//void interact() {ShowMessage( "->х = ");}
// -----------------------------------------------
// модель пружины
	void interact() { //Concept = Взаимодействовать
//масса m = 500 г (500=499+1 skip), жесткость пружины k = 200000 дин/см (200 н/м).
//В начальный момент x = 0,1 см (в x = 0 находится тело с бесконечной массой) и имеет
//начальную скорость V0 = 100 см/с  (100*10/50 = 20 jump)
// T/2 = 0,16 с, амплитуда A = 5 см. x = ASin(om*t)

//nl = 10, nm = 1, nt = 50
//k = F/l = nm* (nl/nt2)/nl* F'/l'= nm*nt2 * k'.
// k' = k/(nm*nt2) = 200000/(1*50*50) = 80 генераций

ListItem *b; Component *p; Carrier *q;
//  в базе (headOfList) находится перая (массивная) частица
//  1. ишем вторую (легкую) частицу
b = headOfList; bool done = true;
do {
b = b->right;
		if (b->something != NULL) { // есть частица
			p = b->something;
			done = false;
		};
} while (done);
// задаем жескость пружины
Temp *t, *k; k = new Temp; t = k;
for (int i = 0; i < 80; i++) {
t->next = new Temp;
t = t->next;
}
// 2. взаимодействуем
b = headOfList; done = true; int i = 0; int random_value;
q = new Carrier(BACKWARD);

do { b = b->right; //b=b->right; // сместим 0 точку
// более жесткая пружина
t = k;
do { p->doImpact(q); headOfList->something->doImpact(q); // пара взаимодействия
i++; t = t->next;
} while (t != NULL);
/* ----------------------
random_value = 0 + rand()%2;
if (random_value == 1) {p->doImpact(q); headOfList->something->doImpact(q);};
*/ //----------------------

// менее жесткая пружина (цикл вынесен за пределы цикла)
/*
if (tt == NULL) {p->doImpact(q); headOfList->something->doImpact(q);
tt = kk;
} else {
if (t2 == NULL) {p->doImpact(q); headOfList->something->doImpact(q);
t2 = k2; } else { t2 = t2->next; };
tt = tt->next;
};
*/
		if (b->something != NULL) { // есть частица
			done = false;
		};
} while (done);
delete q;
//ShowMessage( "acts = "+IntToStr(i));
} // end void interact()  ------------------------

	TreeNodeForSpringProject():SpecialTreeNode() {
// частица
TreeLeaf *p; p = new TreeLeaf(500); // ед. масса
p->currentItemOfSkip = p->headItemOfSkip;
p->number = 1;
//p->headItemOfJump = new Jump; p->headItemOfJump->direction = FORWARD; //ед.скорость
//Эксперимент 1. начальную скорость V0 = 100 см/с  (100*10/50 = 20 jump)
Jump *j, *jj; jj = new Jump; jj->direction = FORWARD;
j = jj;
for (int i = 0; i < 19; i++) {
j->next = new Jump; j->next->direction = FORWARD;
j=j->next;
};
p->headItemOfJump = jj;
p->currentItemOfJump = p->headItemOfJump;
this->headOfList->right->something = p; // в соседней ячейке
	}
};

// самое простое взаимодействие
class SimpleCouple: public OrdinaryTreeNode {
private:
public:
// ---------------------------------------
// самое простое взаимодействие
	//void interact() {ShowMessage( "->х = ");}
	void interact() { //Concept = Взаимодействовать

ListItem *b; Component *p1, *p2;
//  ишем тяжелую частицу
b = m[X0]; bool done = true;
do {
b = b->left;
		if (b->something != NULL) { // есть частица
			p1 = b->something;
			done = false;
		};
} while (done);
//  ишем легкую частицу
b = m[X0]; done = true;
do {
b = b->right;
		if (b->something != NULL) { // есть частица
			p2 = b->something;
			done = false;
		};
} while (done);
// агент силы
Carrier *f = new Carrier; f->direction = FORWARD;
for (int i = 0; i < 2; i++) {
// пара взаимодействия
p2->doImpact(f);  // изменил напрвление
p1->doImpact(f);  // вернулся к исходному
};
delete f;
} // end void interact()

	SimpleCouple():OrdinaryTreeNode() {

	X0 = 50; // координаты центра инерции 50 ячейка
// 0 1 ... 49 50 51
// _ _ ...  1 _ 2

TreeLeaf *p;
// массивная частица
p = new TreeLeaf;
p->headItemOfSkip = new Skip;  // m=2
p->currentItemOfSkip = p->headItemOfSkip;
p->number = 1;
p->headItemOfJump = NULL; p->currentItemOfJump = p->headItemOfJump;
//this->headOfList->something = p;   // в базе пространства
this->m[X0-1]->something = p;
// легкая частица
p = new TreeLeaf; // m=1
p->currentItemOfSkip = p->headItemOfSkip;
p->number = 2;
p->headItemOfJump = NULL; p->currentItemOfJump = p->headItemOfJump;
//this->headOfList->something = p;   // в базе пространства
this->m[X0+2]->something = p;  // m1*x1 = m2*x2

// центр инерции
//headItemOfJump = new Jump; //headItemOfJump->direction = FORWARD;
currentItemOfJump = headItemOfJump;
//headItemOfSkip = headOfList->something->headItemOfSkip;
headItemOfSkip = new Skip;
headItemOfSkip->next = new Skip;  //m=3
currentItemOfSkip = headItemOfSkip;
	}
};

//---------------------------------------------------------------------------
#endif
