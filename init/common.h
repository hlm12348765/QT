/*
 * common.h
 *
 *  Created on: 2017.3.20
 *      Author: shenjj
 */

#ifndef COMMON_H_
#define COMMON_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <asm/termios.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <signal.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <pthread.h>
#include <string.h>
#include <sys/ioctl.h>  
#include <math.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>
#include <string>

#include <linux/videodev2.h>
#include <fstream>
#include <iostream>

  
#include <netdb.h>  
#include <net/if.h>  
#include <arpa/inet.h>  
#include <sys/ioctl.h>  
#include <sys/types.h>  
#include <sys/socket.h>  


#ifdef DEBUG
#define DPRINTS(x...)	do{char buf[256]; strcpy(buf,x);writelog(x, 0, true); printf("%s", x);} while(0)
#define DPRINTD(x...)	do{char savestring[20]; sprintf(savestring, "%d", x); writelog(savestring, 0, true); printf("%s", savestring);} while(0)
#define DPRINTF(x...)	do{char savestring[20]; sprintf(savestring, "%f", x); writelog(savestring, 0, true); printf("%s", savestring);} while(0)
#define DPRINTLF(x...)	do{char savestring[20]; sprintf(savestring, "%10.14f", x); writelog(savestring, 0, true); printf("%s", savestring);} while(0)

#else
#define DPRINTS(x...)	do{char buf[256]; strcpy(buf,x);writelog(buf, 0, 1);} while(0)
#define DPRINTD(x...)	do{char savestring[20]; sprintf(savestring, "%d", x); writelog(savestring, 0, 1);} while(0)
#define DPRINTF(x...)	do{char savestring[20]; sprintf(savestring, "%f", x); writelog(savestring, 0, true);} while(0)
#define DPRINTLF(x...)	do{char savestring[20]; sprintf(savestring, "%10.14f", x); writelog(savestring, 0, true);} while(0)
#endif


#define ___double_cache_size        32766
#define LOGFILE_PATH                "/home/logfile/"
#define MAC_SIZE    18  
#define IP_SIZE     16  


//LCD显示结构体
struct LCD_SPEAK
{
	//LCD显示内容
	const char* lcd_str;
	//播放语音
	const char* sp_voice;
	//编号
	const char* number;

};


struct INIT_FLAG
{
	int ising;
	pthread_mutex_t ising_mutex;
	int unpass;
	pthread_mutex_t unpass_mutex;
	int already;
	pthread_mutex_t already_mutex;
	int sucess;
	pthread_mutex_t sucess_mutex;

};

struct tm *localtime_user(const time_t *time, struct tm *resultp);
void displaytime(time_t t);
void itoa(unsigned int num, char *str, unsigned char radix);
void writelog(char* WriteLog, time_t savetime, bool cache);



#endif /* COMMON_H_ */


