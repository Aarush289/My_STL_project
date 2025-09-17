#include <stdio.h>
#include <math.h>
int main(){
    int objects;
    scanf("%d",&objects);
    int temp[objects];
    for(int i=0;i<objects;i++){
        scanf("%d",&temp[i]);
    }
    int q;
    scanf("%d",&q);
    int def[objects-1];
    for(int i=0;i<objects-1;i++){
        def[i]=abs(temp[i]-temp[i+1]);
    }
    int t=0;
    while(t==0){
    if(q<1){break;}
    q--;
    int q1;
    scanf("%d",&q1);
    switch(q1){
        case 1:
        int k,p;
        scanf("%d %d",&k,&p);
        def[k]=abs(temp[k]-temp[k-1]);
        def[k+1]=abs(temp[k+1]-temp[k+2]);
        break;
        case 2:
        int i,t;
        int j;
        for( j=i;j<objects-1;j++){
            if(def[j]<=t){}
            else{break;}
        }
        t++;
        printf("%d",j+1);
        break;
    }
    }
    int h=0;
    while(h==0){
        if(q<1){break;}
        q--;
        int q1;
    scanf("%d",&q1);
    switch(q1){
        case 1:
         int k,p;
        scanf("%d %d",&k,&p);
        def[k]=abs(temp[k]-temp[k-1]);
        def[k+1]=abs(temp[k+1]-temp[k+2]);
        h++;
        break;
    }

    }
}