#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
      int n;
      scanf("%d",&n);
      if(n<=4){printf("-1\n");}
      else{for(int i=1;i<=(n/2);i++){
        if(2*i!= 4) printf("%d ",2*i);
      }
      printf("4 5 ");
      if(n%2==0){ for(int i=1;i<=(n/2);i++){
        if(2*i!=6){ printf("%d ",(2*i)-1);}
      }}
      else{
         for(int i=1;i<=(n/2)+1;i++){
        if(2*i!=6){ printf("%d ",(2*i)-1);}
      }
      }
      printf("\n");
      }
   }
}