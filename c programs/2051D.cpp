#include<bits/stdc++.h>
using namespace std;
#define debug 0
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        long long int n;
        long long int x;
        long long int y;
        cin >> n >> x >> y ;
        long long int arr[n];
        long long int sum=0;
        for(int i=0;i<n;i++){
            cin >> arr[i] ;
            sum+=arr[i];
        }
        //if(debug){cout << sum << endl;}
        sort(arr,arr+n);
        long long int max=(sum-x);
        long long int min=(sum-y);
        long long int count=0;
        long long int minin=0;
        long long int maxin=1;
        while(maxin < n && arr[minin]+arr[maxin] <= max){
            minin++;
            maxin++;
        }
        long long maxin2=0;
        while(maxin2 < n && arr[0]+arr[maxin2] <= max){maxin2++;}
        if(maxin2==n){maxin2--;}
       // if(debug){cout << minin <<"\t" << maxin <<endl;}
       // if(debug){cout << max << "\t" << min << endl;}
        for(long long int i=0;i<maxin;i++){
            long long int j=i+1;
            long long int low =(i+1);
            long long int high=(maxin2);
            int flag=0;
            while(low<=high){
                long long int mid=(low+high)/2;
                if((arr[mid]+arr[i])<=max && (arr[mid]+arr[i])>=min){
                    if(mid!=(n-1)){if(arr[i]+arr[mid+1]>max){j=mid;flag=1;break;}
                    else{low=mid+1;}}
                    else{j=mid;flag=1;break;}
                }
                if((arr[mid]+arr[i])<min){low=mid+1;}
                if((arr[mid]+arr[i])>max){high=mid-1;}
            }
            long long int minin2=(i+1);
            low=(i+1);
            high=(maxin2);
            int flag2=0;
            while(low<=high){
                long long int mid=(low+high)/2;
                if(arr[i]+arr[mid]>=min){high=mid-1;}
                if(arr[i]+arr[mid]<min){
                    if(arr[i]+arr[mid+1]>=min){minin2=mid;flag2=1;break;}
                    else{low=mid+1;}
                }
            }
           // cout << minin2 << "\t" << flag2<< endl;
          if(flag ){  
            if(flag2)
            {
                while(j<(n-1) && arr[j]==arr[j+1]){j++;}
                count+=(j-minin2);
            }
            else{
                 while(j<(n-1) && arr[j]==arr[j+1]){j++;}
                count+=(j-i);
            }
          }
           // cout << count << endl;
        }
        cout << count << endl;
    }
}