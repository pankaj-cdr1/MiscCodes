#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>

#include <functional>
#include <limits>
#include <numeric>
#include <complex>

#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())
const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);
char *Y;
int n;
int isprime(int num)
{
    if(num<=1) return 0;
    for(int i = 2; i< num; i++)
            if(num%i==0) return 0;
    return 1;
}
li dp[2][20][100][100];
li func(int turn, int idx, int even, int odd)
{
    if(idx == 0) return isprime(even - odd) == 1; 
    if(dp[turn][idx][even][odd] != -1) return dp[turn][idx][even][odd];
    li ans = 0;
    for(int i = 0; i < 10; i++) {
            if(turn)
            ans += func(1-turn, idx - 1, even, odd + i);
            else 
            ans += func(1-turn, idx - 1, even + i, odd);
    }
    return dp[turn][idx][even][odd] = ans;
}
li solve(int inc){
	li ret = 0;
	int len = strlen(Y);
	int sum[2] = {0};
	int turn = len&1;
	for(int i = 0; i < len; i++){
		int d = Y[i] - '0';
		for(int j = 0; j < d; j++){
                if(turn)
				ret += func(1-turn, len - 1 - i, sum[0], sum[1] + j);
				else 
				ret += func(1-turn, len - 1 - i, sum[0] + j, sum[1]);
		}
		sum[turn] += d;
		turn = 1 - turn;
	}
	if(inc && isprime(sum[0]-sum[1]) == 1) ret = (ret + 1);
	return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    mset(dp, -1);
    char a[15],b[15];
    while(t--){
               scanf("%s %s",a,b);
               Y = b;
               li ans = solve(1);
               Y = a;
               ans -= solve(0);
               printf("%lld\n",ans);
    }
    return 0;
}
