#include <iostream>
#include <cstdio>
#include <assert.h>
#include <cstring>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    while(t--) {
        long long n, k, m;
        scanf("%lld%lld%lld", &n, &k, &m);
        long long total = (n*(n + 1))/2;
        total *= total;
        total *= k;
        long long ans = (total >= m) ? total - m : 0;
        printf("%lld\n", ans);
    }
    return 0;
}

