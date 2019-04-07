Question 9:There are 5 processes and 3 resource types, resource A with 10 instances, B with 5 instances and C with 7 instances. Consider following and write a c code to find whether the system is in safe state or not::  
     Available	   Processes	Allocation	Max
A	B	C	   A	B	C   	A	B	C
3	3	2  P0      0	1	0   	7	5	3
	           P1	   2	0	0   	3	2	2
	           P2	   3	0	2   	9	0	2
	           P3	   2	1	1   	2	2	2
	           P4      0	0	2   	4	3	3
Solution:From given scenario,it is specified that it is an axample of banker's algorithm.From given data firstly we are calculating need matrix such that need=max-allocated. then use available matrix and start subtracting need whose need can be fulfilled thrn add max value coresponds to that particular value then repeat till the safe sequence not achieved.in last print the safe sequence.

Ques. 19. Design a scheduler that uses a preemptive priority scheduling algorithm based on dynamically changing priority. Larger number for priority indicates higher priority.When the process starts execution (i.e. CPU assigned), priority for that process changes at the rate of m=1.When the process waits for CPU in the ready queue (but not yet started execution), its priority changes at a rate n=2. All the processes are initially assigned priority value of 0 when they enter ready queue for the first time . The time slice for each process is q = 1. When two processes want to join ready queue simultaneously, the process which has not executed recently is given priority. Calculate the average waiting time for each process. The program must be generic i.e. number of processes, their burst time and arrival time must be entered by user. 
Solution: It is an example of multilevel schedulling as we are using round robin scheduling with time quantam =1 and priority schedulling ,where larger number for priority indicates higher priority. Thus by taking information from user about the processes such that number of processes,burst time,and arrival time ,we are calculating average waiting time for each processes.


