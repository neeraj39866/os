#include<stdio.h> 
using namespace std; 
const int a = 5; // Number of processes 
const int b= 3; // Number of resources 
void calneed(int need[a][b], int maxm[a][b], int allot[a][b]) // Function to find the need of each process 
{ 
    for (int i = 0 ; i < a ; i++) 
        for (int j = 0 ; j < b ; j++)  
            need[i][j] = maxm[i][j] - allot[i][j]; //Need of instance= max instance-allocated instance
} 
bool isSafe(int processes[], int avail[], int maxm[][b],int allot[][b]) 
{ 
    int need[a][b]; 
    calneed(need, maxm, allot); // Function to calculate need matrix 
    bool finish[a] = {0};  // Mark all processes as infinish 
    int safeSeq[a]; // To store safe sequence 
    int work[b]; 
    for (int i = 0; i < b ; i++) //duplicacy in work resource
        work[i] = avail[i]; 
  
    // While all processes are not finished 
    // or system is not in safe state. 
    int count = 0; 
    while (count < a) //find a process which is not finished
    {  
     bool found=false;
        for (int c = 0; c < a; c++) 
        {  
            if (finish[c] == 0) //checking process is finished or not
            { 
                int j; 
                for (j = 0; j < b; j++) //checking current p is less than work or not
                    if (need[c][j] > work[j]) 
                        break;
                if (j == b) // If all needs of p were satisfied. 
                {  
                    for (int k = 0 ; k < b ; k++) //Add the allocated resource of current P to he work resource
                        work[k] += allot[c][k]; 
                    safeSeq[count++] = c; // Mark it safe add this process to safe sequence.
                    finish[c] = 1; // Mark this p as finished 
                    found = true; 
                } 
            } 
        }  
        if (found == false) // If we could not find a next process in safe sequence
        { 
            printf("System is not in safe state"); 
            return false; 
        } 
    } 
    // If system is in safe state then safe sequence will be as below 
    printf( "System is in safe state.\nSafe sequence is: "); 
    for (int i = 0; i < a ; i++) 
        printf("%d ",safeSeq[i]); 
    return true;  
} 
int main() 
{ 
    int processes[] = {0, 1, 2, 3, 4}; 
    int avail[] = {5, 3, 2}; // Available instances of resources 
    int maxm[][b] = {{7, 8, 4},{3, 2, 2},{9, 0, 6},{2, 8, 2},{4, 5, 3}}; // Maximum R that can be allocated to processes
    int allot[][b] = {{0, 6, 0}, {2, 6, 0}, {3, 7, 2},{2, 6, 1}, {1, 6, 2}}; // Resources allocated to processes 
    isSafe(processes, avail, maxm, allot); // Check system is in safe state or not
    return 0; 
} 
