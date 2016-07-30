#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;
string standard="no leaks are possible";
string filename="valgrind_out_solutions.txt";
int case_test();
int mem_test();

int main(){
    cout<<"case test running......"<<endl;
    case_test();
    cout<<"memory test running......"<<endl;
//    mem_test();
    return 0;
}
int mem_test(){
    pid_t p1=fork();
    if(p1==0){
        int fd=open("valgrind_test.txt",O_RDWR | O_CLOEXEC | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG);
        if(fd<0){
            perror("Failed to open txt file");
            exit(1);
        }
        dup2(fd,STDOUT_FILENO);
        execlp("valgrind","./your_vector.out",NULL);
        perror("Execlp failed:");
        exit(1);
    }
    else if(p1>0){
        int status;
        pid_t w_result=waitpid(p1,&status,0);
        if(w_result==-1){
            perror("Failed to wait");
            exit(1);
        }
        ifstream file;
        file.open(filename,ios::in|ios::out);
        if(file.fail()){
            perror("failed to open valgrind text files");
            exit(1);
        }
        string line;
        bool flag=false;
        while(getline(file,line)){
            if(line.find(standard)!=-1){
                flag=true;
            }
        }
        file.close();
        }
    }
    else{
        perror("Failed to fork");
        exit(1);
    }
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
        if(p2==0){//child process
            int fd_null=open("/dev/null",O_RDWR);
            dup2(fd_null,STDOUT_FILENO);
            execlp("diff","diff","your_vector.txt","your_vector_solution.txt");
            perror("Execlp diff failed");
            exit(1);
        }
        else if(p2>0){
            int status2;
            waitpid(p2,&status2,0);
            if(WIFEXITED(status2)){
                if(WEXITSTATUS(status2)!=0){
                    cout<<"case test failed"<<endl;
                }
                else{
                    cout<<"case test passed"<<endl;
                }
            }
            
        }
        else{
            perror("Failed to fork");
            exit(1);
        }

    }
    else{
        perror("Failed to fork");
        exit(1);
    }
    return 0;
}
