#include <stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n; 
        scanf("%d",&n);
        int line[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &line[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(i%2==0){
                sum+=line[i];
            }
            else{
                sum-=line[i];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}