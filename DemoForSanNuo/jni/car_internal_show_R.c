#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

#include "car_internal_show_R.h"

#define RS232_NAME 		"/dev/ttyS0"
#define RS232_BAUD 		(B9600)
#define RS232_BUF_SIZE		512
#define CMD_STR			0x01
#define CMD_DIGITAL		0x20
#define USE_BIG_ENDIAN
#define DEBUG  

unsigned char buf[RS232_BUF_SIZE] = {0}; 
car_show_iterm_t tojava_1 = {0} ; //
char tojava_2[128] = {0};
int rs232_fd = -1;
static int count = 0;
static int number = 0;

int command_parse(void)
{
	if((buf[0] != 0x55) || buf[1] != 0xaa)
	{
		printf("waring:parse error1\n");
		return -1;
	}
	number = buf[2];
	switch(buf[3])
	{
		case CMD_STR:
			memcpy(tojava_2, buf+4, number);
#ifdef DEBUG
			printf("to jave string is [%s]\n", tojava_2);
#endif
		break;

		case CMD_DIGITAL:
			memcpy((char *)&tojava_1, buf+4, 16);
#ifdef USE_BIG_ENDIAN
			tojava_1.speed1=htons(tojava_1.speed1);
			tojava_1.speed2=htons(tojava_1.speed2);
			tojava_1.speed3=htons(tojava_1.speed3);
			tojava_1.speed4=htons(tojava_1.speed4);
			tojava_1.speed5=htons(tojava_1.speed5);
			tojava_1.speed6=htons(tojava_1.speed6);
			tojava_1.speed7=htons(tojava_1.speed7);
			tojava_1.speed8=htons(tojava_1.speed8);
#endif
#ifdef DEBUG
	printf("to java 1 is [%x], [%x], [%x], [%x], [%x], [%x], [%x], [%x]\n", tojava_1.speed1, tojava_1.speed2, tojava_1.speed3, tojava_1.speed4, tojava_1.speed5, tojava_1.speed6, tojava_1.speed7, tojava_1.speed8);
#endif
		break;
		
		default:
			printf("waring:parse error1\n");
			return -1;
		break;
	}
	return 0;
}

void *read_thread(void *arg)
{
	int i=0;
	unsigned char chksum=0;
	fd_set read_fds;
	struct timeval timeout = {0, 100};///0s, 100ms
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		count=0;
		number = 0;
		chksum = 0;

		while(1)
		{
			i=read(rs232_fd, buf+count, 1);
			if(i==1)
				count++;
			else
				continue;
#ifdef DEBUG
			printf("(%x)",buf[count-1]);
#endif
			if(count == 1)
			{
				if(buf[0] != 0x55)
				{		
					count = 0;
					continue;
				}
			}
			if(count == 2)
			{
				if(buf[1] != 0xaa)
				{	
					count = 0;
					continue;
				}
			}
			if(count > 2)
			{
				number = buf[2];
			}

			if(number != 0)
			{
				if(number == (count-4))
					break;
			}
			
		}
#ifdef DEBUG
		printf("aahtest buf is:[\n");
#endif
		i=0;
		for(i=0;i<(number+1);i++)
		{
#ifdef DEBUG
			printf("%x ",buf[i+2]);
#endif
			chksum += buf[i+2];
		}
#ifdef DEBUG
		printf(" -%x]-%x\n", buf[count-1],chksum);
#endif
		if(buf[count-1] == chksum)
			command_parse();
		else
			printf("waring: check sum error once\n");
		
	}

	return NULL;
}

int StartRunning(void)
{
	struct termios opt;
	pthread_t pid;

	//rs232_fd = open("/dev/ttyS0", O_RDONLY);
	rs232_fd = open(RS232_NAME, O_RDONLY|O_NONBLOCK);
	if(rs232_fd < 0)
	{
		printf("Open uart [%s] error, line %d !\n", RS232_NAME, __LINE__);
		return -1;
	}
	else
		printf("Open %s OK\n", RS232_NAME);
//	fcntl(rs232_fd, F_SETFL, O_NONBLOCK);
	tcgetattr(rs232_fd, &opt);
//	tcflush(rs232_fd, TCIFLUSH);
	cfsetispeed(&opt, B9600);
	cfsetospeed(&opt, B9600);
        opt.c_cflag &= ~CSIZE;
	opt.c_cflag |= CS8;
	opt.c_cflag &= ~PARENB;
//	opt.c_oflag &= ~(OPOST);
	opt.c_cflag &= ~CSTOPB;
	opt.c_cflag &= ~CRTSCTS;
	opt.c_iflag &= ~(IXON|IXOFF|IXANY);
	opt.c_iflag |= INPCK;
	opt.c_lflag &= ~(ICANON|ISIG|ECHO|IEXTEN);
	opt.c_lflag &= ~(INPCK|BRKINT|ICRNL|ISTRIP|IXON);
	opt.c_cc[VMIN] = 0;
	opt.c_cc[VTIME] = 0;
	if(tcsetattr(rs232_fd, TCSANOW, &opt) != 0)
	{
		printf("Set uart [%s] attr error, line %d \n", RS232_NAME, __LINE__);
		close(rs232_fd);
		return -1;
	}
	tcflush(rs232_fd, TCIOFLUSH);
	
	if( pthread_create(&pid, NULL, read_thread, NULL) == 0 )
		printf("Create read thread OK\n");
	else
		printf("Create read thread error!,line %d\n", __LINE__);
	while(1)
	{
		sleep(1);
		printf("...add content here!!!!!!!!!.....\n");
	}
	if(rs232_fd)
		close(rs232_fd);
	exit(0);
}



