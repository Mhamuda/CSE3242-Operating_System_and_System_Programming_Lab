// First-Come First-Serve (FCFS) Scheduling Algorithm

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    freopen("FCFSinput.txt", "r", stdin);
    ll n, i, j, k, l, burst;
    string proc;
    cin >> n;

    vector<ll> burstTime(n), waitingTime(n), turnaroundTime(n);
    vector<string> process;

    for (i = 0; i < n; i++)
    {
        cin >> proc >> burst;
        process.pb(proc);
        burstTime[i] = burst;
    }
    waitingTime[0] = 0;
    for (i = 1; i < n; i++)
        waitingTime[i] += waitingTime[i - 1] + burstTime[i - 1];

    for (i = 0; i < n; i++)
        turnaroundTime[i] = waitingTime[i] + burstTime[i];

    // Printing Gantt Chart
    cout << "\nGantt Chart:\n";

    // Prinint top bar
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[i]; j++)
            cout << "--";
        cout << " ";
    }

    // Printing process name
    cout << "\n|";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[i] - 1; j++)
            cout << " ";
        cout << process[i];
        for (j = 0; j < burstTime[i] - 1; j++)
            cout << " ";
        cout << "|";
    }

    // Printing bottom bar
    cout << "\n";
    cout << " ";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[i]; j++)
            cout << "--";
        cout << " ";
    }

    // Printing turnaround time
    cout << "\n";
    cout << "0";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < burstTime[i]; j++)
            cout << "  ";
        if (turnaroundTime[i] > 9)
            cout << "\b";
        cout << turnaroundTime[i];
    }
    cout << "\n";

    cout << "\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (i = 0; i < n; i++)
    {
        cout << process[i] << "\t\t"
             << burstTime[i] << "\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << "\n";
    }

    // Average waiting time
    double avgWaitingTime = 0;
    for (i = 0; i < n; i++)
        avgWaitingTime += waitingTime[i];
    avgWaitingTime /= n;
    cout << "Average waiting time = " << avgWaitingTime << "\n";

    // Average turnaround time
    double avgTurnaroundTime = 0;
    for (i = 0; i < n; i++)
        avgTurnaroundTime += turnaroundTime[i];
    avgTurnaroundTime /= n;
    cout << "Average turnaround time = " << avgTurnaroundTime << "\n";

    return 0;
}
