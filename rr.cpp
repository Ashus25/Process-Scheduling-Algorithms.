#include <bits/stdc++.h>
using namespace std;

struct Process
{
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int completion_time;
  int turnaround_time;
  int waiting_time;
};

bool compareArrivalTime(Process p1, Process p2)
{
  return p1.arrival_time < p2.arrival_time; // Sort processes based on arrival time
}

void findCompletionTime(Process p[], int n, int time_quantum)
{
  sort(p, p + n, compareArrivalTime); // Sort processes based on arrival time
  queue<Process> ready_queue;
  int current_time = p[0].arrival_time; // Initialize current time to arrival time of first process
  int remaining_processes = n;
  int index = 0;

  while (remaining_processes > 0)
  {
    while (index < n && p[index].arrival_time <= current_time)
    {
      ready_queue.push(p[index]);
      index++;
    }

    if (ready_queue.empty())
    {
      current_time = p[index].arrival_time;
      continue;
    }

    Process current_process = ready_queue.front();
    ready_queue.pop();

    int quantum = min(time_quantum, current_process.remaining_time);
    current_time += quantum;
    current_process.remaining_time -= quantum;

    if (current_process.remaining_time <= 0)
    {
      current_process.completion_time = current_time;
      current_process.turnaround_time = current_process.completion_time - current_process.arrival_time;
      current_process.waiting_time = current_process.turnaround_time - current_process.burst_time;
      remaining_processes--;
    }
    else
    {
      while (index < n && p[index].arrival_time <= current_time)
      {
        ready_queue.push(p[index]);
        index++;
      }
      ready_queue.push(current_process);
    }
  }
}

void printRoundRobin(Process p[], int n)
{
  cout << "Round Robin Scheduling :" << endl;
  cout << "PID\tArrival Time\tBurst Time\t Completion Time\tTurnaround Time\t\tWaiting Time" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << p[i].pid << "\t\t" << p[i].arrival_time << "\t\t" << p[i].burst_time << "\t\t" << p[i].completion_time << "\t\t" << p[i].turnaround_time << "\t\t\t" << p[i].waiting_time << endl;
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
    p[i].remaining_time = p[i].burst_time;
  }

  int num_quantum;
  cout << "Enter the number of different time quantum values: ";
  cin >> num_quantum;
  int time_quantum[num_quantum];
  cout << "Enter the time quantum values: ";
  for (int i = 0; i < num_quantum; ++i)
  {
    cin >> time_quantum[i];
  }

  for (int i = 0; i < num_quantum; ++i)
  {
    cout << "\nUsing Time Quantum: " << time_quantum[i] << endl;
    findCompletionTime(p, n, time_quantum[i]);
    printRoundRobin(p, n);
  }

  return 0;
}
