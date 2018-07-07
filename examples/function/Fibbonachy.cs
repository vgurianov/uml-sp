using System;
using System.Collections.Generic;
using System.Text;

namespace Sequence
{
    /* Problem by Fibbonachy
     * 
     * Un+2 = Un+1 + Un, U1 = U2 = 1
     * 1, 1, 2, 3, 5, 8, 13, ...
     */

    // ** Concept = Couple of rabbits
    public class Node
    { 
        public string val;
        public int val1;

        public bool state;  // Adult(mature) or childish couple of rabbits
        public Node next; 
        public Node previous;
        public Node()
        {
            val = "?";
            next = null; previous = null;
            state = false;
        }
    }
    public class Dependencis
    {
        public Node x, t;  // argument
        public Node y, f;  // function

        public string probe;  // observer
        int ix, iy; // count of elements
        int last_y; // previous of number

        public Dependencis()
        {
            // ** x is a month
            x = new Node(); x.val1 = 0;
            t = x;
            for (int i = 0; i < 12; i++)
            {
                t.next = new Node(); t.val1 = i + 1;
                //t.next.previous = t; 
                t = t.next;
            }
            ix = 0; iy = 0;
            t = x;
            // ** y is the couple of rabbits
            y = new Node(); y.state = false;
            y.next = new Node(); y.next.state = true;
            last_y = 1;
        }
        public void Run()
        {
            fbSequence();
        }
        public void fbSequenceNumeric()
        {
            int fb0, fb1, fb;
            fb0 = 1; fb1 = 1;
            for (int i = 3; i<12; i++) {
                fb = fb0 + fb1;
                fb0 = fb1; fb1 = fb;
            }

        }
        public void fbSequence()
        {
            Node ytmp; 
            if (t != null)
            {
                ix++;
                Node yt = y;
                int iy = 0; // mature couple of rabbits
                int yy = 0; // all couple of rabbits
                do
                {
                    if (yt.state)
                    {
                        iy++; // count
                        //y.previous = new Node(); yt = y0; y = y.previous; y.next = yt;
                        ytmp = new Node(); ytmp.state = false;
                        // insert to head of list
                        ytmp.next = y; y = ytmp;
                    }
                    else { yt.state = true; };

                yt = yt.next; yy++;
                } while (yt != null);

                t = t.next;
                probe = ix.ToString() + ", " + iy.ToString() + ", " + yy.ToString() + ", " + (Convert.ToDouble(iy)/Convert.ToDouble(last_y) ).ToString();
                last_y = iy;
            }
            else probe = "The end";
        }

    } // public class Dependencis
}
