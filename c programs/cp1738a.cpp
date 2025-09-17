#include<bits/stdc++.h>
using namespace std;
 int main(){
   long long int cases;
   cin >> cases;
   while(cases--){
      int n,m;
      cin >>n >>m;
      int mat[n][m];
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            cin >> mat[i][j];
         }
      }        
      int count=0;
      for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(mat[i][j]==0){continue;}
            count++;
            for(int row=i;row<n;row++){
               for(int col=j;col<m;col++){
                  if(((row+col)-(i+j)==1)||((row+col)-(i+j)==-1)){continue;}
                  if(mat[row][col]==mat[i][j]){mat[row][col]=0;}
               }
            }
         }
      }
      cout << count <<endl;
   }  
}