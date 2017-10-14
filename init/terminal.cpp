
#include "startup.h"
#include <QApplication>
#include <QTranslator>

#include "common.h"
#include "serial.h"
#include "sound.h"
#include <list>


using namespace std;

typedef list<LCD_SPEAK> LISTSPEAK;  
LISTSPEAK listlcd_speak;   


//监听usb线程
pthread_t    usb_listenid;   
pthread_attr_t usb_listenattr;
//播放语音线程
pthread_t    audio_id;                
pthread_attr_t audioattr;
//自处理线程
pthread_t   selfkill_id;                
pthread_attr_t selfkill_attr;
//lcd show
pthread_t   lcdshow_id;                
pthread_attr_t lcdshow_attr;
//file lock
pthread_mutex_t mutex_writelog;
//flag for lcd
INIT_FLAG flag;


void init();
void* usb_listen(void *param);
void* audio(void *param);
int update_udisk();
void speak_th();
void lcd_speak(const char* sp);
int get_local_mac(const char *eth_inf, char *mac); 
int get_local_ip(const char *eth_inf, char *ip); 
void* selfkill(void *param);

void*  lcd_show(void *param);

/**
 * @Description 
 * @param 无
 * @return  无
 */
int  main (int argc,char *argv[])
{
//记录启动时间
	//displaytime(time(0));
	//DPRINTS("The judge base_program started!\n");
	printf("start=======================\n");
//初始化
	init();
#if 1
//开启线程监听usb
	pthread_attr_init(&usb_listenattr);
	pthread_attr_setdetachstate(&usb_listenattr, PTHREAD_CREATE_DETACHED);
	if(pthread_create(&usb_listenid,NULL,usb_listen,NULL) != 0)
	{
		DPRINTS("USB linsten  Task Thread Failed!\n");
		return 0;
	}
	pthread_attr_destroy(&usb_listenattr);
// start the lcd show
	pthread_attr_init(&lcdshow_attr);
	pthread_attr_setdetachstate(&lcdshow_attr, PTHREAD_CREATE_DETACHED);
	if(pthread_create(&usb_listenid,NULL,lcd_show,NULL) != 0)
	{
		DPRINTS("USB linsten  Task Thread Failed!\n");
		return 0;
	}
	pthread_attr_destroy(&lcdshow_attr);

//开启音频播放线程
	pthread_attr_init(&audioattr);
	pthread_attr_setdetachstate(&audioattr, PTHREAD_CREATE_DETACHED);
	if(pthread_create(&audio_id,NULL,audio,NULL) != 0)
	{
		DPRINTS("Create AUDIO Task Thread Failed!\n");
		return 0;
	}
	pthread_attr_destroy(&audioattr);

	//开启自处理线程
	pthread_attr_init(&selfkill_attr);
	pthread_attr_setdetachstate(&selfkill_attr, PTHREAD_CREATE_DETACHED);
	if(pthread_create(&selfkill_id,NULL,selfkill,NULL) != 0)
	{
		DPRINTS("Create AUDIO Task Thread Failed!\n");
		return 0;
	}
	pthread_attr_destroy(&selfkill_attr);


	while(1)
	{
		sleep(1);
	}
#endif

	return 0;

}


void init()
{

	//初始化锁
	pthread_mutex_init(&mutex_writelog, NULL);
	pthread_mutex_init(&flag.ising_mutex,NULL);
	pthread_mutex_init(&flag.unpass_mutex, NULL);
	pthread_mutex_init(&flag.already_mutex, NULL);
	pthread_mutex_init(&flag.sucess_mutex, NULL);
	//自动提示
	LCD_SPEAK  lcd_speak_textA1={"正在预安装,请等待","/home/voice/I001.wav","I001"};
	listlcd_speak.push_back(lcd_speak_textA1);
	LCD_SPEAK  lcd_speak_textA2={"程序预安装成功，系统重启","/home/voice/I002.wav","I002"};
	listlcd_speak.push_back(lcd_speak_textA2);
	LCD_SPEAK  lcd_speak_textA3={"U盘内容格式不满足要求","/home/voice/I003.wav","I003"};
	listlcd_speak.push_back(lcd_speak_textA3);
	LCD_SPEAK  lcd_speak_textA4={"已预安装,无需再次安装","/home/voice/I004.wav","I004"};
	listlcd_speak.push_back(lcd_speak_textA4);

}



