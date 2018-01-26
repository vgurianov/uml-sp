using System;
using System.Collections.Generic;
using System.Text;

namespace ClockClassesAlt
{
    /* Simulation of gear train in clock (observer of seconds hand)
    * 
    * Using:
    *   pWorld = new Root();
    * 
    *   pWorld.Run();
    *   label1.Text = pWorld.probe;
    */

    public class Item
    {
        public Item next;
        public Item()
        {
            next = null;
        }
    }
    /* Class Component
     * 
     */
    public abstract class Component
    {
        public string probe; public int counter;
        public Item list, cur;
        public Item stateList, state;
        public virtual void Run()
        {
        }
    }
    /* class Leaf
     ** Concept = Hour hand + clock face
     */
    public class Leaf : Component
    {
        public Leaf()
        {
            state = new Item(); stateList = state;
            this.list = new Item(); cur = list;
            for (int i = 1; i < 60; i++)
            {
                cur.next = new Item();
                cur = cur.next;
            }
            cur = list;
            probe = ""; counter = 0;
        }
        public override void Run()
        {
            cur = cur.next;
            if (cur == null) { cur = list; counter++; state = state.next; };
            probe = ".hour: " + counter.ToString();
        }
    }
    public abstract class Composite : Component
    {
        public Component component;
    }

    /* TopNode class
     ** Concept = Minute hand + clock face
     */
    public class TopNode : Composite
    {
        public TopNode()
        {
            state = new Item(); stateList = state;
            this.component = new Leaf();
            this.list = new Item(); cur = list;
            for (int i = 1; i < 60; i++)
            {
                cur.next = new Item();
                cur = cur.next;
            }
            cur = list;
            probe = ""; counter = 0;

        }

        public override void Run()
        {
            cur = cur.next;
            if (cur == null) { cur = list; counter++; this.component.Run(); state = state.next; };
            probe = ".minute: " + counter.ToString() + this.component.probe;
        }
    }


    /* BottomNode class
     ** Concept = Second hand + clock face (dial)
     */
    public class BottomNode : Composite
    {
        public BottomNode()
        {
            this.component = new TopNode();
            state = new Item(); stateList = state;
            this.list = new Item(); cur = list;
            for (int i = 1; i < 12*60*60; i++)
            {
                cur.next = new Item();
                cur = cur.next;
            }
            cur = list;
            probe = ""; counter = 0;
        }
        public override void Run()
        {
            this.component.Run();
            if (cur == null) { cur = list; counter = 0; };
            probe = "Second: "+counter.ToString() + this.component.probe;
            cur = cur.next; counter++;
        }
    }
    /* Root class
     ** Concept = Earth
     */
    public class Root : Composite
    {
        public Root()
        {
            this.component = new BottomNode();
        }
        public override void Run()
        {
            this.component.Run();  // 24 times
            this.probe = this.component.probe;
        }
    }

}

