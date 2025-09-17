#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int k;
        scanf("%d",&k);
        int arr[k];
        for(int j=0;j<k;j++){
            scanf("%d",&arr[j]);
        }
        int pro= k-2;
        int flag=0;
        int flag2=0;
        int b=0;
        int c=k-1;
        int num;
        int num2;
        while(1){
            while(pro%arr[b] !=0){
                b++;
            }
            while(pro%arr[c]!=0){
                c--;
            }
            num2= pro/arr[c];
            num = pro/arr[b];
            for(int j=b+1;j<k;j++){
                if(arr[j]==num){flag=1;break;}
            }
            
            if(flag==1){break;}
            for(int j=c-1;j>=0;j--){
                if(arr[j]==num2){flag2=1;break;}
            }
            if(flag2==1){break;}
            b++;
            c--;
        }
        if(flag){
        printf("%d %d\n",arr[b],num);}
        else{printf("%d %d\n",arr[c],num2);}
    }
}