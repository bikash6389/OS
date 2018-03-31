#include<stdio.h>

struct detail {
	int process_id, arrival_time, burst_time, priority;
};

int main() {
	int rr,p,f,total_process,i;
	printf("Enter the number of process for RoundRobin, Priority and FCFS queue: ");
	scanf("%d%d%d", &rr, &p, &f);
	total_process = rr + p + f;
	struct detail ob[total_process];
	for(i=0;i<total_process;i++){
		    printf("\nProcess ID:\t");
            scanf("%d", &ob[i].process_id);
            printf("Arrival Time:\t");
            scanf("%d", &ob[i].arrival_time);
            printf("Burst Time:\t");
            scanf("%d", &ob[i].burst_time);
            printf("Queue Number:\t");
            scanf("%d", &ob[i].priority);
	}
	
	printf("\nProcess ID\t"); 
	printf("Arrival Time\t");
	printf("Burst Time\t");
	printf("Queue Number\t");  
	for(i=0;i<total_process;i++){
		printf("\n");
		printf("  p[%d]\t\t",ob[i].process_id);
		printf("  %d\t\t",ob[i].arrival_time);
		printf("  %d\t\t",ob[i].burst_time);
		printf("  %d\t\t",ob[i].priority);
		
	}
	
}
