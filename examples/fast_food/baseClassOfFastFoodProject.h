/******************************************************
 * File name: baseClassOfFastFoodProject.h
 * Author:  Vasily I.Gurianov
 * Date:    2017.08.22
 * Tested on CodeGear C++ Builder 2007
 *
 * The fast food restaurant simulation.
 *
 * When a car enters from the street, the driver decides to get in line or not. 
 * If the driver decides to leaves the restaurant then he leaves as a dissatisfied customer. 
 * If the driver decides to get in line, then he waits until the menu board is available. 
 * At that time, the driver makes the order to the order taker.
 * After the order taken, then the driver moves forward and the next customer can order. 
 * It is a first activity. The order sends to the kitchen. As soon as kitchen is available, 
 * order takes the cook. It is a second activity.
 * As soon as customer arrived to the pickup window, he pays and picks up his food. 
 * As soon as he picks up his food, then the customer leaves the restaurant as satisfied customer.
 *
 * Using:
 * TreeRoot *pWorld = new TreeRoot;
 *
 * pWorld->Run();
 * Memo1->Lines->Add(pWorld->probe);
 *
 * ***************************************************/

#ifndef baseClassOfFastFoodProjectH
#define baseClassOfFastFoodProjectH

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>


	/******************************************************
	 *  Class:   LinkedList
	 * ***************************************************/
	class LinkedList {
	public:
		LinkedList *next;
		LinkedList() {
			this->next = NULL;
		}
	};  // class LinkedList

	/******************************************************
	 * Class:   QueueNode
	 *
	 * This class define node of queue.
	 *
	 * ***************************************************/
	enum QueueNodeState {PROCESSED, UNPROCESSED};
	class QueueNode {
	public:
		AnsiString _data;
		QueueNodeState _state;
		QueueNode *next;

		QueueNode() {
			_data = "Who am I?";
			_state = UNPROCESSED;
		}
		QueueNode(AnsiString data) {
			_data = data;
			_state = UNPROCESSED;
		}
	};  // class QueueNode

	/******************************************************
	 * Class:   Queue
     * 
	 * This class define queue.
	 * 
	 * ***************************************************/
	class Queue {
	public:
		QueueNode *head;
		QueueNode *tail;
		int count;
        Queue() {
			head = NULL;
			tail = head;
			count = 0;
        } 
		int Count() { return count; }
		bool IsEmpty() { return count == 0; }
	   // push
		void enqueue(QueueNode *data) {
			if (count == 0) {
				head = data;
				tail = head; }
			else {
				tail->next = data;
				tail = tail->next; };
            count++;
        }
		// pull
		QueueNode *dequeue() {
			if (count == 0) return NULL;
			else {
			QueueNode *out;
			out = head;
			head = head->next;
			count--;
			return out; };
		}
		// get first element
		QueueNode* first() {
				//if (IsEmpty) return NULL; else
				return head;
		}
		// get last element
		QueueNode* last() {
				//if (IsEmpty) return NULL; else
				return tail;
		}

        // clear queue
		void Clear() {
			head = NULL;
			tail = NULL;
            count = 0;
        }
		//
		bool Contains(AnsiString data) {
			QueueNode *current = head;
			while (current != NULL)	{
				if (current->_data == data) {return true;}
				else current = current->next;
            }
            return false;
		}
	};  // class Queue

	/******************************************************
	 *  Class:   <<Substance>> Component
	 *  The class is Component role in Composite pattern
	 *  ***
	 *  Concept = Service
	 * ***************************************************/
	enum ComponentState {IDLE, BUSY};
	class Component {
	public:
	ComponentState componentState;

	QueueNode *input;   //*** Concept = Input of entity
	QueueNode *output;  //*** Concept = Output of entity

		virtual void Run() = 0;
	};  // class Component

	/******************************************************
	 * Class:   <<Ontology Atom>> TreeLeaf
	 *  The class is Leaf role in Composite pattern
	 *  ***
	 *  Concept = Server
	 * ***************************************************/
	class TreeLeaf : public Component {
		private:
			LinkedList *headItemOfList;
			LinkedList *currentItemOfList;

		public:

		TreeLeaf() {
			headItemOfList = new LinkedList;
			currentItemOfList = headItemOfList;
			for (int i = 0; i < 0; i++) {
			currentItemOfList->next = new LinkedList;
			currentItemOfList = currentItemOfList->next;
			};
			currentItemOfList = headItemOfList;
			componentState = IDLE;
		}
		virtual void Run() { // <<Exist>>
		if (currentItemOfList != NULL) {
		componentState = BUSY;
		output = NULL;
		currentItemOfList = currentItemOfList->next;
		} else {
		currentItemOfList = headItemOfList; componentState = IDLE;
		if (input != NULL) input->_state = PROCESSED;
		output = input;
		 };
		}
	};

	/******************************************************
	 *  Class:   <<Ontology Space>>ItemOfList
	 *  The class is container for instances 'Component' class
	 *  ***
	 *  Concept = Cell of Space
	 * ***************************************************/
	class ItemOfList {
	protected:
	public:
		Component *_component;
 		ItemOfList *left;
		ItemOfList *right;

		ItemOfList() {
			_component = NULL;
			left = NULL;
			right = NULL;
        }

	};  // class ItemOfList

	/******************************************************
	 *  Class:   <<Ontology Category>>Composite
	 *  The class is Composite role in Composite pattern
	 *  ***
	 *  Concept = Singleton (single-server queue system category)
	 * ***************************************************/
	class Composite : public Component {
	protected:
		ItemOfList *head;
		ItemOfList *tail;
	public:
		 Composite() {
		 head = NULL; tail = NULL;
		 /*head = new ItemOfList;
		 tail = head;
		 tail->right = new ItemOfList;
		 tail = tail->right;
		 tail->right = new ItemOfList;
		 tail = tail->right;  */
         }
	};  // class Component

	/******************************************************
	 * Class:   <<Ontology System>> TreeNode
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Queuing System
	 * ***************************************************/
	class BottomNode : public Composite {
		public:
		Queue *queue;       // *** Concept = Customer queue
		QueueNode *client;  // *** Concept = Client served

		BottomNode () {
			head = new ItemOfList;
			tail = head;
			head->_component = new TreeLeaf;
			queue = new Queue();
			input = NULL;
			output = NULL;
			client = NULL;
			componentState == IDLE;
			}
		void Run() { //<<Exist>>

			if (input != NULL) queue->enqueue(input);
			if (head->_component->componentState == IDLE) {
				output = client;
				client = queue->dequeue();
				head->_component->input = client;
			} else output = NULL;
			head->_component->Run();
			
		}

	};  // BottomNode

	/******************************************************
	 * Class:   <<Ontology System>> TopNode
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Queuing System
	 * ***************************************************/
	class TopNode : public Composite {
		private:
			BottomNode *bottomNode;
			QueueNode *product;
		public:

		TopNode() {
			// build restaurant
			head = new ItemOfList;
			head->_component = new BottomNode;
			tail = head;
			tail->right = new ItemOfList;
			tail->right->_component = new BottomNode;
			//tail = tail->right;
			//tail = head;
			//tail->right = new ItemOfList;
			//tail->right->_component = new BottomNode;
			tail = tail->right;
			bottomNode = new BottomNode;
			// and set inicial condition
			input = NULL;
			output = NULL;
			componentState = IDLE;
			}
		void Run() { //<<Exist>>
		// HACK: The algorithm need to generalization
			// -- First server
			head->_component->input = input;
			if (head->_component->componentState == IDLE) {
				tail->_component->input = head->_component->output;
				bottomNode->input = new QueueNode("Order");
			};
			head->_component->Run(); 
			// -- Third server
			bottomNode->Run();
			// -- Second server
			if (bottomNode->output != NULL) {
			tail->_component->Run();
			};
			tail->_component->Run();
			if (tail->_component->componentState == IDLE) {
				output = tail->_component->output;
			} else output = NULL;
		}

	};

	/******************************************************
	 * Class:   <<Ontology Context>> TreeRoot
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Calling population (a boundary and initial condition)
	 * ***************************************************/
	class TreeRoot: public Composite {
		private:
			LinkedList *headItemOfList;
			LinkedList *currentItemOfList;
		public:
		 AnsiString probe;

		 TreeRoot() {
			head = new ItemOfList;
			head->_component = new TopNode;
			// time
			headItemOfList = new LinkedList;
			currentItemOfList = headItemOfList;
			for (int i = 0; i < 0; i++) {  // i < 0 is test
			currentItemOfList->next = new LinkedList;
			currentItemOfList = currentItemOfList->next;
			};
			currentItemOfList = headItemOfList;

		}
		void Run() { //<<Exist>>
			int firs_value = 0; int width_value = 100; // for random
			currentItemOfList = headItemOfList;
			while (currentItemOfList != NULL) {
				int random_number = firs_value + rand() % width_value;
				if (random_number <= 100) { // random_number <= 100 is test
				 head->_component->input = new QueueNode("Car");
				} else { head->_component->input = NULL; };
				head->_component->Run();
				if (head->_component->output != NULL) {
					probe = head->_component->output->_data;
					delete head->_component->output;
				} else {probe = "NULL";};
			currentItemOfList = currentItemOfList->next;
			}; // while (currentItemOfList != NULL)
		}
	};

//---------------------------------------------------------------------------
#endif
