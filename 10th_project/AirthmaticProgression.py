from functools import reduce
class AirthmaticProgression:
    def nterm(self,firstterm,cd,n,term):
        
        if firstterm != 0 and cd != 0 and n != 0 and term == 0:
             return firstterm+(n-1)*cd
        elif firstterm==0 and cd != 0 and n != 0 and term != 0:
            return term-(n-1)*cd
        elif cd==0 and firstterm != 0 and n != 0 and term != 0:
            return (term - firstterm)/(n-1)
        elif n==0 and firstterm != 0 and cd != 0 and  term != 0:
            value = ((term - firstterm)/cd)+1
            if type(value)==float():
                print ("AP doesn't exist")
            return value
    def form_Ap_fromterms(self,n,Tn,m,Tm):
        
        if m>n:
            self.d = (Tm-Tn)/(m-n)
        else:
            self.d = (Tn-Tm)/(n-m)
        d = self.d
        print(d)
        a = Tn-(n-1)*d
        self.a = a
        return (a,(a+d),(a+2*d),(a+3*d))
    
    def checkterm_from_terms(self,n,Tn,m,Tm,t):
        self.formmAp(n,Tn,m,Tm)
        return self.a+(t-1)*self.d
    
    def checkterm(self,a,b,term):
        n = (((term-a)/(a-b))+1)
        if n>=0 and n != float():
            print("yes it is a term of AP ")
        else :
            print("No it's not a term of AP")
    
    def digitsdivisible(self,number,digit):
        
        li = [x for x in range(10**(digit-1),10**(digit))]
        fil =list(filter(lambda x : x%number == 0 , li))
        print(fil)
        sum = reduce(lambda p,q:p+q, fil)
        print(sum)
        
        
    def multiples_in_range(self,number,a,b):
        li = [x for x in range(a,b+1) if x%number==0]
        return len(li)
    
    
    def cd_by_exceed(self,a,exceedby,b):
        return exceedby/(a-b)
    
            
    def sumofterm( self, sumofnterm=0 , firstterm=0 , cd=0 , n=0 , lastterm=0 ):
        if firstterm != 0 and cd != 0 and n != 0 and lastterm==0:
            return (n/2)*(2*firstterm +(n-1)*cd)
            
        elif firstterm != 0 and cd == 0 and n == 0 and lastterm !=0:
            return (n/2)*(firstterm +lastterm)
            
        elif firstterm==0 and sumofnterm!=0 and cd != 0 and n != 0 :
            if lastterm==0 :
                return (((sumofnterm*2)/n)-(n-1)*cd)/2
            else :
                return ((sumofnterm*2)/n)-lastterm
                
        elif cd==0 and lastterm==0 and sumofnterm!=0 and firstterm != 0 and n != 0  :
            return (((sumofnterm*2)/n)-2*firstterm)/(n-1)
        elif n==0 and lastterm==0 and sumofnterm!=0 and firstterm != 0 and cd !=0 :
            value2 = (-(2*firstterm - cd) + (((firstterm - cd)**2)+(8 * cd * sumofnterm))**(1/2))/(2*cd)
            value3 =  (-(firstterm - cd) - ((firstterm - cd)**2)+(4 * cd * sumofnterm))/(2*cd)
            print(value2,value3)
            if value2>0:
                return round(value2)
            elif value3>0:
                return round(value3)
            
    def mterm_from_sum(self,firstterm,n,sumofnterms,m):
        self.__cd =  ((sumofnterms)*(2/n)-firstterm)/(n-1)
        return firstterm + (m-1)*self.__cd 
    
    def Ap_from_sumoftwoterms(self,n,sumofnterms,m,sumofmterms):
        if m>n:
            cd =((sumofmterms*2/m) - (sumofnterms*2/n))/(m-n)
        else :
            cd =((sumofnterms*2/n) - (sumofmterms*2/m))/(n-m)
        a = ((sumofnterms*2/n)-(n-1)*cd)/2
        return a,a+cd,a+(2*cd),a+(3*cd)
       
    def sumconsecutive(self,n):
        return n*(n+1)/2
    
    
    def sqrsum(self,n):
        return ((n)*(n+1)*((2*n)+1))/6
    
    def cubesum(self,n):
        return ((n)*(n+1)/2)**2
    
l = AirthmaticProgression()
x = l.sumofterm(0,3,7,25,0)
print(x)
    
    

        
    