// By Formidable Chief
#include<bits/stdc++.h>
#define long long long
#define ll long
#define endl "\n"
#define contains count
#define inf (long)9e18
using namespace std;

int ini() {int i; cin >> i; return i;}
long in()  {long l; cin >> l; return l;}
vector<long> in(int n){vector<long> arr(n);for(int i=0;i<n;i++) arr[i] = in();return arr;}

/*
	* Remember the pain
	* Remember the promises they broke
	* Remember how worthless they made you feel
	* Turn that pain into anger
	* And show them who you really are
*/

void solve() {
	int n = ini();
	vector<pair<long, long>> arr(n);
	for(int i=0;i<n;i++) {
		arr[i].first = in();
		arr[i].second = in();
	}
	sort(arr.begin(), arr.end());
	vector<vector<pair<long, long>>> dp(n);
	dp[0].push_back({arr[0].second, arr[0].first});
	for(int i=1;i<n;i++) {
		vector<pair<long, long>> last_dp = dp[i-1];
		long min_cost = inf;
		for(pair<long, long> p : last_dp) {
			min_cost = min(min_cost, p.first);
			dp[i].push_back({p.first + arr[i].first - p.second, p.second});
		}
		dp[i].push_back({min_cost + arr[i].second, arr[i].first});
	}
	long ans = inf;
	for(pair<long, long> p : dp[n-1]) ans = min(ans, p.first);
	cout << ans << endl;
}

int main () {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t = 1;
	//t = ini();
	for(int i=0; i<t; i++) solve();
}
