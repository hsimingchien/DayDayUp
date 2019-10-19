#include <stdio.h>
#include <signal.h>

void signal_handle(int sig_num)
{
    static int sig_total_num = 0;
    if(sig_num == SIGUSR1)
    {
        printf("Capture SIGUSR1\n");
~~~~~~~~
    }
    else
    {
        //printf("program is exited!\n");
    }

    sig_total_num++;
    printf("signal_handle running ...\n");
    printf("The Capture Sig numbers is:%d\n", sig_total_num);
}

int main(int argc, char **argv)
{
    signal(SIGUSR1, signal_handle);
    signal(SIGUSR2, signal_handle);
    while(1)
        sleep(100);
    return 0;
}
