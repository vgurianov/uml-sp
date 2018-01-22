# Decomposition of clock
Terms view on [Wikipedia](https://en.wikipedia.org/wiki/Pendulum_clock).
## Introduction
SSP (Simulation with Simulation with Scientific Profile) is analog of Unified Process to development a simulation models. The main principle of SSP is a decomposition principle. First of all, we define context and system. Farther, we make decomposition of system to subsystems. In end, we have atomic objects. The atomic object is an anolog of ABS-agent. For decomposition, we use Composite pattern.<br/>
The particularity feature of decomposition in SSP is a decomposition of time. For any subsystem need to define a minimal change of subsystem (quantum of exist, can say ). In UML2 SP, it is a operation with "Exist" stereotype. In this section we will discurse it topic.


## Application domain
In the pendulum clock, the work of a constant external force (gravity acting on the weight) periodically compensates for the loss of mechanical energy of the pendulum. For details, see [Wikipedia](https://en.wikipedia.org/wiki/Pendulum_clock)
<p><img src="clock.png" alt="" /></p>
Figure 1. Pendulum clock (picture from [http://fizportal.ru/](http://fizportal.ru/physics-book-67-3))<br/>
First of all, we are interested in a gear train.
The gear ratios of the gear train divide the rotation rate down to give wheels that rotate once every hour and once every 12 hours, to turn the hands of the clock.<br/> 
Where are two objects such that their time is sinhronize. First object is the hour hand (and dial), second object is the minute hand (and dial). Let the second hand by directly connected with the pendulum.

## Analysis model
A conceptual model in UML2 SP is an analysis class diagram. This diagram considered as ontology. 
Model the clock is depicted in Fig.2.

<p><img src="ClassDiagram.png" alt="" /></p>
Figure 2. The class diagram<br/>
The ontology consist as frames and links between them. Frames define concepts. 

#### Topological Space
The “Component” frame define “Topological Space
” concept. The frame has «left and right» slots. It is defined "coupling" notion.


### Verification
<p><img src="main_form.png" alt="" /></p>
Figure 3. Results of observe the simulation model<br/>

### The simulation model in C# code:  
[ClockClass.cs](https://github.com/vgurianov/uml-sp/blob/master/examples/clock/ClockClass.cs) 

## Alternative model of analysis 
A conceptual model in UML2 SP is an analysis class diagram. This diagram considered as ontology. 
Model the fractal is depicted in Fig.3.

<p><img src="AltClassDiagram.png" alt="" /></p>
Figure 3. The class diagram<br/>
We shall give definition of concepts to the ontology.

#### Topological Space
The “Component” frame define “Topological Space
” concept. The frame has «left and right» slots. It is defined "coupling" notion.
### Verification
<p><img src="main_form2.png" alt="" /></p>
Figure 3. Results of measurement to simulation model<br/>

### The simulation model in C# code:  
[ClockClassAlt.cs](https://github.com/vgurianov/uml-sp/blob/master/examples/clock/ClockClassAlt.cs)

## Conclusion
In this section considered object model of the Koch snowflake. This model can use to construct other fractals such as the Cantor ternary set and more complex.<br/>

## References
1.	[V.I. Gurianov, Simulation with UML SP. Cheboksary: SPbSEU, branch in Cheboksary, 2014. - 136 p.(In Russian)](http://simulation.su/static/en-books.html)
