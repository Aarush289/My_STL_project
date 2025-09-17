#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int flag=1;
    int j=0;
    while(flag==1){
        for(int i=j;i<n-1;i++){
            flag=0;
            if(array[i]>=array[i+1]){}
            else{j=i;flag=1;break;}
        }
        for(int k=j+1;k>0;k--){
            if (array[k]>array[k-1])
            {
                int temp=array[k-1];
                array[k-1]=array[k];
                array[k]=temp;
            }
            else{break;}
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",array[i]);
    }
    return 0;
}