#include <bits/stdc++.h>
#include <algorithm>
#include <cstdint>

using namespace std;
#define debug 0
#define ll long long
void take(long long int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void take(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int main() {
    int cases ;
    cin >> cases;
    while(cases--){
        ll n;
        cin >> n;
        int arr[n];
        take(arr,n);
        string str;
        cin >> str;
        map <int,int> m;
        for(int i=0;i<n;i++){
            m[i+1]=arr[i];
        } 
        int count[n];
        for(int i=0;i<n;i++){count[i]=-1;}
        for(int i=0;i<n;i++){
            int count1=0;
            if(count[arr[i]-1]!=-1){continue;}
            vector <int> vec;
            vec.push_back(arr[i]);
            int des=(arr[i]);
            if(str[i]=='0'){count1++;}
            int c=m[des];
            while(c!=des){
                if(str[c-1]=='0'){count1++;}
                vec.push_back(c);
                c=m[c];
            }
            for(int j=0;j<vec.size();j++){
                cout << vec[i] << "a" ;
                count[vec[i]]=count1;
            }
        }
        for(int i=0;i<n;i++){
            cout << count[i] << " ";

        }
        cout << endl;
     }
    
    }
    

 