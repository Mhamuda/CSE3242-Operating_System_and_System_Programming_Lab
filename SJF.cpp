// Shortest Job First(SJF) Scheduling Algorithm: (Non-Preemptive)

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    freopen("SJFinput.txt", "r", stdin);

    ll n, i, j, k, l, burst;
    string proc;
    cin >> n;

    vector<ll> waitingTime(n), turnaroundTime(n), BT(n);
    vector<string> process;
    vector<pair<ll, ll>> burstTime;

    for (i = 0; i < n; i++)
    {
        cin >> proc >> burst;
        process.pb(proc);
        burstTime.pb({burst, i});
        BT[i] = burst;
    }

    sort(burstTime.begin(), burstTime.end());

    waitingTime[burstTime[0].second] = 0;

    for (i = 1; i < n; i++)
        waitingTime[burstTime[i].second] += waitingTime[burstTime[i - 1].second] + burstTime[i - 1].first;

    for (i = 0; i < n; i++)
        turnaroundTime[i] = waitingTime[i] + BT[i];

    // Printing Gantt Chart
    cout << "\nGantt Chart:\n";

    // Prinint top bar
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[i].first; j++)
            cout << "--";
        cout << " ";
    }

    // Printing process name
    cout << "\n|";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[i].first - 1; j++)
            cout << " ";
        cout << process[i];
        for (j = 0; j < burstTime[i].first - 1; j++)
            cout << " ";
        cout << "|";
    }

    // Printing bottom bar
    cout << "\n";
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[i].first; j++)
            cout << "--";
        cout << " ";
    }

    // Printing turnaround time
    cout << "\n";
    cout << "0";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[i].first; j++)
            cout << "  ";
        if (turnaroundTime[i] > 9)
            cout << "\b";
        cout << turnaroundTime[burstTime[i].second];
    }
    cout << "\n";

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++)
    {
        cout << process[i] << "\t\t"
             << BT[i] << "\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << "\n";
    }

    // Average waiting time
    double avgWaitingTime = 0;
    for (i = 0; i < n; i++)
        avgWaitingTime += waitingTime[i];
    avgWaitingTime /= n;
    cout << "\nAverage Waiting Time: " << avgWaitingTime << "\n";
   
    // Average turnaround time
    double avgTurnaroundTime = 0;
    for (i = 0; i < n; i++)
        avgTurnaroundTime += turnaroundTime[i];
    avgTurnaroundTime /= n;

        cout << "Average Turnaround Time: " << avgTurnaroundTime << "\n";

    return 0;
}
