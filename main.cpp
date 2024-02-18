#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
    int n;
    cin>>n;

    int a[n];
    int p=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=p)
        {
            int x=p/a[i]+1;
            a[i]=x*a[i];
        }
        p=a[i];
    }

   cout<<a[n-1]<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}