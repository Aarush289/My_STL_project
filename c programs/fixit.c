#include<stdio.h>
int count[101];
void fixit(int A[],int start,int end){
    if(start==end){if(count[end]>0){A[end]=end;}
    else{A[end]=-1;}}
    if(start!=end){if(count[start]>0){A[start]=start;}
                   else{A[start]=-1;} 
                   fixit(A,start+1,end);}
        }
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<101;i++){count[i]=0;}
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        count[A[i]]++;
    }
    fixit(A,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}