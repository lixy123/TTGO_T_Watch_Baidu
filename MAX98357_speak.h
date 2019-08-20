#include "board_def.h"
#include "AudioFileSourceSPIFFS.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorMP3.h"
//#include "AudioOutputI2SNoDAC.h"
//百度语音生成的mp3 最后一汉字播放有问题
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"

//初始化I2S DAC
void init_speaker_i2s();

//播放 SPIFFS存储空间里的声音文件(mp3,wav文件均可)
//百度文字转声音的mp3最后一个字播放不出来，wav文件占用的空间大一些，但播放会完整
void playwav(String playfn);
