/******************************************************
 * File:         AppBaseClasses.h
 * Author:       Vasily I.Gurianov
 * Create date:  2017-11-21
 * Testing:      CodeGear C++Builder 2007
 *
 * Сlassical mechanics
 *
 *
 *
 *
 *
 *
 * ***************************************************/

//---------------------------------------------------------------------------

#ifndef AppBaseClassesH
#define AppBaseClassesH

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
// -------------------------------------------

enum DirectionOption {FORWARD, BACKWARD};
class Jump;
class Carrier {
public:
DirectionOption direction;
	Carrier(){direction = NULL;}
	Carrier(DirectionOption d){direction = d;}
	Carrier(Carrier *f) {direction = f->direction;}  // копирующий конструктор
	Carrier(Jump *); //?
	Jump createJump(); // возможно

};
class Jump {
public:
	DirectionOption direction;
	Jump *next;
	Jump() {next = NULL;}
	Jump(Carrier *f) {
    direction = f->direction;
	next = NULL;}
};
class Skip { // масса
public:
	Skip *next;
	Skip() {next = NULL;}
};
class Temp { // пульсации
public:
	Temp *next;
	Temp() {next = NULL;}
};
//---------------------------------------------------------------------------

	/******************************************************
	 *  Class:   <<Substance>> Component
	 *  The class is Component role in Composite pattern
	 *  ***
	 *  Concept = Matter
	 * ***************************************************/
class ObserverX;
class Component {
// Субстанциональный класс  <<Substance>> Concept = Вещество
private:

	void squeeze() {
	// Concept = self-organization of the list
	if (headItemOfJump->next != NULL) {
	if (headItemOfJump->direction != headItemOfJump->next->direction) {
	Jump *n;
	n = headItemOfJump; headItemOfJump = headItemOfJump->next; delete n;
	n = headItemOfJump; headItemOfJump = headItemOfJump->next; delete n;
	}; };
	}
	void changeMove(Carrier *f) {
	// Concept = Генерировать движение
	Jump *n = new Jump(f);
	n->next = headItemOfJump; headItemOfJump = n;
	squeeze();
	currentItemOfJump = headItemOfJump;
	}
protected:
Carrier *rebound;
	//virtual void replace(ListItem *, Component *) = 0;
	virtual Skip *getListOfSkip() = 0;
	virtual void absorb(Carrier *f) = 0;
	//virtual void put(Component *) = 0;
public:
ObserverX *eProbe; // probe
int number;   // instrument
AnsiString CreateDetect, DestroyDetect;

	Skip *headItemOfSkip, *currentItemOfSkip; // ** Concept = The inertial mass
	Jump *headItemOfJump, *currentItemOfJump; // ** Concept = Resource of motion
	bool isActive;    // ** Concept = Activity/Passivity state
	bool hasStableState; // ** Concept =  Stable/Unstable state

	virtual void Run() = 0;
	virtual void actuate()= 0;
	virtual void doImpact(Carrier *f) {
	// ** Concept = Influence, Newton's second law
if (currentItemOfSkip == NULL) {
	changeMove(f);
	currentItemOfSkip = getListOfSkip();
} else {currentItemOfSkip = currentItemOfSkip->next;};
absorb(f);
	}
	//virtual void move() = 0;
	virtual void listShift() = 0;
	virtual void listInversion(int) = 0;
	virtual void Prepare(int, int, int, int,int,int) = 0;
	virtual Component *getA() = 0;
	virtual Component *getB() = 0;
};

	/******************************************************
	 * Class:   <<Ontology Atom>> TreeLeaf
	 *  The class is Leaf role in Composite pattern
	 *  ***
	 *  Concept = Point particle
	 * ***************************************************/
class TreeLeaf: public Component {
private:
	virtual void listShift() {}
	virtual void listInversion(int) {}
	Skip *getListOfSkip() {
		return headItemOfSkip;
	}
	virtual void absorb(Carrier *f) {
	if (f != NULL) {
	if (f->direction == FORWARD) {f->direction = BACKWARD;}
	else f->direction = FORWARD;
	};
	}
	virtual Component *getA() {}
	virtual Component *getB() {}

public:
	TreeLeaf();
	TreeLeaf(int mm);
	void Run(){
		//if (currentItemOfJump->next != NULL) {
		if (currentItemOfJump != NULL) {
			currentItemOfJump = currentItemOfJump->next;
		} else {isActive = false;};
	}
	void actuate() {
	if (headItemOfJump != NULL) {isActive = true; };
	currentItemOfJump = headItemOfJump;
	}
	void Prepare(int r,int k1,int k2,int r1,int r2,int r3) {}

};
	/******************************************************
	 *  Class:   <<Space>> ListItem
	 *  The class is Component role in Composite pattern
	 *  ***
	 *  Concept = Cell of space
	 * ***************************************************/
