import math

class trignometry:
    def structure(self,height=0,base=0,hypotenus=0,angle=0):
        if hypotenus!=0:
            
        if height==0 and base!=0  and angle!=0:
            return math.tan(angle)*base
        elif height!=0 and base==0  and angle!=0:
            return height/math.tan(angle)
        elif height==0 and base==0  and angle==0: