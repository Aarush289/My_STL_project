//For radix sort my code is 
#include <bits/stdc++.h>
using namespace std;
void radix(int arr[] , int n)
{
    int max_element = arr[0];
    for(int i=1;i<n;i++){
        max_element = max( max_element , arr[i]);
    }
    for(int place =1;max_element/place >0;place*=10){
        int count[10]={0};
        for(int i=0;i<n;i++){
            count[(arr[i]/place)%10]++;
        }
        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        int res[n];
        for(int i=n-1;i>=0;i--){
            res[count[(arr[i]/place)%10] -1] = arr[i];
            count[(arr[i]/place)%10]--;
        }
        for(int i=0;i<n;i++){arr[i]=res[i];}
    }
}

int main(){
    int arr[10] = {12 , 1342 ,123 , 1234, 65,3246 ,56 ,3 ,90 ,840};
    radix(arr ,10);
    for(int i=0;i<10;i++){cout << arr[i] << endl;}
}