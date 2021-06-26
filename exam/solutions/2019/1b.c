#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
void f2(){
int i, p = 0;
for(i=0; i<3; i++) {
    if(p == 0) {
        p = fork();
    }
    printf("pid=%d ppid=%d\n", getpid(), getppid());
    wait(0);
}
}

int main() {
    f2();
    return 0;
}
// this yields 3 child processes