#include<stdio.h>
struct point{
    int xcoord;
    int ycoord;
};
struct rectangle{
    struct point lower;
    struct point upper;
};
int main(){
    struct rectangle r1;
    struct rectangle r2;
    scanf("%d",&r1.lower.xcoord);
    scanf("%d",&r1.lower.ycoord);
    scanf("%d",&r1.upper.xcoord);
    scanf("%d",&r1.upper.ycoord);
     scanf("%d",&r2.lower.xcoord);
    scanf("%d",&r2.lower.ycoord);
    scanf("%d",&r2.upper.xcoord);
    scanf("%d",&r2.upper.ycoord);
    if((r1.lower.xcoord + r1.upper.xcoord == r2.lower.xcoord + r2.upper.xcoord) && (r1.lower.ycoord + r1.upper.ycoord == r2.lower.ycoord + r2.upper.ycoord))
    {printf("Yes\n");}
    else{printf("No\n");}
}