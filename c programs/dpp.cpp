#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n;
        scanf("%d",&n);
        if(n==1){printf("1\n");}
        else{
            if(n%2==0){
               if(n==2){ printf("1 3\n");}
               else{
                for(int i=0;i<n-2;i++){
                    printf("2 ");
                }
                printf("1 3\n");
               }
            }
            else{
                for(int i=0;i<n;i++){
                    printf("2 ");
                }
                printf("\n");
            }
        }
    }
}