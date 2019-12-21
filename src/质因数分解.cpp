
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int primes[501], idx;
int vis[10001];

void generatePrimes(int x) {
	for(int i=2; i<=x; i++) {
		if(!vis[i]) { // isPrime
			primes[++idx] = i; // record the prime
			for(int k=2*i; k<=x; k+=i)
				vis[i] = 1; // not a prime
		}
	}
}

int main()
{
	int n; scanf("%d", &n);
	generatePrimes(n);
	bool firstOutput = true;
	printf("%d=", n);
	for(int i=1; i<=idx; i++) {
		while(n % primes[i] == 0) {
			if(!firstOutput) printf("*");
			printf("%d", primes[i]);
			firstOutput = false;
			n /= primes[i];
		}
	}
	return 0;
}
