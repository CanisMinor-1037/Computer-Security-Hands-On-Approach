#include <stdio.h>
#include <unistd.h>
extern char ** environ;
int main(int argc, char * argv[], char * envp[]) {
    int i = 0;
    char * v[2];
    char * newenv[3];

    if (argc < 2) {
        return 0;
    }

    // Construct argument array
    v[0] = "/usr/bin/env";
    v[1] = NULL;

    // Construct environment variable array
    newenv[0] = "AAA=aaa";
    newenv[1] = "BBB=bbb";
    newenv[2] = NULL;

    switch (argv[1][0]) {
        case '1':
            execve(v[0], v, NULL);
            break;
        case '2':
            execve(v[0], v, newenv);
            break;
        case '3':
            execve(v[0], v, environ);
            break;
        default:
            break;
    }
    return 0;
}