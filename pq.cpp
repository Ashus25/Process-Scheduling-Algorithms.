#include <bits/stdc++.h>
using namespace std;

struct Process
{
  int pid;
  int arrival_time;
  int burst_time;
  int priority;
  int completion_time;
  int turnaround_time;
  int waiting_time;
};

bool compareArrivalTime(Process p1, Process p2)
{
  return p1.arrival_time < p2.arrival_time; // Sort processes based on arrival time
}

bool comparePriority(Process p1, Process p2)
{
  return p1.priority < p2.priority; // Sort processes based on priority
}

void findCompletionTime(Process p[], int n)
{
  sort(p, p + n, compareArrivalTime);   // Sort processes based on arrival time
  int current_time = p[0].arrival_time; // Initialize current time to arrival time of first process

  for (int i = 0; i < n; i++)
  {
    if (current_time < p[i].arrival_time)
      current_time = p[i].arrival_time; // Update current time to process arrival time if it's greater

    p[i].completion_time = current_time + p[i].burst_time; // Calculate completion time
    current_time = p[i].completion_time;                   // Update current time
  }
}

void findTurnaroundTime(Process p[], int n)
{
  for (int i = 0; i < n; i++)
  {
    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time; // Calculate turnaround time
  }
}

void findWaitingTime(Process p[], int n)
{
  for (int i = 0; i < n; i++)
  {
    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time; // Calculate waiting time
  }
}

void findPriorityScheduling(Process p[], int n)
{
  findCompletionTime(p, n);        // Find completion time for processes
  sort(p, p + n, comparePriority); // Sort processes based on priority
  findTurnaroundTime(p, n);        // Find turnaround time for processes
  findWaitingTime(p, n);           // Find waiting time for processes
}

void printPriorityScheduling(Process p[], int n)
{
  cout << "Priority Scheduling :" << endl;
  cout << "PID\tArrival Time\tBurst Time\tPriority\t Completion Time\tTurnaround Time\t\tWaiting Time" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << p[i].pid << "\t\t" << p[i].arrival_time << "\t\t" << p[i].burst_time << "\t\t" << p[i].priority << "\t\t" << p[i].completion_time << "\t\t" << p[i].turnaround_time << "\t\t\t" << p[i].waiting_time << endl;
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
    cout << "Priority: ";
    cin >> p[i].priority;
  }

  findPriorityScheduling(p, n);
  printPriorityScheduling(p, n);

  return 0;
}
