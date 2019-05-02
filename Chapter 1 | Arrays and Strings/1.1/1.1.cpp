#include <iostream>
#include <algorithm>

using namespace std;

// Time Complexity : O(1)
// We Assume time complexity is O(1) as our loop will never iterate more than 256 char
// Space Complexity : O(1)

bool vis[256];
bool IsUnique_1(string S) {
	memset(vis, 0, sizeof(vis));
	if (S.size() > 256)
		return false;

	for (auto i : S) {
		if (vis[i])
			return false;
		vis[i] = true;
	}
	return true; 
}

// this method reduce the memory, 
// instead of an array of bool we will use Just an integer
// But this will limit our ability to check the uniquely to only lowercase char^s

// Time Complexity : O(1)
// We Assume time complexity is O(1) as our loop will never iterate more than 26 char (lower)
// Space Complexity : O(1)
bool IsUnique_2(string S) {
	int Vis = 0;
	for (auto i : S) {
		int val = i - 'a';
		if (Vis & (1 << val))
			return false;

		Vis |= (1 << val);
	}
	return true;
}

// Time Complexity : O(nLog(n) + n) = O(nLog(n)) = Sorting + iteration
// Space Complexity : O(1)
bool IsUnique_3(string S) {
	sort(S.begin(), S.end());
	int Length = S.length();
	for (int i = 0; i < Length - 1; i++)
		if (S[i] == S[i + 1])
			return false;

	return true;
}

int main() {
	string S1 = "Hello, My name is Abdallah Hemdan";
	string S2 = "abcdefghijklmnopqrstuvwxyz";

	// Test IsUnique 1
	(IsUnique_1(S1)) ? cout << "Unique" << endl : cout << "Not Unique" << endl;
	(IsUnique_1(S2)) ? cout << "Unique" << endl : cout << "Not Unique" << endl;
	cout << endl;

	// Test IsUnique 2
	(IsUnique_2(S1)) ? cout << "Unique" << endl : cout << "Not Unique" << endl;
	(IsUnique_2(S2)) ? cout << "Unique" << endl : cout << "Not Unique" << endl;
	cout << endl;

	// Test IsUnique 3
	(IsUnique_3(S1)) ? cout << "Unique" << endl : cout << "Not Unique" << endl;
	(IsUnique_3(S2)) ? cout << "Unique" << endl : cout << "Not Unique" << endl;
	cout << endl;
}
