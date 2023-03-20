#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    freopen("BestFitInput.txt", "r", stdin);
    ll i, p, pN, bN;
    vector<ll> process, blockNo, blockSize;
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
        blockSize.push_back(p);
    }

    for (i = 0; i < pN; i++)
    {
        sort(block.begin(), block.end());
        sort(blockSize.begin(), blockSize.end());
        auto index = lower_bound(blockSize.begin(), blockSize.end(), process[i]);

        if (index == blockSize.end())
            blockNo.push_back(-1);
        else
        {
            ll j = index - blockSize.begin();
            blockNo.push_back(block[j].second);
            block[j].first -= process[i];
            blockSize[j] -= process[i];
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