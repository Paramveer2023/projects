import matplotlib.pyplot as plt
class coordinateGeometry:
    def distance(self,ax,ay,bx,by):
        return ((bx-ax)**2+(by-ay)**2)**(1/2)
    def draw(self,ax,ay,bx,by):
        x = [ax,ay]
        y = [bx,by]
        plt.plot(x, y)
        
    
    def check_collinear(self,ax,ay,bx,by,cx,cy):
        s = 0.5*(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by))
        if s==0:
            print('Lines are collinear')
        else:
            print('Lines are non-collinear')
            
    def distance_o(self,x,y):
        return self.distance(x, y, 0, 0)
    
    def area_traingle(self,ax,ay,bx,by,cx,cy):
        return 0.5*(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by))
    
    def centroid(self,ax,ay,bx,by,cx,cy):
        x = (ax+bx+cx)/3
        y = (ay+by+cy)/3
        return (x,y)
    
    def area_quadrilateral(self,ax,ay,bx,by,cx,cy,dx,dy):
        A = 0.5*(ax*(by-dy)+bx*(dy-ay)+dx*(ay-by))
        B = 0.5*(bx*(cy-dy)+cx*(dy-by)+dx*(by-cy))
        return A+B
    
    def length_daigonal(self,ax,ay,bx,by,cx,cy,dx,dy):
        AC = self.distance(ax,ay,cx,cy)
        BD = self.distance(bx,by,dx,dy)
        return AC,BD
    
    
    
    def check_quadrilateral(self,ax,ay,bx,by,cx,cy,dx,dy):
        AB = self.distance(ax,ay,bx,by)
        AD = self.distance(ax,ay,dx,dy)
        BC = self.distance(bx,by,cx,cy)
        CD = self.distance(cx,cy,dx,dy)
        AC = self.distance(ax,ay,cx,cy)
        BD = self.distance(bx,by,dx,dy)
        if AB==CD and AD==BC and AC==BD and BC!=AD and CD!=AB :
            print("It's Rectangle")
        elif AB==CD and AD==BC and AC!=BD:
            print("It's Parallelogram")
        elif AB==AD and AB==CD and BC==AD and CD==AB and AC==BD:
            print("It's Square")
        elif AB==AD and AB==CD and BC==AD  and CD==AB and AC!=BD:
            print("It's Rhombus")
        else :
            print("It's a random quadrilateral")
            
    def Isection_cordinates(self,ax,ay,bx,by,m,n):
        x = (m*bx+n*ax)/(m+n)
        y = (m*by+n*ay)/(m+n)
        return (x,y)
        
    def Osection_cordinates(self,ax,ay,bx,by,m,n):
        x = (m*bx-n*ax)/(m-n)
        y = (m*by-n*ay)/(m-n)
        return (x,y)
    
    def trisection_cordinates(self,ax,ay,bx,by):
        x = (ax*2+bx)/3
        y = (ay*2+by)/3
        X = (x+bx)/2
        Y = (y+by)/2
        return (x,y),(X,Y)
    
    def Isection_ration(self,ax,ay,bx,by,X,Y):
        n = (bx-X)
        m = (X-ax)
        return "{}/{}".format(m,n)
    def Osection_ration(self,ax,ay,bx,by,X,Y):
        m = (X-bx)/(X-ax)
        return m
c=coordinateGeometry()
x=c.check_quadrilateral()
    