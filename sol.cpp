#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n;
		cin >> n;
		auto Power = [&](long long a, long long b) {
			long long res = 1;
			while (b > 0) {
				if (b & 1) {
					res *= a;
				}
				a *= a;
				b /= 2;
			}
			return res;
		};
		long long ans = 0;
		for (int i = 0; Power(2, i) < n; i++) {
			// find the largest number that is a power of two before 'n'
			ans = Power(2, i);
		}
		long long power_of_two = 0;
		for (int i = 0; Power(2, i) <= n; i++) {
			// find the maximum number that is a power of two from 1 to 'n'
			power_of_two = Power(2, i);
		}
		// if the maximum number that is a power of two is equal to 'n', then
		// the answer is simply 'n' - 1 (because the AND operation between a
		// power of two and its precedent number is always equal to 1),
		// however, if the 'n' is not a power of two, we will use the largest
		// number that is power of two before 'n', and subtract 1 from it
		// which will result to the maximum number that would give 'n'
		// a result of 1 using binary AND (&) operation
		cout << (power_of_two == n ? n - 1 : ans - 1) << '\n';
	}
	return 0;
}
