# Simulation and UML2 SP

An interest peak to object-oriented simulation (OOS) is the end 90th of the last century [1]. 
With 00th more often use special simulation tools. However, scientific applications use an OOS because OOS is flex approach. 
UML2 SP models are OOS-models. In this section we give a short overview Discrete Event Simulation (DES) paradigm 
and position our approach.

## World views in simulation
Pegden [2] allocated three distinct world views in simulation: event, process, and objects.
1. Event modeling. In this paradigm state of the system change from event to event. It is paradigm implemented in tools such as Simscript, GASP, and many others. The approach widely used the first 20 years.
2. Process modeling. In this paradigm passive entities move through elements of system. It is an interpretation as process flow. A typical tool is GPSS. This approach used in 90's.
3. Object modeling. An object-oriented model is a set of interact objects. Object-oriented simulation can realization both event modeling and process modeling (and as system dynamic). For instance, event orientations approach for object-oriented simulation conside in paper [3].
For examples are AnyLogic, FlexSim, and Simio.

In our view those world views differ describe of time.

## Time in UML2 SP
In works of simulation differentiate three kinds a time. It is a physical time, system time, and wallclock time. 
The physical time is a time of investigated system. The simulation time is an image of time in model. 
The wallclock time is a time of compute experiment on computer. In UML2 SP the time defines in models.
The *Analysis Model* defines a physical time. All objects have concurrent threads. 
These threads interact according to the rules like in nature. Simple example is *Single Threaded Execution* and *Producer-Consumer* pattern.The *Design Model* defines a system time. If selecting a sequential computing then system time is a quasi-parallel time. If selecting concurrent or distributed computing then system time is time of concurrency.

We often use quasi-parallel model of time in Analysis Model for simplicity if it possible.

## UML2 SP and ABS
The basic concept of agent based modeling (ABS) is an agents and their interaction. Pegden opinion “it is not a new discrete event world view”; it is variant object-oriented approach. We opinion a base idea of ABS is [net-centric](https://en.wikipedia.org/wiki/Net-centric) conception.
Distinctive feature of UML2 SP is a building method of models. Agent in ABS is a primary element. 
Properties of system are a result interact agents. Atomic object of UML2 SP is analog to ABS-agent 
but it is the result of decomposition of investigated system to subsystems.

## References
1. Jeffrey A. Joines, Stephen D. Roberts, SIMULATION IN AN OBJECT-ORIENTED WORLD. *In Proceedings of the 1999 Winter Simulation Conference* 
2. C. Dennis Pegden, ADVANCED TUTORIAL: OVERVIEW OF SIMULATION WORLD VIEWS *Proceedings of the 2010 Winter Simulation Conference, edited by B. Johansson, S. Jain, J. Montoya-Torres, J. Hugan, and E. Yücesan, eds.*
3. Byoung K. Choi Donghun Kang, HOW TO DEVELOP YOUR OWN SIMULATORS FOR DISCRETE-EVENT SYSTEMS. *In Proceedings of the 2014 Winter Simulation Conference, edited by A. Tolk, S. Y. Diallo, I. O. Ryzhov, L. Yilmaz, S. Buckley, and J. A. Miller, eds.*
