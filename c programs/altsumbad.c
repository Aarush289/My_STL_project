#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    int output[cases];
    for(int done=0;done<cases;done++){
        int inputs;
        scanf("%d",&inputs);
        int array[inputs];
        for(int j=0;j<inputs;j++){
        scanf("%d",&array[j]);
        }
        int sum=0;
        for(int i=0;i<inputs;i++){
            if(i%2==0){sum=sum+array[i];
            }
            else{sum=sum-array[i];
            }
        }
        output[done]=sum;
    }
    for(int o=0;o<cases;o++ ){
        printf("%d\n",output[o]);
    }   
}