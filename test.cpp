#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
int case_test();
int mem_test();
int main(){
    cout<<"case test running......"<<endl;
    case_test();
    cout<<"memory test running......"<<endl;
    mem_test();
    return 0;
}

int case_test(){
    pid_t p1=fork();
    if(p1==0){//child process
        int fd=open("your_vector.txt",O_RDWR | O_CLOEXEC | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG);
        if(fd<0){
            perror("Failed to open txt file");
            exit(1);
        }
        dup2(fd,STDOUT_FILENO);
        execlp("./your_vector.out","./your_vector.out",NULL);
        perror("Execlp failed:");
        exit(1);
    }
    else if(p1>0){//parent process
        int status;
        pid_t w_result=waitpid(p1,&status,0);
        if(w_result==-1){
            perror("Failed to wait");
            exit(1);
        }
        pid_t p2=fork();
        if(p2==0){
            int fd_null
        }

    }
}
