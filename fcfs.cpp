#include <bits/stdc++.h>
using namespace std;

struct Process
{
  int pid;
  int arrival_time;
  int burst_time;
  int completion_time;
  int turn_around_time;
  int waiting_time;
};

void findCompletionTime(Process p[],)
{
}

int main()
{
  int n;
  cout << "Enter the number of processes: ";
  cin >> n;
  Process p[n];

  // Input process details
  for (int i = 0; i < n; i++)
  {
    cout << "Enter details for process " << i + 1 << ":" << endl;
    cout << "PID: ";
    cin >> p[i].pid;
    cout << "Arrival Time: ";
    cin >> p[i].arrival_time;
    cout << "Burst Time: ";
    cin >> p[i].burst_time;
  }

  // Example of accessing process details
  // cout << "Process Details:" << endl;
  // for (int i = 0; i < n; i++) {
  //     cout << "Process " << p[i].pid << ": Arrival Time = " << p[i].arrival_time << ", Burst Time = " << p[i].burst_time << endl;
  // }

  return 0;
}
