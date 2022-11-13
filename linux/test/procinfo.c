#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/utsname.h>

// perf record -e LLC-loads,LLC-load-misses yourExecutable

int main()
{
    // 0
    pid_t pid = getpid();
    printf("self pid=%d\n", (int)pid);

    // 1
    struct utsname buf1;
    errno = 0;
    if(uname(&buf1)!=0)
    {
        perror("uname doesn't return 0, so there is an error");
        exit(EXIT_FAILURE);
    }

    printf("System Name = %s\n", buf1.sysname);
    printf("Node Name = %s\n", buf1.nodename);
    printf("Version = %s\n", buf1.version);
    printf("Release = %s\n", buf1.release);
    printf("Machine = %s\n", buf1.machine);
    printf("-------\n");

    // 2
    char cmd[64];
    snprintf(cmd, sizeof(cmd), "cat /proc/%d/status", (int)pid);

    int counter = 0;
    char *mem[1024];
    while (1)
    {
        mem[counter] = (char*)malloc(1024 * 1024);
        memset(mem[counter], 0, 1024 * 1024);


        system(cmd);
        printf("-------%d\n", counter++);
        sleep(1);
    }
}