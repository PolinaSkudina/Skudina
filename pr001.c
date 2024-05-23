#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main() {
	uid_t userid;
	gid_t groupid;
	pid_t procid, parentid;
	userid = getpid();
	groupid = getpid();
	procid = getpid();
	parentid = getppid();
	printf("Ид. пользователя: %d\nИд. группы %d\n", userid, groupid);
	printf("Ид. текущего процесса: %d\nИд. родительского процесса: %d\n", procid, parentid);
	return 0;
}
