# UML2 SP: Object-oriented simulation language
The UML-profile intend for the development of simulation models. The development use a modified Unified Process. UML2 SP models are do not depend on the programming language.

We opinion, the language useful to scientific simulation. The UML2 SP describe object of study as an ontology, i.e. as non-numeric model. This valuable if the mathematical model of object is not known. The ontology can be investigate simulation method.
Also, the language can be used to technical simulation, however, this is more expensive than the GPSS or AnyLogic simulation but it is justified if the high quality of the model is necessary.<br/>
We believe, the UML2 SP helpful into area of higher education to study of simulation and preparation of thesis.

This project is my a postdoctoral research work on a simulation. More details can be found on [wiki](https://github.com/vgurianov/uml-sp/wiki). Publications of the language see a bibliography section.

A website of the UML2 SP is https://vgurianov.github.io/uml-sp/<br/><br/>

Folders:

- **UML2 SP metamodel**   -- Metamodel of the language
- **UML2 SP**             -- UML2 SP installation (it is an implementation of the language for StarUML editor)
- **examples**            -- The examles of simulation models on UML2 SP and C++

Does this project require use of the StarUML editor?<br/>
No, the StarUML editor is not required. You can use any UML-editor if it supports uml-profiles (see https://en.wikipedia.org/wiki/List_of_Unified_Modeling_Language_tools).<br/>
It is necessary to perform the following steps:<br/>
1. create a profile, for example
- Microsoft Visual Studio: https://msdn.microsoft.com/en-us/library/ee332513.aspx
- MagicDraw UML tool: https://community.nomagic.com/uml-profile-t2139.html
- Sparx: http://www.sparxsystems.com/resources/developers/uml_profiles.html
- Visual Paradigm: https://www.visual-paradigm.com/tutorials/how-to-define-custom-model-element-properties.jsp
2. create stereotypes using the definitions https://vgurianov.github.io/uml-sp/metamodel

### License
This project is licensed under the terms of the [BSD 2-Clause license](LICENSE).
### Feedback
The feedback is very welcome.
