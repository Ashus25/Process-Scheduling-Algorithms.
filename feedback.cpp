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

void findCompletionTime(Process p[], int n, int num_queues, int *time_quantum)
{
  sort(p, p + n, compareArrivalTime); // Sort processes based on arrival time
  queue<Process> ready_queue[num_queues];
  int current_time = 0; // Initialize current time to 0
  int index = 0;

  while (true)
  {
    bool all_processes_done = true;

    // Fill the ready queues with processes based on arrival time
    while (index < n && p[index].arrival_time <= current_time)
    {
      ready_queue[0].push(p[index++]);
    }

    // Execute processes in each queue according to their time quantum
    for (int i = 0; i < num_queues; ++i)
    {
      while (!ready_queue[i].empty())
      {
        Process current_process = ready_queue[i].front();
        ready_queue[i].pop();

        int execution_time = min(current_process.remaining_time, time_quantum[i]);
        current_time += execution_time;
        current_process.remaining_time -= execution_time;

        if (current_process.remaining_time <= 0)
        {
          current_process.completion_time = current_time;
          current_process.turnaround_time = current_process.completion_time - current_process.arrival_time;
          current_process.waiting_time = current_process.turnaround_time - current_process.burst_time;
        }
        else
        {
          ready_queue[min(i + 1, num_queues - 1)].push(current_process);
        }
      }
    }

    // Check if all processes are done
    for (int i = 0; i < n; ++i)
    {
      if (p[i].remaining_time > 0)
      {
        all_processes_done = false;
        break;
      }
    }

    if (all_processes_done)
      break;
  }
}

void printFeedbackScheduling(Process p[], int n)
{
  cout << "Feedback Scheduling :" << endl;
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

  int num_queues;
  cout << "Enter the number of feedback queues: ";
  cin >> num_queues;
  int time_quantum[num_queues];
  cout << "Enter the time quantum for each queue: ";
  for (int i = 0; i < num_queues; ++i)
  {
    cin >> time_quantum[i];
  }

  findCompletionTime(p, n, num_queues, time_quantum);
  printFeedbackScheduling(p, n);

  return 0;
}
