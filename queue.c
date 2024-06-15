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
        int i, len;
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
            for (i = 1; i <=5; i++) {
        mubuf.mtupe = 1;
        strcpy(mubuf.mtext, "Nothing to lose, because we lost it all befor");
        len = strlen(mubuf.mtext) +1;
          if((msgsnd(msqid, (struct msgbuf *)&mybuf, len, 0) < 0) {
                printf("Сообщение не получилось отправить\n");
                msgctl(msqid, IPC_RMID, struct msqid_ds *)NULL);
                exit(-1);
                }
        }
        mubuf.mtupe = LAST_MESSAGE;
        len = 0;
        if((msgsnd(msqid, (struct msgbuf *)&mybuf, len, 0) < 0) {
                printf("Последнее сообщение не отправлено\n");
                 msgctl(msqid, IPC_RMID, struct msqid_ds *)NULL);
                exit(-1);
        }

                return 0;
}
