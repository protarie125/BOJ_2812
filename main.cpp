#include <iostream>
#include <deque>
#include <string>

using namespace std;

using dqc = deque<char>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k; cin >> n >> k;
	string s; cin >> s;

	auto q = dqc{};
	auto dc = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		if (q.empty()) {
			q.push_back(s[i]);
			continue;
		}

		if (k == dc) {
			q.push_back(s[i]);
			continue;
		}

		while (!q.empty() && dc < k) {
			auto t = q.back();
			if (t < s[i]) {
				++dc;
				q.pop_back();
			}
			else {
				break;
			}
		}

		q.push_back(s[i]);
	}

	auto ct = int{ 0 };
	while (!q.empty() && ct < n - k) {
		cout << q.front();
		q.pop_front();
		++ct;
	}

	return 0;
}