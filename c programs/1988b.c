#include<stdio.h>
#include<string.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n;
        scanf("%d",&n);
        char arr[n+1];
        scanf("%s",arr);
        if(arr[0]==1 && arr[n-1]==1){printf("Yes\n");}
        else{
        int count0=0;
        int count1=0;
        for(int i=0;i<strlen(arr);i++){
        int j=i;
        while(arr[i]=='0'){if(i<strlen(arr)){i++;}}
        if(i!=strlen(arr)){count1++;}
        if(i>j){count0++;}
        } 
        if(count1>count0){printf("Yes\n");}
        else{printf("No\n");}
    }
    }
}