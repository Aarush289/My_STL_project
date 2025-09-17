# include<stdio.h>
#include<stdlib.h>
# define debug 1
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}
int main(){
    int cases;
    scanf("%d",&cases);
    for(int l=0;l<cases;l++){
        int n,x;
        scanf("%d%d",&n,&x);
        int arr[n];
        int temp[n];
        temp[0]=0;
        scanf("%d",&arr[0]);
        int max=arr[0];
        int count1=1;
        for(int i=1;i<n;i++){
            scanf("%d",&arr[i]);
            temp[i]=0;
            if(max<arr[i]){max=arr[i];count1=1;}
            if(max==arr[i]){count1++;}
        }
        count1--;
        if(debug){printf("%d\n",count1);}
        if(debug){printf("%d\n",max);}
        int p=0;
        int i=0;
        qsort(arr, n, sizeof(int), compare);
        while(i<n){
            int j;
            for(j=p;j<n;j++){
                temp[i]+=arr[j];
                if(temp[i]>max){break;}
            }
             temp[i]-=arr[j];
             if(arr[j]==max){break;}
             i++;
             p=j;
        }
        for(int j=i+1;j<i+1+count1;j++){temp[j]=max;}
         if(debug){for(int i=0;i<n;i++){printf("%d ",temp[i]);}printf("\n");}
        qsort(temp, n, sizeof(int), compare);
        if(debug){for(int i=0;i<n;i++){printf("%d ",temp[i]);}printf("\n");}
        int k=n-(i+count1+1);
        if(debug){printf("%d\n",k);}
        int answer=0;
        
        for(int p=k;p<k+x;p++){
            int min=temp[p];
            int count=0;
            for(int j=k;j<k+x;j++){
                if(j>=n){break;}
                else{
                if(temp[j]==min){count++;}}
            }
           if(debug){ printf("%d %d\n",min,count);}
            answer+=min;
            for(int j=k;j<k+x;j++){
               if(j<n){ temp[j]-=min;}
            }
            k=k+count;
           if(debug){ printf("%d\n",k);}
            if(k>=n){break;}
        }
       printf("%d\n",answer);
    }
}