#include<bits/stdc++.h>
using namespace std;
#define debug 1
int main(){
        int n,num;
        scanf("%d%d",&n,&num);
        int arr[n];
        for(int i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
        int sum=0;
        int i=0;
        int j=0;
        int flag=0;
        while(sum!=num){
                while(sum<num){
                        sum+=arr[j];
                        j++;if(j==n){if(sum<num){flag=1;} 
                        break;}
                }
                if(sum>num){
                        sum-=arr[i];
                        i++;if(i==n){flag=1;break;}
                }
                if(j==(n) && arr[j-1]>num){flag=1;}
                if(flag==1){break;}
                
        }
        if(flag==1){printf("-1\n");}
        else{printf("%d %d\n",i+1,j);}
}