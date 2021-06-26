#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
void f1(){
int i;
for(i=0; i<3; i++) {
if(fork() == 0) {}
printf("pid=%d ppid=%d\n", getpid(), getppid());
wait(0);
}
}

int main() {
    f1();
    return 0;
}
// this yields 8 processes