void*  lcd_show(void *param)
{
    int argc;
    char** argv;
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(":/qrc/qt_zh_CN.qm");
    a.installTranslator(&translator);
    startup s;
    s.show();


    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    a.exec();
    return NULL;
}

void* usb_listen(void *param)
{
	
	
	

	char ip[IP_SIZE];  
    	char mac[MAC_SIZE];	
   	const char *test_eth = "eth0";

	
	while(1){
		if(!access("/dev/sda", F_OK))
		{
			sleep(1);
			int ret = update_udisk();
			if(ret == 1)
			{
                printf("===================sucess\n");
				//lcd_speak("I002");
				pthread_mutex_lock(&flag.sucess_mutex);
				flag.sucess=1;
				pthread_mutex_unlock(&flag.sucess_mutex);
				sleep(5);
				system("reboot");
			}
			else if(ret == -1)
			{
				
                printf("===================no  u-storage\n");
				pthread_mutex_lock(&flag.unpass_mutex);
				flag.unpass=1;
				pthread_mutex_unlock(&flag.unpass_mutex);
				usleep(1000);				
			}
			else if(ret == -2)
			{
				
                printf("===================no file in u-storage\n");
				pthread_mutex_lock(&flag.unpass_mutex);
				flag.unpass=1;
				pthread_mutex_unlock(&flag.unpass_mutex);
				//lcd_speak("I003");
				break;		
			}
			else if(ret == -3)
			{
				
                printf("===================file is already\n");
				pthread_mutex_lock(&flag.already_mutex);
				flag.already=1;
				pthread_mutex_unlock(&flag.already_mutex);
				//lcd_speak("I004");
				sleep(5);
			}

		}
		//显示ip mac getway
		get_local_mac(test_eth, mac);
		
  
    		get_local_ip(test_eth, ip);
		
   	    //printf("local %s ip: %s\n", test_eth, ip); 

	}

}

/**
 * @Description  音频播放
 * @param  无
 * @return  无
 */
void* audio(void *param)
{
	while(1)
	{
		usleep(50);   //50us
		speak_th();
	}
	 return NULL;
}

/**
 * @Description  自处理
 * @param  无
 * @return  无
 */
void* selfkill(void *param)
{
	int pid_install=-1;
	char sys_buf[255];
		
	
	//获取pid
	pid_install = getpid();
	printf("pid=%d\n", pid_install);
	sprintf(sys_buf,"kill %d\n",pid_install);

	while(1)
	{
		//检查是否含有程序
		if(!access("/home/jar/km2system.jar", F_OK))
		{
			//已经预装过，结束本进程
			sleep(5);
			system(sys_buf);
			break;

		}
		else
		{
			//无预装过，等待60s
			sleep(60);
            //system(sys_buf);
			break;
		}
		sleep(1);

		
	}

}