class ListItem {
public:
ListItem *left, *right;
Component *something;

	bool isDisable;  // design, pure syntetic
	int x; // space marking - epistemology entity

	ListItem() {isDisable = false; something = NULL;
	left = NULL; right = NULL;
	}

	//Component extract() { Component p = &something;
	//something = NULL; return p;}
	void put(Component *p){this->something = p;}
	Component *get(){
	//Component f = *this->something;
	//this->something = NULL;
	return this->something;
	}
};

	/******************************************************
	 * Class:   <<>> Observer
	 *  The class is Observer role in Observer pattern
	 *  ***
	 *  Concept =  Измерительная установка
	 * ***************************************************/
class Subject;
class Observer { // датчик
public:
AnsiString scanSpace;
int iTime, x, v, a, x2;
int imp, kinetic_energy, potential_energy;
AnsiString name_sk;
AnsiString CreateDetect, DestroyDetect;

	virtual void Update(Subject *cs) = 0;
};
class ObserverX : public Observer { // датчик положения
private:
	Subject *_subject;
public:
	ObserverX(Subject *s);
	virtual void Update(Subject *cs);

};
class ObserverV : public Observer { // датчик скорости
private:
	Subject *_subject;
public:
	ObserverV(Subject *s);
	virtual void Update(Subject *cs);

};

	/******************************************************
	 * Class:   <<>> Subject
	 *  The class is Subject role in Observer pattern
	 *  ***
	 *  Concept =  Измерительная установка
	 * ***************************************************/
class Subject {
public:
ListItem *rf[1000];
ObserverX *observerX; // датчик положения
ObserverV *observerV; // датчик чего то
int x, x0, v, v0, a;
int x2, imp, kinetic_energy, potential_energy;
int iTime;
AnsiString Caption;
AnsiString CreateDetect, DestroyDetect;

	void Notify() {
		observerX->Update(this);
    } 
};
class ConcreteSubject : public Subject { //Frame Of Reference
public:
int Vf;


	ConcreteSubject(ListItem *c, int v, AnsiString cap) { Caption = cap;
	x0 = 0; v0 = 0;  iTime = 0;
	
		this->Vf = v;
		ListItem *t = c;
		int i = 0;
		do { rf[i] = t;
		t = t->right; i++;
		} while (t != NULL);
	}
	void remap() {
	//x = location_p(1);

	//ListItem *m[150];
	/*
	for (int i = 0; i < 150; i++) m[i] = NULL;

		if (Vf>0) {
		for (int i = 0; i < 150-Vf; i++) m[i] = rf[i+Vf];
		for (int i = 0; i < 150; i++) rf[i] = NULL;
		for (int i = 0; i < 150; i++) rf[i] = m[i];
		};
	*/
	//this->
	imp = pulse_measure(1);
	// для одной частице
	kinetic_energy = kinetic_energy_m(1);
	//potential_energy = potential_energy_m(1);
	// для 2-х частиц
	//kinetic_energy = kinetic_energy_m();
	//potential_energy = potential_energy_m(rf[0]);
	x = location_p(1);//x2 = location_p(2);
	v0 = v; v = velocity(1);
	a = v - v0;
	iTime++;
	this->Notify();
	}

	int location_p(int p_num) {
	/*
	for (int i = 0; i < 150; i++) {
	if (rf[i] != NULL) {
		if (rf[i]->something != NULL) {
			if (rf[i]->something->number == p_num) {return i ;};
	}; 	}; 	};
	*/
ListItem *b;
// туда
b = rf[0]; int xx = 0;
do {
	if (b->something != NULL) { // есть частица
			if (b->something->number == p_num) return xx;	};
b = b->right; xx++;
} while (b != NULL);
// обратно
b = rf[0]; xx = 0;
do {
	if (b->something != NULL) { if (b->something->number == p_num) return xx; 	};
b = b->left; xx--;
} while (b != NULL);
	ShowMessage( Caption+"location_p("+IntToStr(p_num)+") не найдена");
	return -666;
}


