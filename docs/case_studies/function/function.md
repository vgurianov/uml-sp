# Numerical and object models

## Introduction
At now wide use numerical methods. In UML2 SP models, numerical calculation nearly use not. It is an important quality of our approach. In this section we shall discuss it topic. 

## Fibonacci sequence
The Fibonacci sequence is a sequence of number when Fn = Fn-1 + Fn-2 with seed values F0 = F1 = 1, 
i.e. any number is sum two previous numbers.<br/> 
A numerical model in C# is
```
public void fbSequenceNumericalModel()
{
  int fb0, fb1, fb;
  fb0 = 1; fb1 = 1;
  for (int i = 3; i<12; i++) 
  {
    fb = fb0 + fb1;
    probe = i.ToString() + ", " + fb.ToString()
    fb0 = fb1; fb1 = fb;
  }
}
```
An object model is following. In the Fibonacci book, this sequence is result of growth of a rabbit population.<br/> 
Let exist one pair of rabbits in start. Mating pair always produces one new pair at one month.<br/> 
New pair grow one month and do not produces new pair. How many pairs will there be in one year?<br/>
Let Node be model of pair of rabbits. A State attribute is a state of the pair and has two values: mature or childish state.<br/> 
The pairs put to cages and the cages build in row. The "previous" and "next" attributes define place of cage to the row.<br/> 
Let x and y be head of linked lists and
```
            y = new Node(); y.state = false;
            y.next = new Node(); y.next.state = true;
```
We consider following algorithm
```
        public void fbSequence()
        {
            if (t != null)
            {
                ix++;
                Node tt = y; int iy = 0; int yy = 0; Node yt;
                do
                {
                    if (tt.state)
                    {
                        iy++;
                        yt = new Node(); yt.next = y; y = yt; }
                    else { tt.state = true; };

                tt = tt.next; yy++;
                } while (tt != null);

                t = t.next; 
                probe = ix.ToString() + ", " + iy.ToString()+ ", " + yy.ToString();
            }
            else probe = "The end";
        },
```
where ix is counter of months, iy is counter of mature pairs, yy is counter of any pairs. 
The "probe" variable is an input data. New node insert to head of linked list.
The run result of the simulation is depicted in Fig.2
<p><img src="Fibonacci.png" alt="" /></p><br>
Figure 2. The Fibonacci sequence simulation<br>
As we see, measurements of simulation give the Fibonacci sequence.

### The simulation model in C# code:  
[Fibbonachy.cs](https://github.com/vgurianov/uml-sp/blob/master/examples/function/Fibbonachy.cs) 

## Conclusion
In this section we discussed numerical and object models. 

## References
1.	[V.I. Gurianov, Simulation with UML SP. Cheboksary: SPbSEU, branch in Cheboksary, 2014. - 136 p.(In Russian)](http://simulation.su/static/en-books.html)
