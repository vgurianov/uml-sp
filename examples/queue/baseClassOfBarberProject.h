/******************************************************
 * File name: baseClassOfBarberProject.h
 * Author:  Vasily I.Gurianov
 * Date:    2017.08.02
 * Tested on CodeGear C++ Builder 2007
 *
 * The barber simulation.
 *
 * There is a single-chair barbershop. From when it opens in the morning
 * until it closes, customers arrive every 20 ± 10 min at random times.
 * If the barber is not busy, he serves a customer immediately; otherwise
 * they must wait in a queue (FIFO order).
 * The time needed to serve each customer is 19 ± 5 min also random.
 * It's necessary define a average length of queue and a average time of waiting.
 *
 * Using:
 *  TreeRoot *pWorld = new TreeRoot;
 *
 *  pWorld->Run();
 *  Memo1->Lines->Add(pWorld->probe);
 *
 * ***************************************************/

#ifndef baseClassOfBarberProjectH
#define baseClassOfBarberProjectH

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
	enum ServiceState {IDLE, BUSY};
	class Component {
	public:
	ServiceState serviceState;

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
			serviceState = IDLE;
		}
		virtual void Run() { // <<Exist>>
		if (currentItemOfList != NULL) {
		serviceState = BUSY;
		output = NULL;
		currentItemOfList = currentItemOfList->next;
		} else {
		currentItemOfList = headItemOfList; serviceState = IDLE;
		input->_state = PROCESSED;
		output = input;
		 };
		}
	};

	/******************************************************
	 *  Class:   <<Ontology Category>>Composite
	 *  The class is Composite role in Composite pattern
	 *  ***
	 *  Concept = Single-server queue system category
	 * ***************************************************/
	class Composite : public Component {
	protected:
		Component *_component;
	public:
	};  // class Component

	/******************************************************
	 * Class:   <<Ontology System>> TreeNode
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Queuing System
	 * ***************************************************/
	class TreeNode : public Composite {
		public:
		Queue *queue;       // *** Concept = Customer queue
		QueueNode *client;  // *** Concept = Client served

		TreeNode() {
			_component = new TreeLeaf;
			queue = new Queue();
			input = NULL;
			output = NULL;
			client = NULL;
			}
		void Run() { //<<Exist>>

			if (input != NULL) queue->enqueue(input);
			if (_component->serviceState == IDLE) {
				output = client;
				client = queue->dequeue();
				_component->input = client;
			} else output = NULL;
			_component->Run();

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
			_component = new TreeNode;
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
				_component->input = new QueueNode("Customer");
				} else { _component->input = NULL; };
				_component->Run();
				if (_component->output != NULL) {
					probe = _component->output->_data;
					delete _component->output;
				} else {probe = "NULL";};
			currentItemOfList = currentItemOfList->next;
			}; // while (currentItemOfList != NULL)
		}
	};

//---------------------------------------------------------------------------
#endif
