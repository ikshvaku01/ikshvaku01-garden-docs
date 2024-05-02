#include <iostream>
using namespace std;
int main() {
	long long int t,n,k,m;
	cin >> t;
	while(t-- > 0)
	{
		cin>>n>>k>>m;
		long long int total=0;
		for(long long int i=1;i<=n;i++)
		{
			total=total + (k * i*i*i);
		}
		if (total > m)
		{
			cout << total - m <<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}
	}
}