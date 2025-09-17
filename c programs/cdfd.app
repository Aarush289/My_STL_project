#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
         if(x==y){printf("0 0 %d %d\n",x,x);
                  printf("0 %d %d 0\n",x,x) }
         else
         {
            int ax,ay,bx,by,cx,cy,dx,dy;
            ax=0;
            ay=0;
            if(x>y){
               for(int i=(y);i>=(y-x);i--){
                  if((x*x)+((y-i)*(y-i))>=(k*k)){break;}
               }
               bx=x;
               by=y-i;
               cx=0;
               cy=x;
               dx=y-i;
               dy=0;

            }
            else{
                 for(int i=(x);i>=(x-y);i--){
                  if((y*y)+((x-i)*(x-i))>=(k*k)){break;}
               }
               bx=x-i;
               by=y;
               cx=0;
               cy=x-i;
               dx=y;
               dy=0;
            }
            printf("%d %d %d %d\n",ax,ay,bx,by);
            printf("%d %d %d %d\n",cx,cy,dx,dy);
         }
         

       
   }
}