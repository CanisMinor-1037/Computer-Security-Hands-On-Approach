#include <stdio.h>
#include <stdlib.h>
extern char ** environ;
int main(int argc, char * argv[], char * envp[]) {
    int i = 0;
    while (environ[i]) {
        printf("%s\n", environ[i++]);
    }
    printf("%s\n", getenv("TERM_PROGRAM"));
    if (putenv("MYENV=123") == 0) {
        printf("%s\n", getenv("MYENV"));
    } else {
        printf("putenv() failed\n");
    }
    if (putenv("TERM_PROGRAM=vscode123") == 0) {
        printf("%s\n", getenv("TERM_PROGRAM"));
    } else {
        printf("putenv() failed\n");
    }
    int ret_setenv = 0;
    ret_setenv = setenv("TERM_PROGRAM", "vscode111", 0);
    printf("%d, %s\n", ret_setenv, getenv("TERM_PROGRAM"));
    ret_setenv = setenv("TERM_PROGRAM", "vscode111", 1);
    printf("%d, %s\n", ret_setenv, getenv("TERM_PROGRAM"));
    unsetenv("MYENV");
    if (getenv("MYENV") == NULL) {
        printf("unsetenv() success\n");
    } else {
        printf("unsetenv() failed\n");
    }
    return 0;
}