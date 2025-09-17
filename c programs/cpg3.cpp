#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
      int n;
      scanf("%d",&n);
      int mat[2][n];
      for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
      }
       int answer=0;
      if(n>1){
      for(int i=0;i<n;i++){
        if(mat[0][i]<mat[1][i]){int temp=mat[0][i];mat[0][i]=mat[1][i];mat[1][i]=temp;}
      }
      if(debug){
         for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
      }
      }
      int max=mat[0][0]+mat[1][0];
      if(debug){printf("%d\n",max);}
      int index=0;
      int i=0;
      for(i=1;i<n;i++){
            int sum=mat[0][i]+mat[1][i];
            if(sum>max){index=i;max=sum;}
      }
      int count;
      for(int i=0;i<n;i++){
        int sum=mat[0][i]+mat[1][i];
            if(sum==max){count++;}
      }
      int fre[count];
      int h=0;
      for(int i=0;i<n;i++){
         int sum=mat[0][i]+mat[1][i];
            if(sum==max){fre[h]=i;h++;}
      }
      int maxin=fre[0];
      int min=mat[0][fre[0]];
      for(int i=1;i<count;i++){
            if(mat[0][fre[i]] <min){min=mat[0][fre[i]];maxin=fre[i];}
      }

      }
      if(debug){
        printf("%d %d\n",max,index);
      }
      int temp=mat[0][index];
      mat[0][index]=mat[0][n-1];
      mat[0][n-1]=temp;
     temp=mat[1][index];
      mat[1][index]=mat[1][n-1];
      mat[1][n-1]=temp;
       if(debug){
         for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
      }
      }
      }
     /* printf("%d\n",mat[0][0]);
       printf("%d\n",mat[1][0]);*/
      
     
      for(int j=0;j<n;j++){
        answer+=mat[0][j];
      }
      answer+=mat[1][n-1];
      printf("%d\n",answer);

   }
}