	int velocity(int p_num) { int return_value = 0;

ListItem *b,*b0; b = rf[0]; bool done = true;
while (b->left != NULL) {b = b->left;};  // ищем начало
do { if (b->something != NULL) { if (b->something->number == p_num) done = false; 	};
b0 = b; b = b->right;
} while ( b != NULL && done);
Component *p;
if (done) {ShowMessage( Caption+"velocity("+IntToStr(p_num)+") не найдена"); return -666;
} else p = b0->something;

	Jump *c; c = p->headItemOfJump;
	return_value = 0;
	while (c != NULL) {
		return_value++;
	c = c->next;
	};

	return return_value;
}

	int pulse_measure(int p_num) { int return_value = 0;
	// метод симуляции
	// кол-во актов что бы остановить частицу
ListItem *b,*b0; b = rf[0]; bool done = true;
while (b->left != NULL) {b = b->left;};  // ищем начало
do { if (b->something != NULL) { if (b->something->number == p_num) done = false; 	};
b0 = b; b = b->right;
} while ( b != NULL && done);
Component *p ;
if (done) {ShowMessage( Caption+" pulse_measure("+IntToStr(p_num)+") не найдена"); return -666;
} else { p = b0->something;};

	Jump *c; c = p->headItemOfJump; Skip *s; s = p->headItemOfSkip;
	return_value = 0;
	while (c != NULL) {
    	return_value++;
		s = p->headItemOfSkip;
		while (s != NULL) {
			return_value++;
		s = s->next;
		};
	c = c->next;
	};
	return return_value;
}

	int kinetic_energy_m(int p_num) {
	// метод симуляции  контроль e= p2/2m
	// симулируем торможение до остановки
	// подсчитываем сумму работ на каждом dt
	// F*ds = F*v*dt
ListItem *b,*b0; b = rf[0]; bool done = true;
while (b->left != NULL) {b = b->left;};  // ищем начало
do { if (b->something != NULL) { if (b->something->number == p_num) done = false; 	};
b0=b; b = b->right;
} while ( b != NULL && done);
if (done) {ShowMessage( Caption+": kinetic_energy_m("+IntToStr(p_num)+") не найдена"); return -1;};
Component *p = b0->something;

	Jump *c0, *c; c0 = p->headItemOfJump;
	Skip *s; s = p->headItemOfSkip;
	int return_value = 0;
	while (c0 != NULL) {
	// задает ряд F*v0 + F*v1 + F*v2 + … + F*0
	c = c0;
	while (c != NULL) {
		return_value++;
		s = p->headItemOfSkip;
		while (s != NULL) {
		return_value++;
		s = s->next;
		};

		c = c->next;
	};
	c0 = c0->next; // затормозили на один элемент
	}; //while (c0 != NULL)
	return return_value;
}
	int potential_energy_m(int p_num) {
	// метод симуляции
	// симулируем смещение с ед.шагом
	// считаем работу силы при этом Ai = Fi*ds
	// до некоторой точки, где 0 потенциала
	//  за 0 возмем точку, где частица покоилась, это 3 ячейка от начала
	int x = location_p(p_num);
	Component *p;
	p = rf[x]->something;

	ListItem *c; int return_value = 0;
	c = rf[x];  // точка, где находится частица
	// перемещений меньше на 1 чем ячеек
	while (c->left->left != NULL) { //смотрим на две ячейки
	// симулируем действие силы в точке c
	for (int i = 0; i < 1000; i++) {
	// пара взаимодействия
	//p->doImpact(f);  // изменил напрвление
	//space->something->doImpact(f);  // вернулся к исходному
	return_value++;
	};
	c = c->left; // идем к началу списка
	};

	return return_value;
}
	int kinetic_energy_m() {

	int return_value;
	return_value= kinetic_energy_m(1);
	return_value = return_value+kinetic_energy_m(2);
	return return_value;
}


	int potential_energy_m(ListItem *sp) {
	// метод симуляции
	// симулируем смещение с ед.шагом
	// считаем работу силы при этом Ai = Fi*ds
	// до некоторой точки, где 0 потенциала
	//  за 0 возмем точку, где частица покоилась, это 3 ячейка от начала
	//X0 = 50; // координаты центра инерции 50 ячейка

	ListItem *c; c = sp;
	int return_value = 0;
	bool key = false;
	// перемещений меньше на 1 чем ячеек
	while (c != NULL) {
	// всего две частицы, поэтому просто переключение
	if (c->something != NULL) {if (!key) {key = true;} else {key = false;};
	};
	if (key) {
	// симулируем действие силы в точке c
	for (int i = 0; i < 2; i++) {
	// пара взаимодействия
	//p2->doImpact(f);  // изменил напрвление
	//p1->doImpact(f);  // вернулся к исходному
	return_value++;
	};
	};
	c = c->right; // идем к началу списка
	};

	return return_value;
}

};




	/******************************************************
	 *  Class:   <<Ontology Category>> Composite
	 *  The class is Composite role in Composite pattern
	 *  ***
	 *  Concept = Physical space
	 * ***************************************************/
