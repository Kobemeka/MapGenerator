import matplotlib.pyplot as plt
import random
import numpy as np

class Point:
    def __init__(self,x,y) -> None:
        self.x = x
        self.y = y
    def __add__(self,other):
        return Point(self.x + other.x, self.y + other.y)
        
    def __radd__(self,other):
        if other == 0:
            return self
        else:
            self.__add__(other)
    def __truediv__(self,other):
        return Point(self.x/other,self.y/other)

def midPoint(p1:Point, p2:Point):
    return (p1+p2)/2

def slope(p1,p2):
    return (p1.y-p2.y)/(p1.x-p2.x)

def bisec(p1,p2):
    bslope = -1/slope(p1,p2)
    bmid = midPoint(p1,p2)
    return (bslope, bmid.y - bslope * bmid.x)

def bisecxy(p1,p2):
    bsc = bisec(p1,p2)
    return [[-bsc[1]/bsc[0],(width-bsc[1])/bsc[0]],[0,height]]


width = 256
height = 256

xvals = np.linspace(0,width,2)
yvals = np.linspace(0,height,2)

pointSize = 5

points = [Point(random.randrange(0,width),random.randrange(0,height)) for _ in range(pointSize)]
midpoints = []
bisecs = []
bisecsxys = []
for i in range(pointSize):
    p1 = points[i]

    for j in range(i+1,pointSize):
        p2 = points[j]

        midpoints.append(midPoint(p1,p2))
        bisecs.append(bisec(p1,p2))
        bisecsxys.append(bisecxy(p1,p2))

plt.xlim(0,width)
plt.ylim(0,height)
plt.scatter(list(map(lambda p: p.x,points)),list(map(lambda p: p.y,points)),c="b")
plt.scatter(list(map(lambda p: p.x,midpoints)),list(map(lambda p: p.y,midpoints)),c="r")
for b in range(len(bisecsxys)):
    plt.plot(bisecsxys[b][0],bisecsxys[b][1])
plt.show()