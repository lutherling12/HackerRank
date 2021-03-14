#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n)
{
    const auto length = s.size();
    vector<bool> hasA(length);

    for(auto c = 0; length > c; ++c) {
        // record positions where A is present
        hasA[c] = ('a' == s[c]) ? 1 : 0;
    }

    // find the number of As in repeated string using modulo arithmetic
    const auto results = ldiv(n, length);
    const long repeats = results.quot;
    const long partial = results.rem;

    long numberOfAs = 0;
    for(auto pos = 0; length > pos; ++pos) {
        numberOfAs += hasA[pos] * repeats;
        numberOfAs += hasA[pos] * ((partial > pos) ? 1 : 0);
    }

    return numberOfAs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
