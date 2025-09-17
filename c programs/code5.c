#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,operations;
        scanf("%d%d",&n,&operations);
        int array[n];
        for(int j=0;j<n;j++){
            scanf("%d",&array[j]);
        }
        for(int j=0;j<operations;j++){
            int l,u;
            char cha;
            getchar();
            scanf("%c%d%d",&cha,&l,&u);
            switch(cha){
                case '+':
                for(int k=0;k<n;k++){
                    if(l<=array[k]&&array[k]<=u){
                        array[k]++;
                    }
                }
                break;
                case '-':
                for(int k=0;k<n;k++){
                    if(l<=array[k]&&array[k]<=u){
                        array[k]--;
                    }
                }
            }
            int max;
            max=array[0];
            for(int k=0;k<n;k++){
                if(array[k]>max){
                    max=array[k];
                }
            }
            printf("%d ",max);
        }
        printf("\n");
    }
}