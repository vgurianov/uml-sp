# Mechanical motion
Terms view on [Wikipedia](https://en.wikipedia.org/wiki/Classical_mechanics).
## Introduction
 [Computational physics](https://en.wikipedia.org/wiki/Computational_physics) large wide use to modern scientific research.  
 However, models of computational physics are not simulation models. The simulation model reproduces the message exchange protocol between the components of the system under study. Somewhat simplifying, we can say that the simulation model and 
the object of study should have the same behavioral algorithm. The numerical model reproduces operations with numbers and, 
in general, modeling mathematical object. For example, solving the equations of Newton's motion, 
the numerical model reproduces not the motion of a point particle, but the process of solving a differential equation. 
In this way, where is a problem of development of physical simulation models. 
You can object, in physics have been created many qualitative mathematical models, modern numerical methods are effective, 
and researcher no need to other approaches. With it we can argue - a new approach always eventually gives something new.

In this section, we shall discuss simulation in physics.The simulation model of classical mechanical motion was propose 
in papers [1-3]. This model based on the Levi-Beck theory of mechanical motion in discrete space-time.
## Related Works


## Application Domain
Newton's laws
- First law:	In an inertial frame of reference, an object either remains at rest or continues to move at a constant velocity, 
unless acted upon by a force. 
- Second law:	In an inertial reference frame, the vector sum of the forces F on an object is equal to the mass m 
of that object multiplied by the acceleration a of the object: F = ma. 
- Third law:	When one body exerts a force on a second body, the second body simultaneously exerts a force equal 
in magnitude and opposite in direction on the first body.

More info view on [Wikipedia](https://en.wikipedia.org/wiki/Newton%27s_laws_of_motion).

## Analysis model
Fundamentals of mechanical motion in discrete space-time were developed in the period of the birth of quantum mechanics []. In our opinion, these views can become a theoretical basis for constructing imitation models. We will not discuss the question of the discreteness of physical space. Our task is to find ways to adequately describe the mechanical motion by means of simulation modeling.
In our model, we use a two-layer architecture (see Fig. 1), which allows us to separate the components of the model into two levels of abstraction. The lower layer defines abstract model classes (see Figure 3), such as Component, Composite, and ListItem. The ReusableClassesOfInterface package contains abstract classes modeling the research installation and the user interface libraries (we use VCL). Top-layer packages define specific classes, such as ConcreteTreeNode, TreeLeaf, TreeRoot, and classes of a specific simulation model. In UML2 SP, an architectural diagram in terms of subject semantics is an interpreted as a conceptual graph
<p><img src="fig1.png" alt="" /></p>
Figure 1. Architectural analysis of the class diagram<br/>
Package Epistemology Entity. This package defines the procedure for measuring the main characteristics of the mechanical movement - time, position, speed and acceleration.
Package Ontology Entity. This package has the marked meaning "Classical mechanics" in the sense that by theory we mean the classification of mechanical systems.
<p><img src="fig2.png" alt="" /></p>

### 1. Ontology partition
A conceptual model in UML2 SP is an analysis class diagram. This diagram considered as ontology. 
Model a mechanical motion is depicted in Fig.1.  

#### Description of a computational semantics
All objects of class have parallel threads.

#### Description of an application domain semantics
We shall give definition of concepts to the ontology. The architecture of the model defines the pattern Composite [14], which defines the hierarchy of nested mechanical subsystems. Unlike the classic pattern [14], aggregation materializes through a linked list with ListItem elements.

- Matter
The “Component” frame define “Matter” concept. In the classical physics, [matter](https://en.wikipedia.org/wiki/Matter) is any substance that has mass and takes up space by having volume. 
The frame has headItemOfJump and currentItemOfJump slots. It is define “Resource of motion” concept.
The frame has headItemOfSkip and currentItemOfSkip slots. It is define “The inertial mass” concept. The property of body is called inertia. A quantitative measure of inertia is [mass](https://en.wikipedia.org/wiki/Mass).<br/>
The *doImpact()* method define “Influence” concept. The concept describes to act of force to body and change value headItemOfJump slot.<br/> 
Newton's second law. In 1926, Levi proposed the following mechanism action of force [13, P.98]. 
The force acts on the particle not constantly, but every τ sec (τ~E-23 sec).
On any other particle, whose mass is N times larger, the force acts every Nτ sec.
We use the Carrier class such that generates new instances of the headItemOfJump list. The Component class has both headItemOfSkip and currentItemOfSkip fields of type Skip. This list simulates the inertia of a particle when skips objects of Carrier. A quantity of skip is quantity elements in the headItemOfSkip list (see Fig.3). If ‘currentItemOfSkip’ list end then object of Carrier is processed. The changeMove() method change length of the list. 
The absorb() method change a state of object Carrier class. The getListOfSkip() method return a pointer headItemOfSkip. Both methods absorb() and getListOfSkip() are abstract methods and shall be must define in a concrete class. A detailed of algorithmic record of Newton's 2nd law is discussed in [12].

<p><img src="fig3.png" alt="" /></p>
Figure 3. 	Algorithmic recording of Newton's second law

Point particle
The “TreeLeaf” frame define “Point particle” concept. A [point particle](https://en.wikipedia.org/wiki/Point_particle) is 
an appropriate representation of any object whose size, shape, and structure is irrelevant in a given context.
The TreeLeaf define both methods absorb() and getListOfSkip(). The absorb() method change direction of Carrier to the contrary. The getListOfSkip() method return a pointer headItemOfSkip.
The <<Exist>>Run() method define rule of change of isActive value.
```
void Run(){
		if (currentItemOfJump->next != NULL) {
		if (currentItemOfJump != NULL) {
			currentItemOfJump = currentItemOfJump->next;
		} else {isActive = false;};
	}
``` 
The actuate() method make particle is the active
```
	void actuate() {
	if (headItemOfJump != NULL) {isActive = true; };
	currentItemOfJump = headItemOfJump;
	}
```
- Agent of force
The “Carrier” frame define “Agent of force” concept. Agent of force is a carrier of interaction. The frame has «Direction» slot. In 1-dimension space, it is field can has two value are backward and forward.

- Cell of space
The “Composite” frame define “Cell of space” concept. The frame has «left» and «right» slots. It is defined "coupling" (or "topology") notion. The frame has “something” slot. It is define "content" notion.

- Physical space
The base (the headOfList attribute) and the anchor points (tailOfList attribute) that specify the direction in space model the physical space. From the point of view of computational semantics, space is an N-dimensional linked list of instances of the ListItem class.
The space assembly is
```
for (int i = 0; i < 1000; i++) m[i] = NULL;
	
	for (int i = 0; i < N; i++) { // N - resolution of space
		m[i] = new ListItem; m[i]->x = i;
	};
	ListItem *a;
	for (int i = 0; i < N; i++) {
	a = m[i];
	if (i<N-1) a->right = m[i+1]; if (i>0) a->left = m[i-1];
	};
	headOfList = m[1];    // base of space
	tailOfList = m[N-1];  // anchor point 
```
Further, we confine ourselves to a one-dimensional space. The listShift() and listInversion() method are operations above space.


### 2. Epistemology partition

## Verification
We denote the box-counting dimension by *d*. Let *e* be a length of covering, 

## The simulation model in C++ code:  
[ClassesOfFractalProject.h](https://github.com/vgurianov/uml-sp/blob/master/examples/fractal/ClassesOfFractalProject.h), 
[ClassesOfFractalProject.cpp](https://github.com/vgurianov/uml-sp/blob/master/examples/fractal/ClassesOfFractalProject.cpp)

## Conclusion
In this section considered object model of the Koch snowflake. This model can use to construct other fractals such as the Cantor 

## References
