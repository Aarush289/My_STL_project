#include<bits/stdc++.h>
using namespace std;
int main(){
   int cases;
   scanf("%d",&cases);
   while(cases--){
      int n;
      scanf("%d",&n);
      getchar();
      char str[n+1];
      scanf("%s",str);
      char copy[n+1];
      for(int i=0;i<=n;i++){
        copy[i]=str[i];
      }
      sort(str,str+n);
        int count=1;
        int j=1;
        while(str[j]!=0){
            if(str[j]!=str[j-1]){count++;}
            j++;
        }
        if(count>1){
        int freq[count];
        int k=1;
        int i=0;
        for(int i=0;i<count;i++){
            freq[i]=1;
        }
        while(str[k]!=0){
            if(str[k]==str[k-1]){freq[i]++;}
            else{i++;}
            k++;
        }
        int max=freq[0];
        int min=freq[0];
        for(int m=1;m<count;m++){
                if(freq[m]>max){max=freq[m];}
                if(freq[m]<min){min=freq[m];}
        }
        int f=0;
        int l=0;
        while(freq[l]!=max){
            f+=freq[l];
            l++;
        }
        char ma= str[f];
       //printf("%c\n",ma);//
        l=0;
        f=0;
        if(min==max){
        f=min;
        }
        else{
              while(freq[l]!=min){
            f+=freq[l];
            l++;
        }
        }
        char mi;
      //  printf("%d\n",f);//
        if(f==0 ){mi=str[0];}
       // if(f==0 && (max==min)){str[0]=ma;}//
        else{mi=str[f];}
        int h=0;
       // printf("%c\n",mi);//
        while(copy[h]!=mi){
            h++;
        }
        copy[h]=ma;
        }

        printf("%s\n",copy);
   }
}