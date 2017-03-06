#tar -cvf 102.tar iot/
#export PS1='> '

Files = root.c \
STATE_MACHINE.c \
P31u/i2c.c \
P31u/info.c \


CC=gcc
CCFLAGS= -g -Wall -Werror  -std=gnu99
OUTPUT= test


all:
	$(CC) $(CCFLAGS) ${Files} -o ${OUTPUT}