class Composite : public Component {
public:
ListItem *m[1000]; int N; // lattice - epistemology entity
ConcreteSubject *frame;   // frame - epistemology entity

ListItem *headOfList;  // ** base of space
ListItem *tailOfList;  // ** anchor point

	void listShift() {
	if (headItemOfJump != NULL) {
	if (currentItemOfJump->direction == FORWARD ) {
	while (currentItemOfJump != NULL) {
	headOfList = headOfList->right;
	currentItemOfJump=currentItemOfJump->next;};};
	currentItemOfJump = headItemOfJump;
	if (currentItemOfJump->direction == BACKWARD) {
	while (currentItemOfJump != NULL) {headOfList = headOfList->left;
	currentItemOfJump=currentItemOfJump->next;};};
    };
	currentItemOfJump = headItemOfJump;
	//ShowMessage( "base in "+IntToStr(headOfList->x));

	}
	void listInversion(int) {	}
	void buildSpace(int j) {
	for (int i = 0; i < 1000; i++) m[i] = NULL;
	// space assembly
	N = j;  // N - resolution of space
	for (int i = 0; i < N; i++) {
		m[i] = new ListItem; m[i]->x = i;
	};
	ListItem *a;
	for (int i = 0; i < N; i++) {
	a = m[i];
	if (i<N-1) a->right = m[i+1]; if (i>0) a->left = m[i-1];
	};
	headOfList = m[1];  // base of space
	tailOfList = m[N-1];  // anchor point
	}
};

	/******************************************************
	 * Class:   <<Ontology Context>> TreeRoot
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept =  Mechanical system
	 * ***************************************************/
class AbstractTreeNode: public Composite  {
private:
	void reviveCells();

	Component *replace(ListItem *b, Component *p);
	void clearOfSkip();
	void addOfSkip(Component *s);
	void move();

	void actuate();

protected:
	virtual void absorb(Carrier *f) {
ListItem *previous; ListItem *b;
this->reviveCells(); // activate all cells
// 1. Распределяем агентов силы по частицам
// туда
b = headOfList;
do {
	if (!b->isDisable) { // ячейка не обработана
		if (b->something != NULL) { // есть частица
		b->something->doImpact(f);
		rebound = f;  // f изменен
		};
	b->isDisable = true;  // пометить ячейку как обработанную
	};
previous = b;
b = b->right;
} while (b != NULL);
// обратно
b = previous;
do {
	if (!b->isDisable) { // ячейка не обработана
		if (b->something != NULL) { // есть частица
		b->something->doImpact(f);
		rebound = f;
		};
	b->isDisable = true;  // пометить ячейку как обработанную
	};
b = b->left;
} while (b != NULL);

    }
	virtual void interact() = 0; //{ShowMessage( "->х = ");}
	virtual void bump(ListItem *b){ // столкнуться
	// абсолютно упругое столкновение
	// использован метод эквивалентной замены алгоритма
	Component *p = b->something;
ShowMessage( "AbstractTreeNode:Bump p = "+IntToStr(p->number));
Jump *j = p->headItemOfJump;
while (j != NULL) {
if (j->direction = FORWARD) j->direction = BACKWARD;
else j->direction = FORWARD;
j=j->next;};
}
	virtual void Stabilize() { hasStableState = true;}
	virtual Component *getA() {
	ListItem *a,*b;
	a = headOfList; while (a->left != NULL) {a = a->left;}; // ищем начало
	// ищем первую частицу (A)
	b = a; while (b != NULL) {
	if (b->something != NULL) return b->something;
	b = b->right;};
	return 0;
	}
	virtual Component *getB() {
	ListItem *a,*b;
	a = headOfList; while (a->left != NULL) {a = a->left;}; // ищем начало
	int k = 0;
	// ищем первую частицу (A)
	b = a;
	while (b != NULL && k==0) {
	if (b->something != NULL) k++;
	b = b->right;};
	// ищем вторую частицу (B)
	while (b != NULL && k==1) {
	if (b->something != NULL) {k++; return b->something;};
	b = b->right;};

	return 0;
	}

public:
	AbstractTreeNode() 	{
	// schematic description of the birth of the system
	this->headItemOfJump = NULL; currentItemOfJump = NULL;
	hasStableState = true;
	} // AbstractTreeNode()

