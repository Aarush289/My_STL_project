#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
      int n,m;
      scanf("%d%d",&n,&m);
      int count=0;
      int temp=n;
      while(n!=0){
          n/=10;
          count++;  
      }
      n=temp;
      int arrlarge[count];
      int arrsmall[count];
      if(n<m){int temp=n;n=m;m=temp;}
      if(debug){printf("%d\n",m);}
      for(int i=0;i<count;i++){
         arrlarge[i]= (n%10);
         n=n/10;
      }
     if(debug){   for(int i=0;i<count;i++){
         printf("%d",arrlarge[i]);
      }
      printf("\n");
     }
     
      for(int i=0;i<count;i++){
         arrsmall[i]= (m%10);
         m=m/10;
      }
       if(debug){   for(int i=0;i<count;i++){
         printf("%d",arrsmall[i]);
      }
      printf("\n");
     }
      int j=count-1;
      while(arrlarge[j]==arrsmall[j]){
         j--;
      }
      if(debug){printf("%d\n",j);}
      for(int i=j-1;i>=0;i--){
         if(arrlarge[i]>arrsmall[i]){int temp=arrlarge[i];arrlarge[i]=arrsmall[i];arrsmall[i]=temp; }
      }
      for(int i=count-1;i>=0;i--){
         printf("%d",arrlarge[i]);
      }
      printf("\n");
       for(int i=count-1;i>=0;i--){
         printf("%d",arrsmall[i]);
      }
      printf("\n");
   }
}