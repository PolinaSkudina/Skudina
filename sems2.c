#include <sys/types.h>
#include <sys/ipc.h>    
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

int main () {
        int semid;
        char pathname[] = "key.ipc";
        key_t key ;
        struct sembuf mubuf;
        if((key = ftok(pathname, 0)) < 0) {
                printf("Не удалось сгененрировать ключ ipc\n");
                exit(-1);
        }
        if((semid = semget(key, 1, 0666 | IPC_CREAT)) < 0) {
                printf("Не удалось получить доступ к массиву семафоров\n");
                exit(-1);
        }
        mubuf.sem_op = 1;
        mubuf.sem_flg = 0;
        mubuf.sem_num = 0;
        if(semop(semid, &mubuf, 1) < 0) {
                printf("Не удалось выполнить операцию над семафором\n");
                exit(-1);
        }
                printf("Семафор установлен в единицу\n");
                return 0;
}
