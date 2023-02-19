// Round Robin Scheduling Algorithm

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    freopen("RoundRobinInput.txt", "r", stdin);

    ll n, i, j, k, l, burst, arrival, quantum;
    string proc;
    cin >> n >> quantum;

    vector<ll> waitingTime(n), turnaroundTime(n), BT(n), burstTime(n);
    vector<string> process;

    for (i = 0; i < n; i++)
    {
        cin >> proc >> burst;
        process.pb(proc);
        BT[i] = burst;
    }

    burstTime = BT;

    vector<string> Prc;
    vector<ll> BT1;
    ll time = 0;
    map<string, ll> prevBT;
    BT1.pb(0);

    while (1)
    {
        bool done = true;
        for (i = 0; i < n; i++)
        {
            if (burstTime[i] > 0)
            {
                done = false;
                if (burstTime[i] > quantum)
                {
                    waitingTime[i] += time - prevBT[process[i]];
                    time += quantum;
                    burstTime[i] -= quantum;
                    Prc.pb(process[i]);
                    prevBT[process[i]] = time;
                    BT1.pb(time);
                }
                else
                {
                    waitingTime[i] += time - prevBT[process[i]];
                    time += burstTime[i];
                    burstTime[i] = 0;
                    Prc.pb(process[i]);
                    prevBT[process[i]] = time;
                    BT1.pb(time);
                }
            }
        }
        if (done == true)
            break;
    }

    for (i = 0; i < n; i++)
        turnaroundTime[i] = waitingTime[i] + BT[i];

    // Printing Gantt Chart
    cout << "\nGantt Chart:\n";

    // Prinint top bar
    cout << " ";
    for (i = 0; i < Prc.size(); i++)
    {
        for (j = 0; j < BT1[i + 1] - BT1[i]; j++)
            cout << "--";
        cout << " ";
    }

    // Printing process name
    cout << "\n|";
    for (i = 0; i < Prc.size(); i++)
    {
        for (j = 0; j < (BT1[i + 1] - BT1[i]) - 1; j++)
            cout << " ";
        cout << Prc[i];
        for (j = 0; j < (BT1[i + 1] - BT1[i]) - 1; j++)
            cout << " ";
        cout << "|";
    }

    // Printing bottom bar
    cout << "\n";
    cout << " ";
    for (i = 0; i < Prc.size(); i++)
    {
        for (j = 0; j < BT1[i + 1] - BT1[i]; j++)
            cout << "--";
        cout << " ";
    }

    // Printing turnaround time
    cout << "\n";
    cout << 0;

    for (i = 0; i < Prc.size(); i++)
    {
        for (j = 0; j < BT1[i + 1] - BT1[i]; j++)
            cout << "  ";

        if (BT1[i + 1] > 9)
            cout << "\b";

        cout << BT1[i + 1];
    }

    cout << "\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++)
        cout << process[i] << "\t\t" << BT[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";

    // Printing average waiting time
    ll sum = 0;
    for (i = 0; i < n; i++)
        sum += waitingTime[i];
    cout << "\nAverage Waiting Time = " << (double)sum / n << endl;

    // Printing average turnaround time
    sum = 0;
    for (i = 0; i < n; i++)
        sum += turnaroundTime[i];
    cout << "Average Turnaround Time = " << (double)sum / n << endl;

    return 0;
}