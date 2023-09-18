#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;

    char* cmd = "/bin/date";
    char* args[] = {cmd, "--version", NULL};

    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        printf("I'm about to execute command %s\n", cmd);
        execv(cmd, args);
        perror("Execv failed");
        exit(1);
    } else {
        // Parent process
        waitpid(child_pid, &status, 0); // Wait for the child to finish
        printf("Program /bin/date returned with code %d\n", WEXITSTATUS(status));
    }

    return 0;
}
