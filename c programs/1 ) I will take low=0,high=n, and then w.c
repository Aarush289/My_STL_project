1 ) I will take low=0,high=n, and then will check till low<high, the arr[mid] whenever it is 1 ,then I will make high=mid;and whenever it is 0 , I will check if arr[mid+1]=1 if yes then I will break out of loop ,  else I will do low=mid+1 . answer will be mid at last .
code will be :
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     int low=0;
     int high=n;
     int mid;
    while(low<high){
            mid=(low+high)/2;
           if(arr[mid]==0){
            if(arr[mid+1]==1){break;}
            else{low=mid+1;}
           }
           else{high=mid;}
            }
            if(low==mid){printf("Not avaliable\n");}
            else{ printf("%d\n",mid);}
}
2) I will take low=0, if(n<=10^6)high=n, else{high=10^6}, flag=0 and then will check till low<high , if (cube of mid >n) then I will do high =mid; if (cube of mid ==n) then I will do flag=1 and  break out of loop  , if(cube of mid <n) then low=mid +1, then finally out of loop if flag=0, I will print no that means the given n is not perfect cube else I will print yes that is the given number is a perfect cube.
code will be:
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int low=0;
    long long int high;
    if(n>1000000){ high=1000000;}
    else{  high=n;}
     long long int mid;
     long long int flag=0;
    while(low<high){
            mid=(low+high)/2;
            if((mid*mid*mid)==n){flag=1;break;}
            else{
                if((mid*mid*mid)>n){high=mid;}
                else{low=mid+1;}
            }
            }
            if(n==1 || n==1000000000000000000){flag=1;}
            if(flag==0){printf("Not a perfect cube \n");}
            else{ printf("Yes , perfect cube \n",mid);}
}

3) In this question ,we can do one thing but the code will be very inefficient , like I will first check if no of elements is odd or even , if it is odd I will try to find an element such that no of elements less than or equal to that are equal to no of elements greater than equal to that 