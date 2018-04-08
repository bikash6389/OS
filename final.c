#include<stdio.h>

struct detail {
	int process_id, arrival_time, burst_time, priority, rem_time;
};

void roundRobin(struct detail round[], int kk);
void fcfs1(struct detail fcfs[], int pp);

int main() {
	int rr,p,f,total_process,i;
	printf("Enter the number of process for RoundRobin, Priority and FCFS queue: ");
	scanf("%d%d%d", &rr, &p, &f);
	total_process = rr + p + f;
	struct detail ob[total_process], round[rr], fcfs[f];
	for(i=0;i<total_process;i++){
		    printf("\nProcess ID:\t");
            scanf("%d", &ob[i].process_id);
            printf("Arrival Time:\t");
            scanf("%d", &ob[i].arrival_time);
            printf("Burst Time:\t");
            scanf("%d", &ob[i].burst_time);
            ob[i].rem_time = ob[i].burst_time;
            printf("Priority:\t");
            scanf("%d", &ob[i].priority);
	}
	
	printf("\nProcess ID\t"); 
	printf("Arrival Time\t");
	printf("Burst Time\t");
	printf("Priority\t"); 
	for(i=0;i<total_process;i++){
		printf("\n");
		printf("  p[%d]\t\t",ob[i].process_id);
		printf("  %d\t\t",ob[i].arrival_time);
		printf("  %d\t\t",ob[i].burst_time);
		printf("  %d\t\t",ob[i].priority);
		
	}
	
	int q1a, q1b, q2a, q2b, q3a, q3b, kk = 0, pp = 0;
	printf("\nEnter the priority range for Queue 1 (Round Robin): ");
	scanf("%d%d", &q1a, &q1b);
	printf("\nEnter the priority range for Queue 3 (FCFS): ");
	scanf("%d%d", &q2a, &q2b);

	for(i=0;i<total_process;i++)
	{
		if((ob[i].priority >= q1a) && (ob[i].priority <= q1b)) {
			round[kk].process_id = ob[i].process_id;
			round[kk].arrival_time = ob[i].arrival_time;
			round[kk].burst_time = ob[i].burst_time;
			round[kk].priority = ob[i].priority;
			round[kk].rem_time = ob[i].rem_time;
			kk++;
		}
		if((ob[i].priority >= q2a) && (ob[i].priority <= q2b)) {
			fcfs[pp].process_id = ob[i].process_id;
			fcfs[pp].arrival_time = 0;                   // fcfs[pp].arrival_time = ob[i].arrival_time;
			fcfs[pp].burst_time = ob[i].burst_time;
			fcfs[pp].priority = ob[i].priority;
			fcfs[pp].rem_time = ob[i].rem_time;
			pp++;		
		}
	}
	
	printf("\n\n-------------------------------------------------------------------------------------------\n\n");
	roundRobin(round, kk);
	printf("\n\n-------------------------------------------------------------------------------------------\n\n");
	fcfs1(fcfs, pp);
}

void roundRobin(struct detail round[], int kk) {
	
	int i, time_quantum,time=0,count,remain,flag=0,wait_time=0,turnaround_time=0,sm=0;
	printf("\nRound Robin table: \n");
	
	printf("\nProcess ID\t");
	printf("Arrival Time\t");
	printf("Burst Time\t");
	printf("Priority\t");
	for(i=0;i<kk;i++){
		printf("\n");
		printf("  p[%d]\t\t",round[i].process_id);
		printf("  %d\t\t",round[i].arrival_time);
		printf("  %d\t\t",round[i].burst_time);
		printf("  %d\t\t",round[i].priority);
		sm = sm + round[i].burst_time;	
	}
	
  time_quantum = 4; 
  printf("\n\nProcess\t \tTurnaround Time\t\tWaiting Time\n\n"); 
  for(time=0,count=0;remain!=0;)
  { 
    if(round[count].rem_time<=time_quantum && round[count].rem_time>0) 
    { 
      time+=round[count].rem_time; 
      round[count].rem_time =0; 
      flag=1; 
    } 
    else if(round[count].rem_time>0) 
    { 
      round[count].rem_time-=time_quantum; 
      time+=time_quantum; 
    } 
    if(round[count].rem_time==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t\t%d\t\t%d\n",count+1,time-round[count].arrival_time,time-round[count].arrival_time-round[count].burst_time); 
      wait_time+=time-round[count].arrival_time-round[count].burst_time; 
      turnaround_time+=time-round[count].arrival_time;
      flag=0; 
    } 
    if(count==kk-1)
      count=0; 
    else if(round[count+1].arrival_time<=time)
      count++;
    else
      count=0;
    if(time == sm)
    break;
  } 
  
  float avwt, avtat;
  avwt = wait_time/kk;
  avtat = turnaround_time/kk;
  printf("\n\nAverage Waiting Time:%d",avwt);
  printf("\nAverage Turnaround Time:%d",avtat); 
}


void fcfs1(struct detail fcfs[], int pp) {
	
	int i;
	printf("\nFCFS table: \n\n");
	printf("\nProcess ID\t");
//	printf("Arrival Time\t");
	printf("Burst Time\t");
	printf("Priority\t");
	for(i=0;i<pp;i++){
		printf("\n");
		printf("  p[%d]\t\t",fcfs[i].process_id);
//		printf("  %d\t\t",fcfs[i].arrival_time);
		printf("  %d\t\t",fcfs[i].burst_time);
		printf("  %d\t\t",fcfs[i].priority);
	}
	
	printf("\n\n");
	int wt[50], j, tat[20], avwt=0, avtat=0;
	wt[0] = 0;
 
    for(i=1;i<pp;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=fcfs[j].burst_time;
    }
 
    printf("\nProcess\t\tWaiting Time\tTurnaround Time");
 
    for(i=0;i<pp;i++)
    {
        tat[i]=fcfs[i].burst_time+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\n  P[%d]\t\t  %d\t\t  %d",fcfs[i].process_id,wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat); 
	
}
