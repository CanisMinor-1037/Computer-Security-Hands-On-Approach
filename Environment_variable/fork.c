#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
extern ** environ;
FILE * fp_parent;
FILE * fp_child;
int main(int argc, char * argv[], char * envp[]) {
    pid_t pid = fork();
    if (pid < 0) {
        printf("fork() failed");
    } else if (pid == 0) {
        printf("In child process:\n");
        int i = 0;
        fp_child = fopen("child_process_environ.txt", "a+");
        while (environ[i]) {
            //printf("[child process]%s\n", environ[i++]);
            fwrite(environ[i],strlen(environ[i]), 1, fp_child);
            fwrite("\r\n", 1, 2, fp_child);
            i++;
        }
        fclose(fp_child);
    } else {
        printf("In parent process:\n");
        int i = 0;
        fp_parent = fopen("parent_process_environ.txt", "a+");
        while (environ[i]) {
            //printf("[parent process]%s\n", environ[i++]);
            fwrite(environ[i], strlen(environ[i]), 1, fp_parent);
            fwrite("\r\n", 1, 2, fp_parent);
            i++;
        }
    }
    // use "diff"
    return 0;
}
