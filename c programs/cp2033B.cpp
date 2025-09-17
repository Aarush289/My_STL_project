#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
        int n;
        scanf("%d",&n);
        int min[(2*n)-1];
        for(int j=0;j<(2*n)-1;j++){
            min[j]=0;
        }
        int mat[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int k=i;
                    if(min[n-1-i]>mat[j][j-k]){min[n-1-i]=mat[j][j-k];}
                    if(min[n+i-1]>mat[j-k][j]){min[n+i-1]=mat[j-k][j];}
            }
        }
        int answer=0;
        for(int i=0;i<(2*n)-1;i++){
            if(min[i]<0){answer-=min[i];}
        }
        printf("%d\n",answer);
   }

}