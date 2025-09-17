#include<bits/stdc++.h>
#define debug 0
using namespace std;
int main(){
         int n;
         scanf("%d",&n);
         getchar();
        char str[100000];
        scanf("%s",str);
        int count=0;
        for(int i=0;i<strlen(str);i++){
         int flag=0;
         for(int j=0;j<i;j++){
            if(str[i]==str[j]){flag=1;}
         }
          if(flag==0){count++;}
        }
        if(debug){printf("%d\n",count);}
        int k=0;
        int arr[count];
        for(int i=0;i<strlen(str);i++){
         int flag=0;
         for(int j=0;j<i;j++){
            if(str[i]==str[j]){flag=1;}
         }
          if(flag==0){arr[k]=i;k++;}
        }

       if(count<n){printf("NO\n");}
       else{
         printf("YES\n");
         int j=0;
         while(j<n-1){
        
           for(int i=arr[j];i<arr[j+1];i++){
            printf("%c",str[i]);
           }
           j++;
            printf("\n");
         }
      /*   printf("%d\n",j);
         printf("%d\n",arr[j]);
         printf("%c\n",str[arr[j]]);*/
           for(int i=arr[j];i<strlen(str);i++){
             printf("%c",str[i]);
           }    
           printf("\n");
         }
       }
