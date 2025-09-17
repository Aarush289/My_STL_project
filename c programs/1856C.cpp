#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){max=arr[i];}
    }
    int count=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]<=arr[i+1]){
            while(arr[i]<arr[i+1])
                {   i++; 
                    if(i>n-2)
                    {   
                      break;
                    }
                }                
            count++;
        }
    }
 //   printf("%d\n",count);//
    int arri[count];
    int answer[count];
    int j=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]<=arr[i+1]){while(arr[i]<arr[i+1]){i++;if(i>n-2){break;}} if(i<n-2 && arr[i]==arr[i+1]){i++;} arri[j]=i;j++;}
    }
    /*for(int i=0;i<count;i++){
        printf("%d ",arri[i]);
    }
    printf("\n");*/

    for(int i=0;i<count;i++){
        int temp=k;
        int temparr[n];
        for(int i=0;i<n;i++){
            temparr[i]=arr[i];
        }
       if(arri[i]==0){answer[i]=0;i++;}
       int j=arri[i];
       if(j==n-2 && temparr[j]==temparr[j+1]){temparr[j]++;temp--;}
        while(temp > temparr[j]-temparr[j-1] && j>0 && temparr[j]>=temparr[j-1]){
                 temp-= (temparr[j]-temparr[j-1]+1);
                temparr[j-1]=temparr[j]+1;
                j--;
        }
        answer[i]=temparr[j];
    }
    /*for(int i=0;i<count;i++){
        printf("%d ",answer[i]);
    }
    printf("\n");*/
    for(int i=0;i<count;i++){
        if(max<answer[i]){max=answer[i];}
    }
    printf("%d\n",max);
   }
}