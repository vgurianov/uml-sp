/******************************************************
 * File name: BaseClassesOfTheoryProject.h
 * Author:  Vasily I.Gurianov
 * Date:    2017.10.15
 * Tested on CodeGear C++ Builder 2007
 *
 * Template of decomposition of queueing system
 *
 *      Computer      Peripheral device
 *                    -------------
 *      ---------    |   -> Printer |
 *  -> | CPU -+--|---|->+           |-->
 *     |  !   !  |   |   -> Fax     |
 *     |  <- HD  |    -------------
 *      ---------
 *
 * Using:
 *  TreeRoot *pWorld = new TreeRoot;
 *
 *  pWorld->Run();
 *  Memo1->Lines->Add(pWorld->probe);
 *
 * ***************************************************/

#ifndef BaseClassesOfTheoryProjectH
#define BaseClassesOfTheoryProjectH

#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
 
//---------------------------------------------------------------------------


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
		AnsiString _data;  // job name
		QueueNodeState _state;
		int mark;   // for route
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
	 *  **
	 *  Concept = Service
	 * ***************************************************/
	enum ServiceState {IDLE, BUSY};
	class Component {
	public:
	AnsiString trace; // it is instrument of observe
	ServiceState serviceState;

	QueueNode *input;   //*** Concept = Input of job
	QueueNode *output;  //*** Concept = Output of job

		virtual void Run() = 0;
		void debugTrace(AnsiString name_class) { // it is debug procedure
AnsiString tr; tr = name_class;
if (input != NULL) {tr=tr+input->_data+", ";} else tr=tr+"NULL, ";
if (output != NULL) {tr=tr+output->_data;} else tr=tr+"NULL";
ShowMessage(tr);
}

	};  // class Component

	/******************************************************
	 * Class:   <<Ontology Atom>> TreeLeaf
	 *  The class is Leaf role in Composite pattern
	 *  **
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
			for (int i = 0; i < 0; i++) { // test
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
		input->_state = PROCESSED;  // ?
		output = input;
		 };
		}
	}; // TreeLeaf

	/******************************************************
	 *  Class:   <<Ontology Space>> ItemOfList
	 *  The class is a container
	 *  **
	 *  Concept = Work site
	 * ***************************************************/
	class ItemOfList {
	public:
		ItemOfList *left, *right;
		Component *_component;
	};

	/******************************************************
	 *  Class:   <<Ontology Category>> Composite
	 *  The class is Composite role in Composite pattern
	 *  **
	 *  Concept =
	 * ***************************************************/
	class Composite : public Component {
	protected:
		ItemOfList *head;
	public:
	};

	/******************************************************
	 *  Class:   <<Ontology Category>> DirectAccessComposite
	 *  The class is Composite role in Composite pattern
	 *  ***
	 *  Concept = G/G/s queuing system
	 * ***************************************************/
	class DirectAccessComposite : public Composite {
		private:
		protected:
			Queue *queue;       // *** Concept = Customer queue
		public:
		 DirectAccessComposite(){}
		 DirectAccessComposite(Component *c1, Component *c2) {
			head = new ItemOfList; head->_component = c1;
			head-> right = new ItemOfList; head-> right->_component = c2;
}
};
	/******************************************************
	 *  Class:   <<Ontology Category>> SequentialAccessComposite
	 *  The class is Composite role in Composite pattern
	 *  **
	 *  Concept = Multiphases queuing system
	 * ***************************************************/
	class SequentialAccessComposite: public Composite {
		private:
		protected:
			ItemOfList *tail;
		public:
		 SequentialAccessComposite() {}
		 SequentialAccessComposite(Component *c1, Component *c2) {
			head = new ItemOfList; head->_component = c1;
			head-> right = new ItemOfList; head-> right->_component = c2;
			tail = head-> right;

}
};

	/******************************************************
	 * Class:   <<Ontology System>> SimpleNode
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Work unit (server+queue)
	 * ***************************************************/
	class SimpleNode : public DirectAccessComposite {
		public:
		QueueNode *client;  // *** Concept = Client served

		SimpleNode() {
			this->head = new ItemOfList;
			this->head->_component = new TreeLeaf;
			this->queue = new Queue();
			input = NULL;
			output = NULL;
			client = NULL;
			}
		void Run() { //<<Exist>>

			if (input != NULL) queue->enqueue(input);
			if (head->_component->serviceState == IDLE) {
				output = client;
				client = queue->dequeue();
				head->_component->input = client;
			} else output = NULL;
			head->_component->Run();

		}

	};
	/******************************************************
	 * Class:   <<Ontology System>> MiddleNode
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Computer
	 * ***************************************************/
	class MiddleNodeA : public SequentialAccessComposite {
		public:

		MiddleNodeA(Component *c1, Component *c2): SequentialAccessComposite(c1, c2) {
		}
		void Run() { //<<Exist>>
output = input; //it is first level debug
// further, take into account the characteristic features of the system,
// for example:
		/*
		// joining:
		head->_component->input = tail->_component->output; // to CPU from HD
		head->_component->input = input;  // to CPU from input
		// forking (mark == 0 then output):
		if (head->_component->output->mark == 0)  {// to PD
		output = head->_component->output;  output->mark = 0; //or 1
		} else tail->_component->input = head->_component->output;  // to HD
		*/
this->debugTrace(" MiddleNodeA: ");
		}

	};
	/******************************************************
	 * Class:   <<Ontology System>> MiddleNode
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Peripheral device
	 * ***************************************************/
	class MiddleNodeB : public DirectAccessComposite {
		public:

		MiddleNodeB() {
		}
		MiddleNodeB(Component *c1, Component *c2): DirectAccessComposite(c1, c2) {
		}
		void Run() { //<<Exist>>
output = input; //it is first level debug
// further, take into account the characteristic features of the system,
// for example:
		/*
		// Direct Access:
		if (input->_component->mark == 0) { // first element
			output = head->_component->output;
			head->_component->input = input;
			head->_component->Run();
		} else { // or second element
			output = head->right->_component->output;
			head->right->_component->input = input;
			head->right->_component->Run();
		};
		*/
this->debugTrace(" MiddleNodeB: ");
		}

	}; // MiddleNodeB

	/******************************************************
	 * Class:   <<Ontology System>> TopNode
	 *  The class is Concrete Class role in Composite pattern
	 *  ***
	 *  Concept = Complex of Devices
	 * ***************************************************/
	class TopNode : public  SequentialAccessComposite {
		public:

		TopNode() {
		trace = "";
			input = NULL;
			output = NULL;
			SimpleNode *s1, *s2;
			// assemblage the queueing system
			s1 = new SimpleNode; s2 = new SimpleNode;
			// ** Computer
			MiddleNodeA *ms = new MiddleNodeA(s1,s2);
			// ** Peripheral device
			TreeLeaf *s3, *s4;
			s3 = new TreeLeaf; s4 = new TreeLeaf;
			MiddleNodeB *md = new MiddleNodeB(s3,s4);
			// ** Complex
			head = new ItemOfList; head->_component = ms;
			head->right = new ItemOfList; head->right->_component = md;
            head->right->left = head;
			tail = head->right;

			}

		void Run() { //<<Exist>> sci-hub.io

		output = tail->_component->output;
		ItemOfList *cur = tail;
		while (cur != NULL) {
			cur->_component->Run();
			if (cur->left != NULL) {
			cur->_component->input = cur->left->_component->output;
			} else {
				cur->_component->input = input; // it is head
				//, i.e. head->_component->input = input;
			};
		cur = cur->left;
		};

this->debugTrace(" TopNode: ");
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
			int count; // it is instrument observe
		public:
		 AnsiString probe;

		 TreeRoot() {
			head = new ItemOfList;
			head->_component = new TopNode;
			count = 0;

		}
		void Run() { //<<Exist>>
				count++;
				head->_component->input = new QueueNode("Job "+IntToStr(count));
				head->_component->Run();
				if (head->_component->output != NULL) {
					probe = head->_component->output->_data;
					delete head->_component->output;
				} else {probe = "NULL";};
		}
	};

//---------------------------------------------------------------------------
#endif
