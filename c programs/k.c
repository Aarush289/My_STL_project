#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int main(){
   int arr[5]={23,1,24,4,4};
   qsort(arr, 5, sizeof(int), compare);
   printf("%d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
}