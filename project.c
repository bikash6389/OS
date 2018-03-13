#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
pid_t p;
p = fork();
if(p<0)
 printf("Error\n");
if(p == 0) {
printf("I am child my id is %d\n", getpid());
printf("My parent is %d", getppid());
}
if(p>0) {
printf("I am parent %d\n", getpid());
printf("My child is %d\n", p);
}

}