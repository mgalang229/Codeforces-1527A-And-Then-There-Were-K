#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int last = 0;
		for (int i = 0; i < 30; i++) {
			cout << (n >> i) << " ";
			// we need to find the highest power of 2 that is smaller or
			// equal to 'n' itself by dividing 'n' with the powers of 2
			// and when 'n' becomes 1, then we need to store the 'i'-th index
			// (this will be the exponent of the maximum power of 2 before 'n'
			// or 'n' itself)
			if (((n >> i) & 1) == 1) {
				last = i;
			}
		}
		// the answer would the maximum power of 2 before 'n' or 'n' itself
		// minus one (because this would result to 0 in binary AND operation)
		cout << (1 << last) - 1 << '\n';
	}
	return 0;
}
