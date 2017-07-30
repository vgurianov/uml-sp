<h1 id="Case Studies">Case Studies</h1>
On this page present a scientific simulation models as example.<br/>
Contents:<br/>
<ul>
  <li><a href="#dialogs">Dialogs</a></li>
  <li>paradox-of-barber</li>
</ul>


<h3 id="dialogs">Dialogs</h3>  
In this example we shall simulated dialogs between humans.<br/>
**Application domain:** Greeting <br/>
– Good morning, Mr. Goldsmith. It’s been a long time since we met. How nice to see you again.
– How do you do, Mr. Brown. I’m glad to see you too. How are you?
– Not bad, thank you /Thanks, not so well.<br/>

<p>Ontology depicted in picture:</p><br>
<p><img src="case_studies/dialogs.png" alt="" /></p><br>
<p>Formal describe this definition is a ontology depicted in class diagram.<br /></p>
<ul>
  <li>The “Component” frame define “Subject” concept. This frame has “name” and “next” slots.<br /></li>
  <li>The “Leaf” frame  define “Human” concept.<br /></li>
  <li>The “Composite” frame define “Dialog space” concept and has “pl” slot.<br /></li>
  <li>The “Root” frame define “Environment” concept . It is initial and boundary conditions.<br /></li>
  <li>The “Node” frame define “Greeting” concept and has “msg” slot. It is the system under study.<br />
Class operations define a rule of change of slot.<br/>



<h3 id="paradox-of-barber">Paradox of barber</h3> 

<strong>Application domain:</strong> The paradox of barber by Bertrand Russell<br/> 
A traditional model of DES is a queue. A concrete queue considers for model of the barber paradox by Bertrand Russell. Suppose we want to build model for the paradox of barber by Bertrand Russell. We do not discuss paradox, but present an object-oriented model. Remind, the barber is the "one who shaves all those, and those only, who do not shave themselves." The question is, does the barber shave himself? The queue is the sequence of village males to the barber. A class diagram from an Analysis Model depicted in Figure 10<br/>
<p><img src="examples/barber.png" alt="" /></p><br>
Figure 2: An object-oriented simulation model of a queue to the barber

The model implementation make with C++. The queue simulate as a linked list comprising of an instances of Leaf class. The list is a circular (loop) list. The barber serve client and the list shift on one item (Run() method of Node class). In case Figure 10 the barber can be insert in this list (see Node() constructor). A general structure of model defines the Composite pattern. A Root class set the boundary and initial conditions. The «Exist» methods define a unit of discrete time. We follow the rule "Simulation as programming". The element names of UML-diagram reflect compute semantics of model. This style is a best useful style for a development of a model. In the class diagram we allow superfluity for most clarity. In particular, we do not use SPSlot stereotype. Also, we simplify the class diagram and omit classes with "EScene" and "ETool" stereotypes. It is a model of the measuring instrument.<br/>
The Figure 2 below shows as used the UML2 SP profile. The class diagram can be read as a semantic net. Concepts of semantic net defined as Frames. The attributes of class interpret as Slots and the operations of class - as Attached Procedures. It is the semantics of application domain and it is a conceptual model. However, if the class diagram read as a class diagram then it is the compute semantics, i.e. semantics of program. In a Design Model will be adding a lot compute entities which do not has semantics of application domain and so do not has stereotypes.<br/>

