#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid,i;
  pid = fork();
  if(pid == 0){
    for(i=1;i<=10;i++){
    	printf(1,"Child\n");
	yield();
    }
  }
  else{
    for(i=1;i<=10;i++){
    	printf(1,"Parent\n");
	yield();
    }
  }
  if(pid!=0){
    wait();
  }
  exit();
}
