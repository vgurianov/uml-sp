# About UML2 SP
A simulation include next steps:
1. define goals of modeling and requirements to simulator
2. conceptual modeling
3. formal describe
4. programming
5. verification and validation
6. make general plan of experiments
7. make up tactical plan and execute experiment
8. analyze results of experiments

UML2 SP support three first step.

# Simple example of development of simulation model
## Application domain: Greeting
-- Good morning, Mr. Goldsmith. It’s been a long time since we met. How nice to see you again.<br/>
-- How do you do, Mr. Brown. I’m glad to see you too. How are you?<br/>
-- Not bad, thank you /Thanks, not so well.<br/><br/>
It's necessary create a simulation model of dialog.

## 1. Define goals of modeling and requirements to simulator
In UML2 SP this step is a *Requirement* workflow. A Use-Case model is an artefact of *Requirement* workflow.

**Goal:** What will Mr. Brown answer?<br/>
**Plan of experiment:** Observe Mr. Brown and Mr. Goldsmith dialog.<br/>

<p><img src="UseCase.png" alt="" /></p>
A *Use-Case model* define the functional requirements of the simulator (system must do "Prepare","Step" and "Visualize").

## 2. Conceptual modeling
In UML2 SP this step is an *Analysis* workflow. An *Analysis model* is an artefact of *Analysis* workflow.<br/>
Analysis model is main part of a simulation model.<br/><br/>
Realization "Step" use case :
<p><img src="UseCaseRealization.png" alt="" /></p> <br>
Class diagram (build from realization):
<p><img src="SP%20ClassDiagram.png" alt="" /></p> <br>

**Application domain semantics.**<br>
In UML2 SP conceptual model is an ontology.<br> 
`The ontology must be true, otherwise the simulation model will not be correct.`<br>
Further we use the terms of knowledge engineering.<br>
A "Component" frame define concept "Subject" . This frame has "name" and "next" slots.<br>
A "Leaf" frame  define concept "Human".<br>
A "Composite" frame define concept "Dialog space" and has "pl" slot.<br>
A "Root" frame define concept "Environment". It is initial and boundary conditions.<br>
A "Node" frame define concept "Greeting" and has "msg" slot. It is the system under study.<br>
Class operations define a rule of change of slot.<br>

**Computational semantics.**<br> 
The class diagram is variant of a *Composite* pattern .<br>

## 3. Formal describe
In UML2 SP this step is a *Design* workflow.A *Design model* is an artefact of *Design* workflow.<br><br/>
An algorithm for the Run operation of the Node class:<br>
<p><img src="ActivityDiagram1.png" alt="" /></p> <br>
On this workflow select a platform and design an algorithms for operations of classes. For Analysis model can be created several Design models.<br>
# Further - programming, testing and etc.
The simulation model in C++ code: [AppBaseClasses.h](https://github.com/vgurianov/uml-sp/blob/master/examples/SimpleExample/AppBaseClasses.h), [AppBaseClasses.cpp](https://github.com/vgurianov/uml-sp/blob/master/examples/SimpleExample/AppBaseClasses.cpp)<br>

[See in GitHub](https://github.com/vgurianov/uml-sp/tree/master/examples/SimpleExample) 
