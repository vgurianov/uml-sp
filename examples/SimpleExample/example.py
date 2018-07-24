# -*- coding: cp1251 -*-
# class Node

class Component:
    name ="noname"
    # next = Component()
    def getMessage(self):
        """ get """
        return 0

    def putMessage(self):
        return 0
    
    
class Leaf(Component):
    def __init__(self, n):
        self.name = n
        
    def getMessage(self):
        return 0
    def putMessage(self, m):
        
        return 0

    
class Composite(Component):
    #pl = Component()
    pass

class Node(Composite):
    msg = "Mr.Toom"
    s = Leaf("Toom")
    def Exist(self):
        return self.pl.name
    
    def __init__(self):
        self.pl = Leaf("Tim")
        

        
if __name__ == "__main__":
    node = Node()
    print ".", node.Exist()
