#include "types.h"
#include "stat.h"
#include "user.h"
// int main(int argc, char *argv[]){
//     int pid = fork();
//     for(int i = 0; i<2; i++){
//         if(pid==0){
//             //자식
//             printf(1, "Child\n");
//             yield();
//         }else{
//             //부모
//             printf(1, "Parent\n");
//             yield();
//         }
//     }
//     if(pid!=0){
//         wait();
//     }
//     exit();
//     };

#define NUM_CHILD 5
#define NUM_LOOP1 50000
#define NUM_LOOP2 1000000
#define NUM_LOOP3 200000
#define NUM_LOOP4 1000000

int me;
int create_child(void){
  for(int i =0  ; i<NUM_CHILD; i++){
    int pid = fork();
    if(pid == 0){
        
      me = i;
      sleep(10);
      return 0;
    }
  } 
  return 1;
}

void exit_child(int parent) {
	if (parent)
		while (wait() != -1);
	exit();
}

int main()
{
  int p;
  p = create_child();

	if (!p) {
		int arr[5] = {0, };

		for (int i = 0; i < NUM_LOOP3; i++) {
			arr[getlev()]++;
		}
		printf(1, "pid %d : L0=%d, L1=%d, L2=%d, L3=%d, L4=%d\n", getpid(), arr[0], arr[1], arr[2], arr[3], arr[4]);
        int a = arr[0];
        int b = arr[1];
        int c = arr[2];
        int d = arr[3];
        //int e = arr[4];
        printf(1,"%d\n", a+b+c+d);
	}
	exit_child(p);
}