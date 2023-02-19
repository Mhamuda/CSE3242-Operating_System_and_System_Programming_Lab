// Priority Scheduling with Round Robin Algorithm

#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    freopen("PrioritySchedulingWithRoundRobinInput.txt", "r", stdin);
    ll n, i, j, k, l, burst, priority, quantum, maxPriority;
    string proc;
    cin >> n >> quantum;

    vector<ll> waitingTime(n), turnaroundTime(n), burstTime(n), BT(n), TAT(n), Priority(n);
    vector<string> process;
    vector<pair<ll, ll>> priorityTime;
    map<string, ll> pBT;
    map<ll, ll> priorityMap;

    for (i = 0; i < n; i++)
    {
        cin >> proc >> burst >> priority;
        process.pb(proc);
        burstTime[i] = burst;
        Priority[i] = priority;
        maxPriority = max(maxPriority, priority);
        priorityMap[priority]++;
        priorityTime.pb({priority, i});
        pBT[proc] = burst;
    }

    BT = burstTime;
    sort(priorityTime.begin(), priorityTime.end());
    map<string, ll> prevBT;
    vector<string> Prc;
    vector<ll> TATime;
    ll time = 0;
    ll p = 1;

    while (1)
    {
        bool done = false;

        for (i = 0; i < n;)
        {
            if (priorityMap[priorityTime[i].first] == 1)
            {
                waitingTime[priorityTime[i].second] += time - prevBT[process[priorityTime[i].second]];
                Prc.pb(process[priorityTime[i].second]);
                time += burstTime[priorityTime[i].second];
                TATime.pb(time);
                prevBT[process[priorityTime[i].second]] = time;
                p++;
                i++;
            }
            else
            {
                queue<string> q;
                map<string, ll> temp;

                while (priorityTime[i].first == p)
                {
                    q.push(process[priorityTime[i].second]);
                    temp[process[priorityTime[i].second]] = priorityTime[i].second;
                    i++;
                }
                p++;

                // cerr<<"--ok--\n";
                // for(auto x = temp.begin(); x != temp.end(); x++)
                // {
                //    cerr<<x->first<<" "<<x->second<<"\n";
                // }
                // cerr<<"\n--ok--\n";

                while (!q.empty())
                {
                    string s = q.front();
                    q.pop();

                    if (pBT[s] > quantum && !q.empty())
                    {
                        waitingTime[temp[s]] += time - prevBT[s];
                        time += quantum;
                        pBT[s] -= quantum;
                        Prc.pb(s);
                        TATime.pb(time);
                        prevBT[s] = time;
                        q.push(s);
                    }
                    else
                    {
                        waitingTime[temp[s]] += time - prevBT[s];
                        time += pBT[s];
                        pBT[s] = 0;
                        Prc.pb(s);
                        TATime.pb(time);
                        prevBT[s] = time;
                    }
                }
            }

            if (i == n)
            {
                done = true;
                break;
            }
        }

        if (done)
            break;
    }

    for (i = 0; i < n; i++)
        turnaroundTime[priorityTime[i].second] = waitingTime[priorityTime[i].second] + burstTime[priorityTime[i].second];

    // Gantt Chart

    cout << "Gantt Chart\n";

    // Printing top bar
    cout << " ";

    for (i = 0; i < Prc.size(); i++)
    {
        if (i == 0)
        {
            for (j = 0; j < TATime[i]; j++)
                cout << "--";
            cout << " ";
        }
        else
        {
            for (j = 0; j < TATime[i] - TATime[i - 1] + 1; j++)
                cout << "--";
            cout << " ";
        }
    }

    // Printing process names in the middle
    cout << "\n|";

    for (i = 0; i < Prc.size(); i++)
    {
        if (i == 0)
        {
            for (j = 0; j < TATime[i] - 1; j++)
                cout << " ";
            cout << Prc[i];
            for (j = 0; j < TATime[i] - 1; j++)
                cout << " ";
            cout << "|";
        }
        else
        {
            for (j = 0; j < (TATime[i] - TATime[i - 1]); j++)
                cout << " ";
            cout << Prc[i];
            for (j = 0; j < (TATime[i] - TATime[i - 1]); j++)
                cout << " ";
            cout << "|";
        }
    }

    // Printing bottom bar
    cout << "\n ";

    for (i = 0; i < Prc.size(); i++)
    {
        if (i == 0)
        {
            for (j = 0; j < TATime[i]; j++)
                cout << "--";
            cout << " ";
        }
        else
        {
            for (j = 0; j < TATime[i] - TATime[i - 1] + 1; j++)
                cout << "--";
            cout << " ";
        }
    }

    // Printing the time line
    cout << "\n";

    cout << "0";
    for (i = 0; i < Prc.size(); i++)
    {
        if (i == 0)
        {
            for (j = 0; j < TATime[i]; j++)
                cout << "  ";
        }
        else
        {
            for (j = 0; j < TATime[i] - TATime[i - 1] + 1; j++)
                cout << "  ";
        }

        if (TATime[i] > 9)
            cout << "\b"; // backspace : remove 1 space

        cout << TATime[i];
    }

    cout << "\n\nProcess\t\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";

    for (i = 0; i < n; i++)
    {
        cout << process[i] << "\t\t"
             << BT[i] << "\t\t"
             << Priority[i] << "\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << "\n";
    }
    cout << "\n";

    // Average waiting time
    float avgWaitingTime = 0;
    for (i = 0; i < n; i++)
        avgWaitingTime += waitingTime[i];
    avgWaitingTime /= n;
    cout << "Average Waiting Time: " << avgWaitingTime << "\n";

    // Average turnaround time
    float avgTurnaroundTime = 0;
    for (i = 0; i < n; i++)
        avgTurnaroundTime += turnaroundTime[i];
    avgTurnaroundTime /= n;

    cout << "Average Turnaround Time: " << avgTurnaroundTime << "\n";

    return 0;
}