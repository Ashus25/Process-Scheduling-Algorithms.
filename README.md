# Process-Scheduling-Algorithms.
Basics of how process works in an Operating System.


In an operating system, CPU scheduling algorithms determine the order in which processes are executed on the CPU. Here, we’ll explore several common scheduling algorithms:

1. First-Come-First-Serve (FCFS)
   Description: FCFS is the simplest scheduling algorithm. It processes the jobs in the order they arrive.
   Working:
   * Processes are placed in a FIFO (First-In-First-Out) queue.
   * The process that arrives first gets executed first.
   * Non-preemptive: Once a process starts executing, it cannot be interrupted.
   Advantages:
   *  Easy to implement.
   *  item 2 No starvation.
   Disadvantages:
   * Long average waiting time.
   * Convoy effect (inefficient resource utilization).
2. Shortest Job First (SJF)
   Description: SJF schedules processes based on their burst time (execution time).
   Working:
   * Processes are sorted by burst time.
   * The process with the shortest burst time is executed first.
   * Non-preemptive (unless using Shortest Remaining Time First - SRTF).
   Advantages:
   * Minimizes average waiting time.
   * Efficient for short processes.
   Disadvantages:
   * Long processes may starve.
   * Requires knowledge of burst times.
3. Round Robin (RR)
   Description: RR allocates CPU time in fixed time slices (quantum).
   Working:
   * Processes are placed in a circular queue.
   * Each process gets a fixed time slice (quantum) to execute.
   * Preemptive: Processes are interrupted after their quantum.
   Advantages:
   * Fairness (equal time for all processes).
   * Suitable for time-sharing systems.
   Disadvantages:
   * High context switching overhead.
   * Inefficient for long processes.
4. Priority Scheduling
   Description: Priority scheduling assigns priorities to processes.
   Working:
   * Each process has a priority (e.g., based on burst time, importance, etc.).
   * Highest-priority process executes first.
   * Non-preemptive (unless using Preemptive Priority Scheduling).
   Advantages:
   * Prioritizes important processes.
   * Customizable based on requirements.
   Disadvantages:
   * Starvation (low-priority processes may wait indefinitely).
5. Feedback Algorithm
   Description: Feedback scheduling allows processes to move between different queues.
   Working:
   * Multiple queues with different priorities (e.g., high, medium, low).
   * Processes start in the highest-priority queue.
   * If not completed, they move to the next lower-priority queue.
   * Preemptive or non-preemptive.
   Advantages:
   * Dynamic adaptation to process behavior.
   * Supports interactive and batch processes.
   Disadvantages:
   * Complexity in managing multiple queues.
