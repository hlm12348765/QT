/*
 *
 * sound.cpp
 *
 *  Created on: 2017��3��22��
 *      Author: shenjj
 */
#include "common.h"

#include"asoundlib.h"
#include"sound.h"
#include<list>

using namespace std;


snd_pcm_t* handle; //PCI�豸���
struct WAV_HEADER
{
	char rld[4]; //riff ��־����
	int rLen;
	char wld[4]; //��ʽ���ͣ�wave��
	char fld[4]; //"fmt"

	int fLen; //sizeof(wave format matex)

	short wFormatTag; //�����ʽ
	short wChannels; //������
	int nSamplesPersec; //����Ƶ��
	int nAvgBitsPerSample; //WAVE�ļ�������С
	short wBlockAlign; //�����
	short wBitsPerSample; //WAVE�ļ�������С

	char dld[4]; //��data��
	int wSampleLength; //��Ƶ���ݵĴ�С

} wav_header;

int set_pcm_play(FILE *fp)
{
	int rc = 0;
	int ret;
	int size;

	snd_pcm_hw_params_t* params; //Ӳ����Ϣ��PCM������
	unsigned int val;
	int dir = 0;
	snd_pcm_uframes_t frames;
	char *buffer;
	int channels = wav_header.wChannels;
	int frequency = wav_header.nSamplesPersec;
	int bit = wav_header.wBitsPerSample;
	int datablock = wav_header.wBlockAlign;

	snd_pcm_hw_params_alloca(&params); //����params�ṹ��
	if (rc < 0)
	{
		perror("\nsnd_pcm_hw_params_alloca:");
		exit(1);
	}
	rc = snd_pcm_hw_params_any(handle, params); //��ʼ��params
	if (rc < 0)
	{
		perror("\nsnd_pcm_hw_params_any:");
		exit(1);
	}
	rc = snd_pcm_hw_params_set_access(handle, params,
			SND_PCM_ACCESS_RW_INTERLEAVED); //��ʼ������Ȩ��
	if (rc < 0)
	{
		perror("\nsed_pcm_hw_set_access:");
		exit(1);

	}

	//����λ��
	switch (bit / 8)
	{
	case 1:
		snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_U8);
		break;
	case 2:
		snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);
		break;
	case 3:
		snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S24_LE);
		break;

	}
	rc = snd_pcm_hw_params_set_channels(handle, params, channels); //��������,1��ʾ����>����2��ʾ������
	if (rc < 0)
	{
		perror("\nsnd_pcm_hw_params_set_channels:");
		exit(1);
	}
	val = frequency;
	rc = snd_pcm_hw_params_set_rate_near(handle, params, &val, &dir); //����>Ƶ��
	if (rc < 0)
	{
		perror("\nsnd_pcm_hw_params_set_rate_near:");
		exit(1);
	}

	rc = snd_pcm_hw_params(handle, params);
	if (rc < 0)
	{
		perror("\nsnd_pcm_hw_params: ");
		exit(1);
	}

	rc = snd_pcm_hw_params_get_period_size(params, &frames, &dir); /*��ȡ����
	 ����*/
	//      printf("frame=%ld\n",frames);
	if (rc < 0)
	{
		perror("\nsnd_pcm_hw_params_get_period_size:");
		exit(1);
	}

	//       size = frames * datablock; /*4 �������ݿ쳤��*/
	size = frames * datablock; /*4 �������ݿ쳤��*/
	//       printf("datablock=%d",datablock);
	buffer = (char*) malloc(size);
	fseek(fp, 58, SEEK_SET); //��λ������������
	while (1)
	{
		memset(buffer, 0, sizeof(buffer));
		ret = fread(buffer, 1, size, fp);
		if (ret == 0)
		{
			//       printf("����д�����\n");
			break;
		}
		else if (ret != size)
		{
			break;
		}
		// д��Ƶ���ݵ�PCM�豸
		ret = snd_pcm_writei(handle, buffer, frames);
		while (ret < 0)
		{
			usleep(2000);
			if (ret == -EPIPE)
			{

				//fprintf(stderr, "underrun occurred\n");
				//���Ӳ���������ã�ʹ�豸׼����
				snd_pcm_prepare(handle);
			}
			else if (ret < 0)
			{
				fprintf(stderr, "error from writei: %s\n", snd_strerror(ret));
			}
		}
	}
	//DPRINTS("ok");
	snd_pcm_drain(handle);
	snd_pcm_close(handle);
	free(buffer);
	fclose(fp);
	return 0;
}

void speak_aud(const char *argv)
{

	int nread, rc;
	FILE *fp;
	fp = fopen(argv, "rb");
	if (fp == NULL)
	{
		perror("open file failed:\n");
		exit(1);
	}
	nread = fread(&wav_header, 1, sizeof(wav_header), fp);
	rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
	if (rc < 0)
	{
		perror("\nopen PCM device failed:");
		return;
	}

	set_pcm_play(fp);

}


unsigned int sound_init(void)       //����
{
	unsigned int rc;
	rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);
	if (rc < 0)
	{
		perror("\nopen PCM device failed:");
		return (1);
	}
	return (1);

}

#if 1
//using namespace std;
list<const char*> sound_lcd;
list<const char*> lcd_sound;

void speak_th()
{
	if (!sound_lcd.empty())
	{
		speak_aud(sound_lcd.front());
		sound_lcd.pop_front();	 
	}

}
#endif
