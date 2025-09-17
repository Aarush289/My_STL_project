#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++)
    {
        int seats,teach,query;
        scanf("%d%d%d",&seats,&teach,&query);
        int arrt[teach];
        for(int i=0;i<teach;i++){
            scanf("%d",&arrt[i]);
        }
        int arrq[query];
        for(int i=0;i<query;i++){
            scanf("%d",&arrq[i]);
        }
        sort(arrt,arrt+teach);
       if(debug){ for(int i=0;i<teach;i++){printf("%d\t",arrt[i]);}
        printf("\n");}
        for(int j=0;j<query;j++){
        if(arrt[teach-1]<arrq[j]){
            printf("%d\n",seats-arrt[teach-1]);
        }
        else{
            if(arrt[0]>arrq[j]){printf("%d\n",arrt[0]-1);}
            else{
                int k;
               int low =0;
               int high= teach-1;
               while(low<=high){
                k=(low+high)/2;
                if(arrt[k]>arrq[j]){
                    if(arrt[k-1]<arrq[j]){break;}
                     else{high=k;}
                }
                else{if(arrt[k+1]>arrq[j]){k++;break;}else{low=k+1;}}
               }

                //printf("%d\n",arrt[k]);//
                printf("%d\n",(arrt[k]-arrt[k-1])/2);
            }
        }
        }
    }
}
