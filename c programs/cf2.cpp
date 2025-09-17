#include<bits/stdc++.h>
using namespace std;
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        long long int n,k,temp;
        scanf("%lld%lld",&n,&k);
        temp=k;
        long long int a[n];
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        long long int dif[n];
        dif[0]=a[0];
        long long int count[n+1];
        count[0]=0;
       for(long long int m=1;m<n+1;m++){ count[m]=1;}
        long long int l=1;
        long long int but=0;
        for(long long int k=1;k<n;k++){
            dif[k]=a[k]-a[k-1];  
                   if(dif[k]==0){count[l]++;}
                   else{l++;}   }
                   long long int p=0;
                  long long int c=0;
                /* for(int j=0;j<n+1;j++){
                    printf("%d\n",count[j]);
                  }*/
        while(k>=(n)*(dif[c])){
            k-=(n)*(dif[c]);
          //  printf("%lld\n",k);//
            but+=((n)*(dif[count[p]]))+count[p];
         //  printf("%lld\n",but);//
            p++;
            c+=count[p];
            n-=count[p];
        } 
        if(k!=0){but+=(k+count[p]);}
        printf("%lld\n",but);
    }
}