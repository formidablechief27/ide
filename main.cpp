//  ?
// Author : Ansari Mohd Abuzaid

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define uld unsigned long double
#define nl cout << endl;
#define all(a) a.begin(), a.end()
// vector queues shorcuts
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vb vector<bool>
#define vchr vector<char>
#define vstr vector<string>
#define pusb push_back
#define popb pop_back
#define pusf push_front
#define popf pop_front
// LOOPS
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define flr(i, a, b) for (ll i = a; i > b; i--)
#define fle(i, a, b) for (ll i = a; i <= b; i++)
#define flre(i, a, b) for (ll i = a; i >= b; i--)
#define fauto(cont, ele) for (auto ele : cont)
// Array Input and Output
#define inparr(a, n) fl(i, 0, n) cin >> a[i];
#define outarr(a, n)                      \
     fl(i, 0, n) { cout << a[i] << " "; } \
     nl;
#define inp2arr(a, n, m)                  \
     fl(i, 0, n)                          \
     {                                    \
          fl(j, 0, m) { cin >> a[i][j]; } \
     }
#define out2arr(a, n, m)                          \
     fl(i, 0, n)                                  \
     {                                            \
          fl(j, 0, m) { cout << a[i][j] << " "; } \
          nl;                                     \
     }
#define copyarr(a, b, n) \
     fl(i, 0, n) { b[i] = a[i]; }
// single double input output
#define pf(a) cout << a << endl;
#define pf2(a, b) cout << a << " " << b << endl;
#define inp(a) cin >> a;
#define inp2(a, b) cin >> a >> b;
#define ret return;

#define NO cout << "NO" << endl;
#define YES cout << "YES" << endl;
#define str string
#define mod 1000000007
// #define pi 3.1415926535897932384626
const long double pi = acos(-1);
// #define pi 3.141075920803576

// debugging
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
     cerr << ' ' << H;
     dbg_out(T...);
}
#define deb(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// SOME USEFUL FUNCTIONS
// returns a map which contains frequency of elements
map<ll, ll> freqmap(vll a, ll n)
{
     map<ll, ll> freq;
     fl(i, 0, n)
     {
          freq[a[i]]++;
     }
     return freq;
}
map<char, ll> freqmapstr(str a, ll n)
{
     map<char, ll> freq;
     fl(i, 0, n)
     {
          if (freq.find(a[i]) == freq.end())
               freq[a[i]] = 1;
          else
               freq[a[i]]++;
     }
     return freq;
}

int largestPower(int n, int p)
{
     int x = 0;
     // Calculate x = n/p + n/(p^2) + n/(p^3) + ....
     while (n)
     {
          n /= p;
          x += n;
     }
     return x;
}

// returns the frequency of a particular character from the string
ll freqchar(str a, ll n, char x)
{
     ll count = 0;
     fl(i, 0, n)
     {
          if (a[i] == x)
          {
               count++;
          }
     }
     return count;
}

ll SumOfDigitsNum(int x)
{
     ll n = 0;
     while (x != 0)
     {
          n = n + x % 10;
          x = x / 10;
     }
     return n;
}
ll SumOfDigitsStr(string x)
{
     ll n = 0;
     fl(i, 0, x.length()) { n = n + x[i] - 48; }
     return n;
}
// sum of elements of array
ll sumarr(vll a, ll n)
{
     ll mp22 = 0;
     fl(i, 0, n) { mp22 = mp22 + a[i]; }
     return mp22;
}

// Euclidean Algorithm : gcd(a,b)=gcd(a-b,b) here a>b
ll gcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;    
}

ll lcm(int a, int b)
{ 
// The product of the GCD and the LCM is equal to the product of A and B
     return (a/gcd(a,b))*b;
}

bool prime(ll num)
{
     if (num <= 1)
          return false;
     if (num <= 3)
          return true;
     fle(i, 2, sqrt(num))
     {
          if (num % i == 0)
          {
               return false;
          }
     }
     return true;
}

// sieveofEratosthenes for prime from 1 to n;
void SieveOfEratosthenes(vb &prime, int n)
{
     for (int p = 2; p * p <= n; p++)
     {
          if (prime[p] == true)
          {
               for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
          }
     }
}

bool isPerfectSquare(long double x)
{
     if (x >= 0)
     {
          long long sr = sqrt(x);
          return (sr * sr == x);
     }
     return false;
}

// below are the modular arithmetic functions
long add(long a, long b)
{
     return (((long)(a + mod) % mod + (b + mod) % mod) % mod);
}
long sub(long a, long b)
{
     return (((long)(a + mod) % mod + ((-1 * b) + mod) % mod) % mod);
}
ll mul(ll a, ll b)
{
     return (((ll)a % mod * b % mod) % mod);
}
long inv(long x)
{
     return pow(x, mod - 2);
}
// long div(long x, long y)
// {
//      return mul(x, inv(y));
// }
// Utility function to do modular exponentiation.
// It returns (x^y) % p
// binpoww function
ll poww(ll a, ll b)
{
     a %= mod;
     ll res = 1;
     while (b > 0)
     {
          if ((b & 1) != 0)
               res = mul(res, a);
          a = mul(a, a);
          b /= 2;
     }
     return res;
}

// abs() works as defined for all input integers, except for one integer: the INT_MIN. For 32-bit integers, the value of INT_MIN is -2147483648. abs( INT_MIN ) returns INT_MIN back!
// so this can be used for safer operations
// https://codeyarns.com/tech/2012-02-14-c-abs-and-its-quirk-with-int_min.html#gsc.tab=0
unsigned int absu(int value)
{
     return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
}

// functions used to sort 2-d array acc to  the particular column
bool sortcol0(const vector<ll> &v1, const vector<ll> &v2)
{
     return v1[0] < v2[0];
}
bool sortcol1(const vector<ll> &v1, const vector<ll> &v2)
{
     return v1[1] > v2[1];
}
// Ascii lowercase - 97-122
// uppercase - 65-90

// problem solving function
void testcase()
{
     ll n;
     inp(n);
     n*=2;
     vll a(n);
     inparr(a,n);
     sort(all(a),greater<ll>());
     ll ans=0;
     fl(i,0,n){
          if(i%2==0){continue;}
         ans+=a[i];
     //     i++; 
     }
     pf(ans);
}

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     int n;
     cin >> n;
     int t1, t2, t3, t4;
     str s;
     for (int i = 1; i <= n; i++)
     {
          // if (i == 554)
          // {
          //     inp(s);
          //     // inp2(t3,t4)
          //     deb(s);
          //     int arr[1];
          //     pf(arr[10000000]);
          // }
          testcase();
     }
     return 0;
}

