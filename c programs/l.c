#include <stdio.h>
#include <stdlib.h>
int main(){
    int array[3]={12,3,23};
    qsort(array);
    printf("%d %d\n",array[0],array[1]);
}