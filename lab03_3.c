#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char *paths[] = { "/local/bin", "/usr/lib", "/usr", "/usr/bin/core",
                      "/usr/ban", "/usr/bin", "/bin" };

    char *cmd = "uname";  // Set cmd to the command name
    char *args[] = { "uname", "-a", NULL }; // Set up arguments for execv

    const int NPATHS = sizeof(paths) / sizeof(char *);

    for (size_t i = 0; i < NPATHS; i++) {
        char *path = paths[i];
        printf("Trying path %s/%s\n", path, cmd);

        // Allocate memory for the full path to the executable
        char filename[1024];
        snprintf(filename, sizeof(filename), "%s/%s", path, cmd);

        // Attempt to execute the command
        execv(filename, args);

        // If execv fails, print an error message and continue to the next path
        perror("execv");
        printf("%s was not a valid path, trying something else\n", filename);
    }

    printf("Could not find program %s\n", cmd);
    return 0;
}