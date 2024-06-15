#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <sys/msg.h>
#include  <string.h>
#define LAST_MESSAGE 255

int main() {
        int msqid;
        char  pathname[] = "key.ipc";
        key_t key;
        int len, maxlen;
        struct mymsgbuf {
                long mtype;
                char mtext[81];
        } mybuf;

        if((key=ftok(pathname, 0)) < 0) {
                printf("Не удалось сгененрировать ключ\n");
                exit(-1);
        }
        if((msqid = msgget(key, 1, 0666 | IPC_CREAT)) < 0) {
                printf("Не удалось создать или найти очередь\n");
                exit(-1);
        }
        while(1) {
                maxlen = 81;
                if((len = msgrcv(msqid, (struct msgbuf *)&mybuf, len, 0) < 0) {
                printf("Сообщение не получилось отправить\n");
                exit(-1);
                }
                if(mubuf.mtype == LAST_MESSAGE) {
                msgctl(msqid, IPC_RMID, struct msqid_ds *)NULL);
                exit(0)
                }
                printf("Тип сообщения %ld, текст %s\n, mubuf.mtype, mubuf.mtext");
        }

                return 0;
}

