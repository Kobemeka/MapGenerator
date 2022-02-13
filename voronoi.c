#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct point
{
    float x;
    float y;

} point;

typedef struct line
{
    float slope;
    float constant;
} line;


float slope(point p1, point p2){
    return (p1.y - p2.y)/(p1.x - p2.x);
}

point midp(point p1, point p2){

    point p = {(p1.x + p2.x)/2, (p1.y + p2.y)/2};
    return (p);
}

line bisector(point p1, point p2){
    float bs_slope = -1.f / slope(p1,p2);
    point mid = midp(p1,p2);
    line bs_line = {bs_slope, mid.y - bs_slope * mid.x};
    return bs_line;
}

int main(){
    srand(time(NULL));

    int width = 100;
    int height = 100;
    
    int ptsSize = 2;
    int bisecSize = ptsSize * (ptsSize - 1)/2;
    float x1, x2, y1, y2, mpx, mpy;

    point midpoints[ptsSize];

    point points[ptsSize];

    line bisectors[bisecSize];

    for (int p = 0; p < ptsSize; p++)
    {
        point newp = {rand()%width, rand()%height};
        printf("x: %f, y: %f\n", newp.x, newp.y);
        points[p] = newp;
    }
    // for (int i = 0; i < ptsSize; i++)
    // {
    //     printf("%f, %f\n", points[i].x, points[i].y);
    // }
    int bisecindex = 0;
    for (int i = 0; i < ptsSize; i++)
    {
        for (int j = i + 1; j < ptsSize; j++)
        {
            // printf("%i, %i, %i\n",i,j,i+j);
            line nbisector = bisector(points[i],points[j]);
            bisectors[bisecindex] = nbisector;
            bisecindex++;
        }
        
    }
    for (int i = 0; i < bisecSize; i++)
    {
        line cb = bisectors[i]; 
        printf("slope: %f, constant: %f\n",cb.slope,cb.constant);
    }
    
    // for (int i = 0; i < ptsSize; i++)
    // {
    //     // point p1 = {rand()%width, rand()%height};
    //     // point p2 = {rand()%width, rand()%height};
    //     point midpptr = midp(p1,p2);

    //     midpoints[i] = midpptr;
    // }
    // for (int i = 0; i < ptsSize; i++)
    // {
    //     printf("%f, %f\n",midpoints[i].x,midpoints[i].y);
    // }
    
    return 0;
}