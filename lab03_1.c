#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        printf("Hello from the child\n");
        exit(0);
    } else {
        // Parent process
        waitpid(child_pid, &status, 0); // Wait for the child to finish
        printf("Hello this is the parent, my child is %d\n", child_pid);
        printf("Goodbye from the parent\n");
    }

    return 0;
}
