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
    scanf("%d",&r1.lower.xcoord);
    scanf("%d",&r1.lower.ycoord);
    scanf("%d",&r1.upper.xcoord);
    scanf("%d",&r1.upper.ycoord);
    while(1){
        r1.upper.xcoord--;
        r1.lower.xcoord++;
        r1.upper.ycoord--;
        r1.lower.ycoord++;
        if(r1.lower.xcoord >= r1.upper.xcoord){break;}
        printf("%d %d %d %d\n",r1.lower.xcoord,r1.lower.ycoord,r1.upper.xcoord,r1.upper.ycoord);
    }
}