	void Prepare(int r,int k1,int k2,int r1,int r2,int r3) { // приготовит начальное состояние
this->buildSpace(r);
this->space2 = new ListItem;
//частица
//TreeLeaf *p = new TreeLeaf(500);
//p->headItemOfSkip = new Skip;
// колесо
//Component *p = new Wheel;
Jump *j, *jj; jj = new Jump; jj->direction = FORWARD;
//j = jj;
//for (int i = 0; i < 3; i++) {
//j->next = new Jump; j->next->direction = FORWARD;
//j=j->next;
//};
//p->headItemOfJump = jj;
//p->number = 1; // это э
//p->actuate();
//headOfList->something = p;
}
// -----------------------------------------------------------
	void Run() { //  ** quantum of existence of the system

if (hasStableState) {
this->interact();  // ** particle interaction
this->actuate();   // ** activate particles
this->move(); // ** displacement of point particles
this->listShift();  // movement of the system
this->Stabilize();
// --- measurement processes -----------------------------
	frame->remap(); // change the coordinate system
// we scan the space
	eProbe->scanSpace = ">";
	for (int i = 0; i < 1000; i++) {
	if (this->m[i] != NULL) {
		if (m[i]->something != NULL) {eProbe->scanSpace= eProbe->scanSpace+'+';
		} else eProbe->scanSpace= eProbe->scanSpace+' ';
	} else eProbe->scanSpace= eProbe->scanSpace+'X';
	};
	eProbe->CreateDetect = this->CreateDetect;
	eProbe->DestroyDetect = this->DestroyDetect;
// ---  ------------------------
//if (currentItemOfJump != NULL) {
//currentItemOfJump = currentItemOfJump->next;
//} else {isActive = false;};

} else { ShowMessage("decay "+frame->Caption);
		//delete this;
		 };

} // void Run() --------------------------------------------

// ** distribute the external force over the particles of the system
	void doImpact(Carrier *c) {
ListItem *b; Component *p;
b = headOfList; bool done = true;
while (done) {

		if (b->something != NULL) {
			p = b->something;
			done = false;
		} else b = b->right;
} ;
p->doImpact(c);

}
// ---------------------------------------
	// gather the mass of the system
	Skip *getListOfSkip() {
clearOfSkip();
ListItem *previous; ListItem *b;
// активизировать все ячейки
this->reviveCells();

// туда
b = headOfList;
do {
	if (!b->isDisable) { // ячейка не обработана
		if (b->something != NULL) { // есть частица
		// собираем массу
		addOfSkip(b->something);
		};
	b->isDisable = true;  // пометить ячейку как обработанную
	};
previous = b;
b = b->right;
} while (b != NULL);
// обратно
b = previous;
do {
	if (!b->isDisable) { // ячейка не обработана
		if (b->something != NULL) { // есть частица
		addOfSkip(b->something);
		};
	b->isDisable = true;  // пометить ячейку как обработанную
	};
b = b->left;
} while (b != NULL);
return headItemOfSkip;
}

// ---------------------------------------
// template for interaction
	void interact1() { //Concept = Взаимодействовать
ListItem *previous; ListItem *b;
this->reviveCells();

// forward
b = headOfList;
do {
	if (!b->isDisable) { // cell not processed
		if (b->something != NULL) { // there is a particle
			Component *p; p = b->something;
			//ShowMessage( "х = "+IntToStr(b->x));
		};
	b->isDisable = true;  // mark cell as processed
	};

previous = b;
b = b->right;
} while (b != NULL);
// back
b = previous;
do {
	if (!b->isDisable) { // cell not processed
		if (b->something != NULL) { // there is a particle
			//ShowMessage( "х = "+IntToStr(b->x));
			Component *p; p = b->something;
		};
	b->isDisable = true;  // mark cell as processed
	};

b = b->left;
} while (b != NULL);
} // end void interact()

// -----------------------------------------------
}; // end class AbstractTreeNode ------------------------------



//---------------------------------------------------------------------------
#endif
