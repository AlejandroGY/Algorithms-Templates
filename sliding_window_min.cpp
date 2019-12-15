#include <bits/stdc++.h>

int main( ) {
	int MAX = 100010;
	int a[MAX], b[MAX];

	std::deque<std::pair<int, int>> D;

	int n, k;
	std::scanf("%d%d", &n, &k);

	for (int i = 0; i < n; ++i) {
		std::scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		while (!D.empty( ) && D.back( ).first >= a[i]) {
			D.pop_back( );
		}
		D.push_back({ a[i], i });
		while (D.front( ).second <= i - k) {
			D.pop_front( );
		}
		b[i] = D.front( ).first;
	}
	for (int i = 0; i < n; ++i) {
		std::printf("%d ", b[i]);
	}
}