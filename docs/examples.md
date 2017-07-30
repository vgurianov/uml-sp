# A general simulation models
## Dialogs
In this example we shall simulated dialogs between humans.<br/>
**Application domain:** Greeting <br/>
– Good morning, Mr. Goldsmith. It’s been a long time since we met. How nice to see you again.
– How do you do, Mr. Brown. I’m glad to see you too. How are you?
– Not bad, thank you /Thanks, not so well.<br/>

<p>Ontology depicted in picture:</p><br>
<p><img src="examples/dialogs.png" alt="" /></p><br>
<p>Formal describe this definition is a ontology depicted in class diagram.<br /></p>
<ul>
  <li>The “Component” frame define “Subject” concept. This frame has “name” and “next” slots.<br /></li>
  <li>The “Leaf” frame  define “Human” concept.<br /></li>
  <li>The “Composite” frame define “Dialog space” concept and has “pl” slot.<br /></li>
  <li>The “Root” frame define “Environment” concept . It is initial and boundary conditions.<br /></li>
  <li>The “Node” frame define “Greeting” concept and has “msg” slot. It is the system under study.<br />
Class operations define a rule of change of slot.


# Scientific models

## Paradox of barber

**Application domain:** The paradox of barber by Bertrand Russell<br/> 
A traditional model of DES is a queue. A concrete queue considers for model of the barber paradox by Bertrand Russell. Suppose we want to build model for the paradox of barber by Bertrand Russell. We do not discuss paradox, but present an object-oriented model. Remind, the barber is the "one who shaves all those, and those only, who do not shave themselves." The question is, does the barber shave himself? The queue is the sequence of village males to the barber. A class diagram from an Analysis Model depicted in Figure 10<br/>
<p><img src="examples/barber.png" alt="" /></p><br>
