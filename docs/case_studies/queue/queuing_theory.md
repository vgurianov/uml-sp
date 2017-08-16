# The queuing theory
## The barber simulation model

The barber simulation is a classical example of queuing theory. There is a single-chair barbershop. 
From when it opens in the morning until it closes, customers arrive every 20 ± 10 min at random times. 
If the barber is not busy, he serves a customer immediately; otherwise they must wait in a queue (FIFO order). 
The time needed to serve each customer is 19 ± 5 min also random. 
It's necessary define an average length of queue and an average time of waiting.

A conceptual model in UML2 SP is an analysis class diagram. This diagram considered as ontology. 
The analysis class diagram of barber model depicted in Fig.1.
<p><img src="barber_ClassDiagram.png" alt="" /></p>
Figure 1. 	Analysis class diagram of barber model

The key elements of queuing systems are the customers and servers. The term “customer” can refer to people, 
parts, trucks, e-mails etc. and the term “server” clerks, mechanics, repairmen, CPUs etc. 
Further we shall accurately define these concepts.
The "Component" frame defines "Service" notion (concept). Service is a server or a queuing system. 
Example, customer service in shopping is the provision of service to customers before, during and after a purchase.
The frame has "input" and "output" slots. It is input and output of queuing system. Those attributes has type "QueueNode". 
It is defined of "Customer". The "QueueNode" class isn’t a frame.
The frame has "serviceState" slot. It is state of queuing system.
The "TreeLeaf" frame defines "Server" concept. The Run method is realization abstract operation Run. 
This operation defines a rule of change of slots value.
The "Composite" frame defines "Singleton" concept. The <Ontology Category> stereotype defines a group (category) of 
a queuing system. In this model is the single-server queue system.
The "TreeNode" frame defines "Queuing System" concept. It is main notion in the Queuing Theory. The frame has "Queue" slot. 
It is define "Customer queue" concept. A type of the slot is Queue. The "Queue" class is not a frame. 
The frame has "Client" slot. This slot defines "Client served". 
The "TreeRoot" frame defines "Calling population" concept. The population of potential customers, referred to 
as the calling population, may be assumed to be finite or infinite. 
It is a boundary and initial condition for the queuing system.




