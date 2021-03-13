#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c)
{
    // track current player's position
    auto playerPos = c.begin();
    const auto goalPost = c.end() - 1;

    int jumps = 0;
    while(goalPost > playerPos) {
        // we don't want the player to fall off the map
        const bool isOutOfBounds =
            playerPos + 2 >= c.end();
        // check if next next cloud is thunder cloud
        const bool isSafeToLongJump =
            !isOutOfBounds && (0 == *(playerPos + 2));

        // if long jump(or position + 2) is safe
        if(isSafeToLongJump) {
            playerPos += 2;
            ++jumps;
        }
        // otherwise, take short jump(or position + 1);
        else {
            ++playerPos;
            ++jumps;
        }
    }

    return jumps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
