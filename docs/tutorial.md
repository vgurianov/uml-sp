# Introduction
A simulation is a reproduction of behavior a study object, i.e. reproduction of algorithm unless is simplistically say. 
Usually, for simulation use a computer programs.  
The research include followes steps:
1. define aims of modeling and requirements to software of simulation;
2. conceptual modeling;
3. formal describe of software;
4. programming;
5. verification and validation of the simulation model (and program);
6. draw up a general plan of experiments;
7. draw up a tactical plan and execute experiment;
8. analyze results of experiments.

The Unified Process (UP) is a software engineering process (SEP), and it has five workflow are requirements, analysis, design, implementation, and test. The UML2 SP allow to use UP for a development of simulation models. The  requirements, analysis, and design of UP support three first step of a simulation.

# Simple example
In this example we shall simulated dialogs between humans.<br/>
**Application domain**: Greeting <br/>
-- Good morning, Mr. Goldsmith. It’s been a long time since we met. How nice to see you again.<br/>
-- How do you do, Mr. Brown. I’m glad to see you too. How are you?<br/>
-- Not bad, thank you /Thanks, not so well.<br/><br/>
It's necessary create a simulation model of dialog.

# Main steps of development of a simulation model
## 0. Start of development
Run StarUML editor. Apply UML2 SP approach (Fig.1):
<p><img src="images/Start_1.png" alt="" /></p>
Figure 1. A selection of approach<br/>
or created new project. Main work areas see Fig.2.
<p><img src="images/Start_2.png" alt="" /></p>
Figure 2. Main window StarUML for UML2 SP approach

Save your project.
## 1. Define goals of modeling and requirements to simulator
In UML2 SP this step is a *Requirement* workflow. A Use-Case model is an artefact of *Requirement* workflow.

**Goal:** What will Mr. Brown answer?<br/>
**Plan of experiment:** Observe Mr. Brown and Mr. Goldsmith dialog.<br/><br/>
Go "SP UseCase" tab and draw Use Case diagram .<br>
<p><img src="UseCase.png" alt="" /></p>
A *Use-Case model* define the functional requirements of the simulator: system must do "Prepare","Step" and "Visualize".

## 2. Conceptual modeling
Analysis model is main part of a simulation model.<br/>
In UML2 SP this step is an *Analysis* workflow. An *Analysis model* is an artefact of *Analysis* workflow.<br/><br/>

### 2.1. Apply "Simulation" pattern
Select "SP Class diagram" tab, in main menu select option  "Tool" and next option "Apply Patterns". In new window select folder "UML2SP" and Simulator pattern.<br/>
<p><img src="images/SimulatorPattern_1.png" alt="" /></p><br/>
Apply pattern:
<p><img src="images/SimulatorPattern_2.png" alt="" /></p>

### 2.2. Development realisation of use cases 
Go "UseCaseRealization" tab.<br>
Realization "Step" use case :
<p><img src="UseCaseRealization.png" alt="" /></p> <br>

### 2.3. Development of an Analysis classes
In modern science, description of a model is mathematical description. The UML2 SP provide alternative posible of model description. It is very much useful of whenever a mathematical model do not be exist.<br/>
For description of model use an ontology. An ontology is a rigorous language like matematics language. In UML2 SP, an ontology is depicted as a class diagram. Application domain semantics is appointed of  "Concept" tagget value. In matematical text, it is "where" word.<br/>
We draw an analogy with mathematics. The class diagram is similar a differencial equation, a communicative  diagram is similar a particular solution, and sequence diagram is similar a graph of function. We understend "similar" as "same role" to description of model.

Go "SP Class diagram" tab.<br>
Class diagram (build from realization):
<p><img src="SP%20ClassDiagram.png" alt="" /></p> <br>

### 2.4. Description of a computational semantics<br> 
The class diagram is variant of a *Composite* pattern .<br>

### 2.5. Description of an application domain semantics

In UML2 SP conceptual model is an [ontology](https://en.wikipedia.org/wiki/Ontology_(information_science)).  Further we use the terms of [Ontology engineering](https://en.wikipedia.org/wiki/Ontology_engineering) in [notation by Marvin Minsky](https://en.wikipedia.org/wiki/Frame_(artificial_intelligence)). You must very good understand  a domain of application.The ontology must be true, otherwise the simulation model will not be correct.<br>

A [definition of dialog](https://en.wikipedia.org/wiki/Dialogue) from Wikipedia:
> "Dialogue (sometimes spelled dialog in U.S. English) is a written or spoken conversational exchange between two or more 
> people, and a literary and theatrical form that depicts such an exchange."<br>

Formal describe this definition is a ontology depicted in class diagram.<br> 
- The "Component" frame define "Subject" concept. This frame has "name" and "next" slots.<br>
- The "Leaf" frame  define "Human" concept.<br>
- The "Composite" frame define "Dialog space" concept and has "pl" slot.<br>
- The "Root" frame define "Environment" concept . It is initial and boundary conditions.<br>
- The "Node" frame define "Greeting" concept and has "msg" slot. It is the system under study.<br>
Class operations define a rule of change of slot.<br><br>
An ontology is main artefact in the UML2 SP.


## 3. Formal describe
In UML2 SP this step is a *Design* workflow.A *Design model* is an artefact of *Design* workflow.<br><br/>
An algorithm for the Run operation of the Node class:<br>
<p><img src="ActivityDiagram1.png" alt="" /></p> <br>
On this workflow select a platform and design an algorithms for operations of classes. For Analysis model can be created several Design models.<br>
# Further - programming, testing and etc.
The simulation model in C++ code: [AppBaseClasses.h](https://github.com/vgurianov/uml-sp/blob/master/examples/SimpleExample/AppBaseClasses.h), [AppBaseClasses.cpp](https://github.com/vgurianov/uml-sp/blob/master/examples/SimpleExample/AppBaseClasses.cpp)<br>

[View on GitHub](https://github.com/vgurianov/uml-sp/tree/master/examples/SimpleExample) 
