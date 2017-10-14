/*
 * ModelInit.cpp
 *
 *  Created on:2017.3.21
 *      Author: shenjj
 */
#include "common.h"
extern pthread_mutex_t mutex_writelog;

//日志文件缓存
char log_buffer[32766];

//线程安全的时间格式转换
struct tm *localtime_user(const time_t *time, struct tm *resultp)
{
	//pthread_mutex_lock(&mutex_time);
	localtime_r(time, resultp);
	//pthread_mutex_unlock(&mutex_time);
	return resultp;
}


//显示时间
void displaytime(time_t t)
{
	char des[20];
	struct tm local;
	localtime_user(&t, &local);
	memset(des, 0, 20);
	sprintf(des, "%04d-%02d-%02d %02d:%02d:%02d", local.tm_year + 1900, local.tm_mon + 1, local.tm_mday, local.tm_hour, local.tm_min, local.tm_sec);
	DPRINTS(des);
	DPRINTS("\n");
}


//数字转字符串
void itoa(unsigned int num, char *str, unsigned char radix)
{
	char string[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	char *ptr = str;
	int i;
	int j;

	if(num == 0)
	{
		str[0] = '0';
		str[1] = '0';
		str[2] = '\0';
		return;
	}

	while(num)
	{
		*ptr++ = string[num % radix];
		num /= radix;

		if (num < radix)
		{
			*ptr++ = string[num];
			*ptr = '\0';
			break;
		}
	}

	j = ptr - str - 1;

	for(i = 0; i < (ptr - str) / 2; i++)
	{
		int temp = str[i];
		str[i] = str[j];
		str[j--] = temp;
	}
}

//保存日志
void writelog(char* WriteLog, time_t savetime, bool cache)
{
	FILE * fp;
	struct tm *local;
	char cDate[9], cTemp[5], buf[1024];
	if(strlen(WriteLog) <= 0 && strlen(log_buffer) <= 0) return;
	if(strlen(WriteLog) + strlen(log_buffer) > sizeof(log_buffer)) return;
	pthread_mutex_lock(&mutex_writelog);
	strncat(log_buffer, WriteLog, strlen(WriteLog));
	//if(cache && strlen(log_buffer) < 10)
	//{
	//	pthread_mutex_unlock(&mutex_writelog);
	//	return;
	//}
	time_t t = ((savetime == 0) ? time(0) : savetime);
	local = localtime(&t);
	//年
	memset(cTemp,0,sizeof(char)*5);
	memset(cDate,0,sizeof(char)*10);
	//itoa(local->tm_year + 1900, cTemp, 5);
	sprintf(cTemp,"%4d",local->tm_year+1900);
	memcpy(cDate, cTemp, 4);
	memset(cTemp,0,sizeof(char)*5);
	//itoa(local->tm_mon + 1, cTemp, 3);	
	sprintf(cTemp,"%02d",local->tm_mon + 1);
	strncat(cDate, cTemp, 2);
	//日
	memset(cTemp,0,sizeof(char)*5);
	//itoa(local->tm_mday, cTemp, 3);
	sprintf(cTemp,"%02d",local->tm_mday);
	strncat(cDate, cTemp, 2);
	//文件名
	memset(buf, 0, sizeof(buf));
	strcpy(buf, LOGFILE_PATH);
	//创建文件夹
	mkdir(buf, S_IRWXU | S_IRWXG | S_IRWXO);
	strncat(buf, cDate, 8);
	strcat(buf, ".txt");
	fp = fopen(buf,"ab+");
	if(fp != NULL)
	{
		fwrite(log_buffer, strlen(log_buffer), sizeof(unsigned char), fp);
		memset(log_buffer, 0, sizeof(log_buffer));
		fflush(fp);
	}
	fclose(fp);
	pthread_mutex_unlock(&mutex_writelog);
}
//将二进制码转换为BCD码
char bin2bcd(char val)
{
	return ((val / 10) << 4) + val % 10;
}

