#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    freopen("FirstFitInput.txt", "r", stdin);
    ll i, j, p, pN, bN;
    bool flag = true;
    vector<ll> process, blockNo, blockSize;

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
        blockSize.push_back(p);
    }

    for (i = 0; i < pN; i++)
    {
        flag = true;
        for (j = 0; j < bN; j++)
        {
            if (blockSize[j] >= process[i])
            {
                flag = false;
                blockNo.push_back(j + 1);
                blockSize[j] -= process[i];
                break;
            }
        }

        if (flag)
            blockNo.push_back(-1);
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