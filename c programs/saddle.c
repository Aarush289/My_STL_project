#include<stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int mat[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int min[m];
    for(int i=0;i<m;i++){
        min[i]=mat[i][0];
    }
    int column[m];
    for(int i=0;i<m;i++){
        column[i]=0;
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(min[i] > mat[i][j]){
                min[i] = mat[i][j];
                column[i]=j;
                }
        }
    }
    int max=min[0];
    int row=0;
    int col;
    col=column[0];
    for(int i=0;i<n;i++){
        if(max<min[i+1]){}
        else{max=min[i+1];row=i;col=column[i];}
    }
    int flag=0;
    for(int j=0;j<m;j++){
        if(max>=mat[j][col]){}
        else{flag=1;break;}
    }
    if(flag==0){printf("%d\n",mat[row][col]);}
    else{printf("No\n");}
}