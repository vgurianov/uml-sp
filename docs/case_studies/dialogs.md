<h1 id="dialogs">Dialogs</h1>  
In this example we shall simulated dialogs between humans.<br/>
<strong>Application domain:</strong> Greeting <br/>
– Good morning, Mr. Goldsmith. It’s been a long time since we met. How nice to see you again.
– How do you do, Mr. Brown. I’m glad to see you too. How are you?
– Not bad, thank you /Thanks, not so well.<br/>

<p>Ontology depicted in picture:</p><br>
<p><img src="dialogs.png" alt="" /></p><br>
<p>Formal describe this definition is a ontology depicted in class diagram.<br /></p>
<ul>
  <li>The “Component” frame define “Subject” concept. This frame has “name” and “next” slots.<br /></li>
  <li>The “Leaf” frame  define “Human” concept.<br /></li>
  <li>The “Composite” frame define “Dialog space” concept and has “pl” slot.<br /></li>
  <li>The “Root” frame define “Environment” concept . It is initial and boundary conditions.<br /></li>
  <li>The “Node” frame define “Greeting” concept and has “msg” slot. It is the system under study.<br />
Class operations define a rule of change of slot.<br/>
<a href="https://github.com/vgurianov/uml-sp/edit/master/docs/case_studies.md">Case Studies</a>
