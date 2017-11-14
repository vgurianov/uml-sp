# Koch snowflake
Terms view on [Wikipedia](https://en.wikipedia.org/wiki/Koch_snowflake).
## Introduction
Mathematical abstractions exist in conceptual reality. The abstractions also can be simulated. 
Simulation model of mathematical abstraction build as simulation model of physical object.
Simulation of mathematical abstraction has many general with [constructive mathematics](https://en.wikipedia.org/wiki/Constructivism_(mathematics)) and used similar notions.
Also, for simulation of mathematical objects are useful notions and ideas [non-standard analysis](https://en.wikipedia.org/wiki/Non-standard_analysis), 
first of all notion of infinitesimal element.
We shall discuss mathematical objects such as geometric fractals because main principle SSP methodology is 
decomposition principle which set quasifractal structure of models. 
We shall considered object model of Koch snowflake. The model proposed in work [1], also see [2].

## Application domain
Terms view on [Wikipedia](https://en.wikipedia.org/wiki/Koch_snowflake)

## Analysis model
In UML2 SP, "space" notion is a container to components of system and denoted <<Space>> stereotype. 
But simulation model of mathematical object of "space" don't isn't <<Space>> class. 
Mathematical objects are objects of mental realty and simulate as objects of physical realty. 
<<Exist>> stereotype mean an operation to mathematical object.
A conceptual model in UML2 SP is an analysis class diagram. This diagram considered as ontology. 
Model the fractal is depicted in Fig.1.

<p><img src="FractalClassDiagram.png" alt="" /></p>
Figure 1. The class diagram<br/>

### Description of a computational semantics
All objects of class have parallel threads.

### Description of an application domain semantics

We shall give definition of concepts to the ontology.

#### Topological Space
The “Component” frame define “Topological Space
” concept. The frame has «left and right» slots. It is defined "coupling" notion.

#### Geometry Point
The “Leaf” frame define “Geometry Point” concept. 
[Geometry Point](https://en.wikipedia.org/wiki/Point_(geometry))

#### Metric space
The "Composite" frame define "Metric space" concept.
A [metric space](https://en.wikipedia.org/wiki/Metric_space
) is a set for which distances between all members of the set are defined. Those distances, 
taken together, are called a metric on the set. "length" slot define "metric" concept. 
"distance()" operation  change a value of slot.

#### Generator
The "AbstractNode" frame define "Generator" concept. 
Generator is object which realise next process:
1. divide the line segment into three segments of equal length.
2. draw an equilateral triangle that has the middle segment from step 1 as its base and points outward.
3. remove the line segment that is the base of the triangle from step 2.
Method run this process is "revrite()" .
"isLeaf" slot define "Is leaf" concept. It have "true" value if object lie bottom tier.
The generator construct the Koch curve.

#### Initiator
The "AbstractRoot" frame define "Initiator" concept. 
The Initiator is initial object. If initiator is line then shall constructe Koch curves.
The Koch snowflake can be constructed by starting with an equilateral triangle.

### Infinitesimal and ordinary elements
If bottom tier consist instance of Lief class the object is quasifractal.
If bottom tier consist instance of Node class the object is fractal. It is potencial infinity object.

## Verification
First two a step can calculate to hand. In first step, e = 1/3 and n = 3*4 = 12, 
d =lnN(e)/ln(1/e) = 2,48490665/1,098612289 = 2,261859507. 
In second step, e = (1/3)/3 = 1/9 and 4*4*3 = 48, d = 3,871201011/ 2,197224577= 1,761859507.  
In general, ep = 1/3p and np = 2(2p)*3. In this way lim (ln(n(e))/ln(1/e)) = 2*(ln2/ln3) = 1, 262. 
The result of measurement to simulation model is shown on Fig. 3, where Dt is accurate value Hausdorff dimension.
<p><img src="Screenshot.png" alt="" /></p>
Figure 2. Results of measurement to simulation model<br/>
As we see, the measurement value of Hausdorff dimension converges to accurate value.

## The simulation model in C++ code:  
[ClassesOfFractalProject.h](https://github.com/vgurianov/uml-sp/blob/master/examples/fractal/ClassesOfFractalProject.h), 
[ClassesOfFractalProject.cpp](https://github.com/vgurianov/uml-sp/blob/master/examples/fractal/ClassesOfFractalProject.cpp)

## Conclusion
In this section considered object model of Koch snowflake. This model can use to construct other fractals such as Cantor ternary set and more complex.
Also, other examples of simulation model of mathematical object see [3]. 

## References
1.	Gurianov V.I. Object Modeling of Fractal Structures // Mathematical Models and Their Applications: 
Sat. sci. tr. Issue. 13. - Cheboksary: Publishing house Chuvash. University, 2011.- P. 148-159
2.	[V.I. Gurianov, Simulation with UML SP. Cheboksary: SPbSEU, branch in Cheboksary, 2014. - 136 p.  
(In Russian)](http://simulation.su/static/en-books.html)
3.	]Shamin RV Modern numerical methods in object-oriented presentation in C #, - 2011. (In Russian)](http://www.intuit.ru/studies/courses/671/527/info)


