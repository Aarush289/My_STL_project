#include<stdio.h>
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int mat[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&mat[i][j]);
        }
    }
        if(n>=m){
            for(int k=0;k<=m;k++){
        for(int i=k;i<m-k;i++){
            printf("%d ",mat[k][i]);
        }
        for(int i=k+1;i<n-k;i++){
            printf("%d ",mat[i][m-(k+1)]);
        }
        for(int i=m-(k+2);i>=k;i--){
            printf("%d ",mat[n-(k+1)][i]);
        }
        for(int i=n-(k+2);i>=(k+1);i--){
            printf("%d ",mat[i][k]);
        }
            }
}
else{
    for(int k=0;k<=n;k++){
        for(int i=k;i<m-k;i++){
            printf("%d ",mat[i][k]);
        }
        for(int i=k+1;i<n-k;i++){
            printf("%d ",mat[i][m-(k+1)]);
        }
        for(int i=m-(k+2);i>=k;i--){
            printf("%d ",mat[n-(k+1)][i]);
        }
        for(int i=n-(k+2);i>=(k+1);i--){
            printf("%d ",mat[i][k]);
        }
            }
}
}
