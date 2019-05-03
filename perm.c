#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define NGID 1000 //for hasan/student	
#define NUID 1000 //for hasan/student


int main(int argc, char** argv){
	
	uid_t cur_uid;  
	cur_uid = getuid();
	
	printf("The current user ID is %d\n", cur_uid);

	if(cur_uid == 0 )	// we are running as root. let's drop it
	{
		setgid(NGID);
		setuid(NUID);
	}
	
	cur_uid = getuid();	
	printf("The current user ID is %d\n", cur_uid);
}


