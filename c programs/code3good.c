#include <stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        int n; 
        scanf("%d", &n);
        if(n!=2){
            for(int j=1;j<=n;j++){
                int input;
                scanf("%d",&input);
            }
            printf("No\n");
        }
        else{
            int input1,input2;
            scanf("%d%d",&input1,&input2);
            if((input1-input2)==1||(input1-input2)==-1){
                printf("No\n");
            }
            else{printf("Yes\n");}
        }
    }
    return 0;
}