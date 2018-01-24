using System;
using System.Collections.Generic;
using System.Text;

namespace ClockClasses
{
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
     ** Concept = Second hand + clock face
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
            cur = list;
            while (cur != null)
            {
                cur = cur.next; counter++;
            }
            cur = list; counter = 0;
            probe = ".second: " + counter.ToString();
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
        public TopNode() {
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
            cur = list;
            while (cur != null)
            {
                cur = cur.next; counter++;
                this.component.Run();
            }
            cur = list; counter = 0;
            probe = ".minute: " + counter.ToString() + this.component.probe;
        }
    }


    /* BottomNode class
     ** Concept = Hour hand + clock face (dial)
     */
    public class BottomNode : Composite
    {
        public BottomNode()
        {
            this.component = new TopNode();
            state = new Item(); stateList = state;
            this.list = new Item(); cur = list;
            for (int i = 1; i < 12; i++)
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
            probe = "Haur:"+counter.ToString() + this.component.probe;
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
