# Queueing theory
[View on Wikipedia](https://en.wikipedia.org/wiki/Queueing_theory)

## The barber simulation model
The barber simulation is a classical example of queueing theory.
### Application domain
There is a single-chair barbershop. 
From when it opens in the morning until it closes, customers arrive every 20 ± 10 min at random times. 
If the barber is not busy, he serves a customer immediately; otherwise they must wait in a queue (FIFO order). 
The time needed to serve each customer is 19 ± 5 min also random.<br/> 
It's necessary define an average length of queue and an average time of waiting.

A conceptual model in UML2 SP is an analysis class diagram. This diagram considered as ontology. 
The analysis class diagram of barber model depicted in Fig.1.
<p><img src="barber_ClassDiagram.png" alt="" /></p>
Figure 1. 	Analysis class diagram of barber model<br/>

### Description of a computational semantics
The object of TreeNode class and the object of TreeLeaf class interact  according Producer-Consumer pattern [1].
The Producer-Consumer pattern is standard solution for interaction two and more threads. 

### Description of an application domain semantics
The key elements of queueing systems are the customers and servers. The term “customer” can refer to people, 
parts, trucks, e-mails etc. and the term “server” clerks, mechanics, repairmen, CPUs etc. 
Further we shall accurately define these concepts.<br/>
#### Service
The "Component" frame defines **Service** notion (concept). Service is a server or a queuing system. 
Example, customer service in shopping is the provision of service to customers before, during and after a purchase.
The frame has "input" and "output" slots. It is input and output of queuing system. Those attributes has type "QueueNode". 
It is defined of "Customer". The "QueueNode" class isn’t a frame.<br/>
The frame has "componentState" slot. It is state of a queuing entity.<br/>
#### Server
The "TreeLeaf" frame defines **Server** concept. The Run method is realization abstract operation Run. 
This operation defines a rule of change of slots value.<br/>
#### Single-server queue system
The "Composite" frame defines **Single-server queue system** concept. The *Ontology Category* stereotype defines a group (category) of a queuing system. In this model it is the single-server queue system.<br/>
#### Queuing System
The "TreeNode" frame defines **Queuing System** concept. It is main notion in the Queuing Theory. The frame has "Queue" slot. 
It is define "Customer queue" concept. A type of the slot is Queue. The "Queue" class is not a frame. 
The frame has "Client" slot. This slot defines "Client served". 
#### Calling population
The "TreeRoot" frame defines **Calling population** concept. The population of potential customers, referred to 
as the calling population, may be assumed to be finite or infinite. 
It is a boundary and initial condition for the queuing system.
<br/><br/>
**The simulation model in C++ code:**  [baseClassOfBarberProject.h](https://github.com/vgurianov/uml-sp/blob/master/examples/queue/baseClassOfBarberProject.h), [baseClassOfBarberProject.cpp](https://github.com/vgurianov/uml-sp/blob/master/examples/queue/baseClassOfBarberProject.cpp)

## References
1. Mark Grand, Patterns in Java, Volume 1: A Catalog of Reusable Design Patterns Illustrated with UML, Second Edition, John Wiley & Sons, 2002

