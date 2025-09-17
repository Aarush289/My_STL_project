#include <bits/stdc++.h>
using namespace std;
 
long long int poww(long long int base,long long int exp,long long int p)
{
    long long int answer = 1;
    long long int c=base;
    while(exp){
        if(exp%2 == 0){
            exp/=2;
            c = (c*c)%p;
        }
        else{
            exp--;
            answer = (answer*c)%p;
        }
    }
    return(answer);
}
long long int modInverse(long long int a,long long int p)
{
    long long int k=p-2;
    long long int answer2;
    answer2 = poww(a,k,p);
    return(answer2);
}
 
long long int computeFac(long long int n,long long int p)
{
    long long int x=1;
    for(int i=n;i>0;i--)
 {
        x=x*i;
        x=x%p;
    }
    return(x);
}
 
long long int computeNCR(long long int n,long long int r,long long int p)
{
    long long int n2= computeFac(n-r,p);
    long long int n1= computeFac(n,p);
    long long int n4= modInverse(n2,p);
    long long int ans = n4 % p;
    ans = ans * (n1%p);
    ans=ans%p;
    return(ans);
}
 
 
int main(){
    int n,k,position,mid;
    scanf("%d%d%d",&n,&k,&position);
    int count1=0,count2=0;
    int low=0;
    int high=n;
    while(low<high){
        mid=(low+high)/2;
        if(mid<=position){
            low=mid+1;
            if(mid!=position){
                count1++;
  }
        }
        else{high=mid;count2++;}
    }
    int less=k-1;
    int more=n-k;
    if(count1 >less || count2 >more)
    {
        cout << "0\n";
    }
    else
    {
       long long int p= 1000000007;
    long long int answer1= computeNCR(less,count1,p);
    long long int answer2= computeNCR(more,count2,p);
    long long int answer3= computeFac((n-count1-count2-1), p);
    answer1=answer1*answer2;
    answer1=answer1 %p;
    answer1=answer1*answer3;
    answer1=answer1 %p;
    printf("%d\n",answer1);
}
}