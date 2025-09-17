#include<stdio.h>
void printtab(int k){
    if(k==0){return ;}
    else{printf(" \t");printtab(k-1);}
}
void printarray(char*s,int low,int high,int numtabs){
    if((low-high)==1){return ;}
    printtab(numtabs);
    printf("%c\t%c\n",*(s+low),*(s+high));
    printarray(s,low+1,high-1,numtabs+1);
}
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char str[n];
    for(int i=0;i<n;i++){
        scanf("%c",&str[i]);
    }
    printarray(str,0,n-1,0);
}