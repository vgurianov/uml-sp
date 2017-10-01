# Paradox of barber by Bertrand Russell

## Application domain
Suppose we want to build model for the paradox of barber by Bertrand Russell. We do not discuss paradox, but present an object-oriented model. Remind, the barber is the "one who shaves all those, and those only, who do not shave themselves." The question is, does the barber shave himself? The queue is the sequence of village males to the barber.<br/> 

A class diagram from an Analysis Model depicted in Figure 1<br/>
<p><img src="barber.png" alt="" /></p><br>
Figure 1: An object-oriented simulation model of a queue to the barber

## Description of a computational semantics
It is example correct define type of data.
## Description of an application domain semantics
- The queue simulate as a linked list comprising of an instances of Leaf class. The list is a circular (loop) list. The barber serve client and the list shift on one item (Run() method of Node class). In case Figure 10 the barber can be insert in this list (see Node() constructor). A general structure of model defines the Composite pattern. A Root class set the boundary and initial conditions. The «Exist» methods define a unit of discrete time. We follow the rule "Simulation as programming". The element names of UML-diagram reflect compute semantics of model. This style is a best useful style for a development of a model. In the class diagram we allow superfluity for most clarity. In particular, we do not use SPSlot stereotype. Also, we simplify the class diagram and omit classes with "EScene" and "ETool" stereotypes. It is a model of the measuring instrument.<br/>
- The Figure 1 below shows as used the UML2 SP profile. The class diagram can be read as a semantic net. Concepts of semantic net defined as Frames. The attributes of class interpret as Slots and the operations of class - as Attached Procedures. It is the semantics of application domain and it is a conceptual model. However, if the class diagram read as a class diagram then it is the compute semantics, i.e. semantics of program. In a Design Model will be adding a lot compute entities which do not has semantics of application domain and so do not has stereotypes.<br />

## The simulation model in C++ code:  
[baseClassOfFastFoodProject.h](https://github.com/vgurianov/uml-sp/blob/master/examples/barber_paradox/baseClassOfBarberParadox.h), [baseClassOfFastFoodProject.cpp](https://github.com/vgurianov/uml-sp/blob/master/examples/barber_paradox/baseClassOfBarberParadox.cpp)

## References
