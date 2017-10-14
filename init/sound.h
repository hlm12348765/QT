/*
 *
 * sound.h
 *
 *  Created on: 2017Äê3ÔÂ22ÈÕ
 *      Author: shenjj
 */

#ifndef SOUND_H_
#define SOUND_H_
#ifdef __cplusplus

extern "C" {

#endif

unsigned int sound_init(void);       
void speak_aud(const char *argv);
void speak(unsigned char sp);
void speak_th();
void lcdshow_order();

#ifdef __cplusplus

}
#endif

#endif /* SOUND1_H_ */