//U盘升级 返回: 1:升级成功重启更新 -1:找不到U盘 -2:升级文件不存在 -3:文件已存在
int update_udisk(void )
{
	//是否进行U盘预装
	if(!access("/dev/sda1", F_OK))
	{
		if(!access("/media/sda1", F_OK))
		{
			if((!access("/home/jar/judge.zip", F_OK)) &&(!access("/media/sda1/km2_firstinstall/22/judge.zip", F_OK)))
			{
				//不用预装，文件已存在
				return -3;
			}
			if(!access("/media/sda1/km2_firstinstall/22/judge.zip", F_OK))
			{
				//升级jar包
				//lcd_speak("I001");
				  pthread_mutex_lock(&flag.ising_mutex);
			          flag.ising=1;
				  pthread_mutex_unlock(&flag.ising_mutex);
				//复制
				system("cp /media/sda1/km2_firstinstall/22/judge.zip  /home/jar/");
				usleep(1000*100);
				//printf("cp sucess then unzip\n");
				//解压
				system("unzip /home/jar/judge.zip  -d /home/jar/");
				//printf("unzip sucess then move\n");
				//判断内容,存在即拷贝过去
				if((!access("/home/jar/judge/km2system.jar", F_OK)) && 
					(!access("/home/jar/judge/tmri_ver.properties", F_OK)) &&
					  (!access("/home/jar/judge/exam_db.db", F_OK)))
				{
					system("mv /home/jar/judge/km2system.jar   /home/jar/");
					system("mv /home/jar/judge/tmri_ver.properties   /home/config/");
					system("mv /home/jar/judge/exam_db.db   /home/examinfo/ksprocess/");
					return 1;
				}
				else
				{
					return -2;
				}
			}
			else
			{
				return -2;
			}
		}
		else
		{
			return -1;
		}
	}
}
extern list<const char*> sound_lcd;

void lcd_speak(const char* sp)
{

	LISTSPEAK::iterator pt;
	for(pt=listlcd_speak.begin();pt!=listlcd_speak.end();pt++)
	{
		if (strstr(pt->number,sp)){
			sound_lcd.push_back(pt->sp_voice);
			sleep(1);	
		}
	}

}



// 获取本机mac  
int get_local_mac(const char *eth_inf, char *mac)  
{  
    struct ifreq ifr;  
    int sd;  
      
    bzero(&ifr, sizeof(struct ifreq));  
    if( (sd = socket(AF_INET, SOCK_STREAM, 0)) < 0)  
    {  
        printf("get %s mac address socket creat error\n", eth_inf);  
        return -1;  
    }  
      
    strncpy(ifr.ifr_name, eth_inf, sizeof(ifr.ifr_name) - 1);  
  
    if(ioctl(sd, SIOCGIFHWADDR, &ifr) < 0)  
    {  
        printf("get %s mac address error\n", eth_inf);  
        close(sd);  
        return -1;  
    }  
  
    snprintf(mac, MAC_SIZE, "%02x:%02x:%02x:%02x:%02x:%02x",  
        (unsigned char)ifr.ifr_hwaddr.sa_data[0],   
        (unsigned char)ifr.ifr_hwaddr.sa_data[1],  
        (unsigned char)ifr.ifr_hwaddr.sa_data[2],   
        (unsigned char)ifr.ifr_hwaddr.sa_data[3],  
        (unsigned char)ifr.ifr_hwaddr.sa_data[4],  
        (unsigned char)ifr.ifr_hwaddr.sa_data[5]);  
  
    close(sd);  
      
    return 0;  
}  
  
  
// 获取本机ip  
int get_local_ip(const char *eth_inf, char *ip)  
{  
    int sd;  
    struct sockaddr_in sin;  
    struct ifreq ifr;  
  
    sd = socket(AF_INET, SOCK_DGRAM, 0);  
    if (-1 == sd)  
    {  
        printf("socket error: %s\n", strerror(errno));  
        return -1;        
    }  
  
    strncpy(ifr.ifr_name, eth_inf, IFNAMSIZ);  
    ifr.ifr_name[IFNAMSIZ - 1] = 0;  
      
    // if error: No such device  
    if (ioctl(sd, SIOCGIFADDR, &ifr) < 0)  
    {  
        printf("ioctl error: %s\n", strerror(errno));  
        close(sd);  
        return -1;  
    }  
  
    memcpy(&sin, &ifr.ifr_addr, sizeof(sin));  
    snprintf(ip, IP_SIZE, "%s", inet_ntoa(sin.sin_addr));  
  
    close(sd);  
    return 0;  
}

