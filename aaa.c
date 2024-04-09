# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int main(void){
    pid_t pid;    // 定义一个pid类型的变量，存放进程号

    printf("Before fork ...\n");

    // 调用fork()系统调用，创建一个子进程
    switch (pid = fork())
    {
    case -1:
        /* code */
        printf("fork call fail\n");
        fflush(stdout);
        exit(1);
    case 0:
        printf("I am child.\n");
        printf("The pid of child is: %d\n",getpid());
        printf("The pid of child`s parent is: %d\n", getppid());
        printf("Child exiting...\n");
        exit(0);
   
    default:
        printf("I am father.\n");
        printf("The pid of father is: %d\n",getpid());
        printf("The pid of father`s child is: %d\n", pid);
    }
    sleep(1);   
    printf("After fork, program exiting...\n");
    exit(0);
}
