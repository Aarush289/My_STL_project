#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int points,query;
        scanf("%d%d",&points,&query);
        int arrayp[points];
        long long int arrayq[query];
        for(int i=0;i<points;i++){
            scanf("%d",&arrayp[i]);
        }
        for(int i=0;i<query;i++){
            scanf("%lld",&arrayq[i]);
        }
        int n=points;
        int segments=(n*(n-1))/2;
         int arrays[segments];
        for(int i=0;i<segments;i++){
            arrays[i]=0;
        }
        int j=0;
        int number;
        long long int h;
        for(int i=arrayp[0];i<=arrayp[points-1];i++){
            number=0;
            if(i==arrayp[j])
            { 
                number=number+((j+1)*(points-j-1))+j;
                  j++;      
            }
            else{number=number+((j)*(points-j));}
            arrays[number-1]++;
        }
        for(int i=0;i<query;i++){
                h=arrayq[i]-1;
            if(arrayq[i]<=segments){
            printf("%d ",arrays[h]);}
            else{printf("0 ");}
        }
        printf("\n");
    }
    return 0;
}