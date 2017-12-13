<h1 id="dialogs">Dialogs</h1>  
Terms view on [Wikipedia](https://en.wikipedia.org/wiki/Fractal).
## Introduction

## Application domain
In this example we shall simulated dialogs between humans.<br/>
<strong>Application domain:</strong> Greeting <br/>  
– Good morning, Mr. Goldsmith. It’s been a long time since we met. How nice to see you again.<br/>
– How do you do, Mr. Brown. I’m glad to see you too. How are you?<br/>
– Not bad, thank you /Thanks, not so well.<br/>

## Analysis model
<p>Ontology depicted in picture:</p><br>
<p><img src="dialogs.png" alt="" /></p><br>
<p>Formal describe this definition is a ontology depicted in class diagram.<br /></p>

### Description of a computational semantics
All objects of class have parallel threads.

### Description of an application domain semantics
We shall give definition of concepts to the ontology.

#### Subject
The “Component” frame define “Subject” concept.
It frame has “name” and “next” slots. It is defined "Subject name" and next notions.

#### Human
The “Leaf” frame  define “Human” concept.

#### Dialog space
The “Composite” frame define “Dialog space” concept and has “pl” slot.

#### Greeting
The “Node” frame define “Greeting” concept and has “msg” slot. It is the system under study.

#### Environment
The “Root” frame define “Environment” concept . It is initial and boundary conditions.

Class operations define a rule of change of slot.<br/>

## The simulation model in C++ code:  
[AppBaseClasses.h](https://github.com/vgurianov/uml-sp/blob/master/examples/SimpleExample/AppBaseClasses.h), 
[AppBaseClasses.cpp](https://github.com/vgurianov/uml-sp/blob/master/examples/SimpleExample/AppBaseClasses.cpp)

## Conclusion
In this section considered object model of the dialogs. 

## References
1.	[V.I. Gurianov, Simulation with UML SP. Cheboksary: SPbSEU, branch in Cheboksary, 2014. - 136 p.(In Russian)](http://simulation.su/static/en-books.html)
