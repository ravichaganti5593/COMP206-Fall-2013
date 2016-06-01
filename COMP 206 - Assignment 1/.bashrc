#!/bin/bash
# .bashrc 

# Source global definitions
if [ -f /usr/socs/Profile ]; then
        . /usr/socs/Profile
fi

# User specific aliases and functions
export PS1="\e[0;32m[\u@ \W Hello Ravi]\$ \e[m"
ls
date
who
finger vnagar
alias lsa='ls -l -a'
firefox
