#include <stdio.h>
#include <stdlib.h>

void handle(char* commands[]) {
    for(int i = 0; i < sizeof(commands) / sizeof(char*); i++) {

    }
    if(system(command) != 0) { printf("%s : RETURNED NON 0 CODE", command); }
}

int submit(char* type, int n) {
    printf("testing");
    //128 Byte buffer -> 512 bits
    char buffer[128];
    sprintf(
        buffer,
        "git checkout -b %s%d && git ls-files | grep -Ev %s%d > testing.txt",
        type, n, type, n
    );
    handle(sprintf("git checkout -b %s%d", type, n));
    handle(sprintf("git ls-files | grep -Ev %s%d >)", sprintf("%s|.gitignore|README.md|utils.h", type), n));
}

int main(int argc, char* argv) {
    for(int i = 0; i < argc; i++) {
        int cft, hw, lab;
        if(argv[i] == "--cft" && i + 1 < argc) { submit("cft", argv[i + 1]); }
        if(argv[i] == "--hw" && i + 1 < argc) { submit("hw", argv[i + 1]); }
        if(argv[i] == "--lab" && i + 1 < argc) { submit("lab", argv[i + 1]); }
    }
    return 0;
} 

