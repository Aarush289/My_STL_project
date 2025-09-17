#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n;
        scanf("%d",&n);
        int arr1[n];
        int arr2[n];
        int arr3[n];
        int answer=0;
        int max1=1;max2=1;max3=1;
        int in1=0,in2=0,in3=0;
        for(int i=0;i<n;i++){
            scanf("%d",&arr1[i]);
            if(max1<arr1[i]){max1=arr1[i];in1=i;}
        }
         for(int i=0;i<n;i++){
            scanf("%d",&arr2[i]);
            if(max2<arr2[i]){max2=arr2[i];in2=i;}
        }
         for(int i=0;i<n;i++){
            scanf("%d",&arr3[i]);
            if(max3<arr3[i]){max3=arr3[i];in3=i;}
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);
        sort(arr3,arr3+n);
        int max,semimax;
        if(in1!=in2 && in2!=in3 && in3!=in1){printf("%d\n",max1+max2+max3);}
        else{
        if(max1>max2){semimax=max1;}
        else{semimax=max2;}
        if(semimax>max3){max=semimax;}
        else{max=max3;}
        answer+=max;
        if(max==max1){
                if(in2==in1){
                    if(in2!=in3){
                        max2=arr2[n-2];
                        answer+=max2;
                        answer+=max3;
                    }
                    else{
                        
                    }
                }
        }
        }
    }
}