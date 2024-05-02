#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    scanf("%d",&t);
    assert(t>=1 && t<=100000);
    while(t--)
    {
    	ll N,K,M;
    	scanf("%lld %lld %lld",&N,&K,&M);
    	assert(N>=1 && N<=1000);
    	assert(K>=1 && K<=1000);
    	assert(M>=1 && M<=1000000);
    	
    	ll beer_cost = (N*(N+1))/2;
    	beer_cost = beer_cost*beer_cost;
    	beer_cost = beer_cost*K;
    	ll lent_money = beer_cost-M;
    	if(lent_money<0)
    		lent_money = 0;
    	printf("%lld\n", lent_money);
    }
    return 0;
}