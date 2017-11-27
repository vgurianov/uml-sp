# Mechanical motion
Terms view on [Wikipedia](https://en.wikipedia.org/wiki/Fractal).
## Introduction
 [Computational physics] (https://en.wikipedia.org/wiki/Computational_physics) large wide use to modern scientific research.  
 However, models of computational physics are not simulation models. The simulation model reproduces the message exchange protocol
 between the components of the system under study. Somewhat simplifying, we can say that the simulation model and 
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
In UML2 SP, "space" notion is a container to components of system and denoted by <<Space>> stereotype. 

### 1. Ontology partition
#### Description of a computational semantics
All objects of class have parallel threads.

#### Description of an application domain semantics
### 2. Epistemology partition

## Verification
We denote the box-counting dimension by *d*. Let *e* be a length of covering, 

## The simulation model in C++ code:  
[ClassesOfFractalProject.h](https://github.com/vgurianov/uml-sp/blob/master/examples/fractal/ClassesOfFractalProject.h), 
[ClassesOfFractalProject.cpp](https://github.com/vgurianov/uml-sp/blob/master/examples/fractal/ClassesOfFractalProject.cpp)

## Conclusion
In this section considered object model of the Koch snowflake. This model can use to construct other fractals such as the Cantor 

## References
