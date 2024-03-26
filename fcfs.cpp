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

void findCompletionTime(Process p[], int n)
{
  p[0].completion_time = p[0].burst_time;
  for (int i = 1; i < n; i++)
  {
    p[i].completion_time = p[i - 1].completion_time + p[i].burst_time;
  }
}

void findTurnAroundTime(Process p[], int n)
{
  for (int i = 0; i < n; i++)
  {
    p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
  }
}

void findWaitingTime(Process p[], int n)
{
  p[0].waiting_time = 0;
  for (int i = 1; i < n; i++)
  {
    p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
  }
}

void findFCFS(Process p[], int n)
{
  findCompletionTime(p, n);
  findTurnAroundTime(p, n);
  findWaitingTime(p, n);
}

void printFCFS(Process p[], int n)
{
  cout << "FCFS Scheduling :" << endl;
  cout << "PID\tArrival Time\tBurst Time\t Completion Time\tTurnaround Time\t\tWaiting Time" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << p[i].pid << "\t\t" << p[i].arrival_time << "\t\t" << p[i].burst_time << "\t\t" << p[i].completion_time << "\t\t" << p[i].turn_around_time << "\t\t\t" << p[i].waiting_time << endl;
  }
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
  findFCFS(p, n);
  printFCFS(p, n);

  return 0;
}
