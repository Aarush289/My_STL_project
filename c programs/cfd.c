#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int inputs;
        scanf("%d",&inputs);
        int array[inputs];
        for(int i=0;i<inputs;i++){
            scanf("%d",&array[i]);
        }
        if(inputs==1){printf("%d\n",array[0]+1);}
        else{
        int max1=0;
        int k;
        int max11=array[0];
        for(k=0;k<inputs;k=k+2){
            max1++;
        }
        for(k=0;k<inputs;k=k+2){
            if(max11>array[k]){}
            else{max11=array[k];}
        }
        
        max1=max1+max11;
        int max2=0;
        int max22=array[1];
        int l;
         for(l=1;l<inputs;l=l+2){
            max2++;
        }
        for(l=1;l<inputs;l=l+2){
            if(max22>array[l]){}
            else{max22=array[l];}
        }
        max2=max2+max22;
        if(max1>max2){printf("%d\n",max1);}
        else{printf("%d\n",max2);}
        }
    }
}