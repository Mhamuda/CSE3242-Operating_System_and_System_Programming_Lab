#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    freopen("WorstFitInput.txt", "r", stdin);
    ll i, p, pN, bN;
    vector<ll> process, blockNo;
    vector<pair<ll, ll>> block;

    cin >> pN;
    for (i = 0; i < pN; i++)
    {
        cin >> p;
        process.push_back(p);
    }

    cin >> bN;
    for (i = 1; i <= bN; i++)
    {
        cin >> p;
        block.push_back({p, i});
    }

    for (i = 0; i < pN; i++)
    {
        sort(block.begin(), block.end(), greater<pair<ll, ll>>());

        if (block[0].first < process[i])
            blockNo.push_back(-1);
        else
        {
            blockNo.push_back(block[0].second);
            block[0].first -= process[i];
        }
    }

    cout << "Process No"
         << "\tProcess size"
         << "\tBlock No"
         << "\n";

    for (i = 0; i < pN; i++)
    {
        cout << "  " << i + 1 << "    "
             << "\t\t" << process[i] << "\t\t";

        (blockNo[i] == -1) ? cout << "Not Allocated" : cout << blockNo[i];
        cout << "\n";
    }

    return 0;
}