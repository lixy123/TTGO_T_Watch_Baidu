#include "AudioFileSourceSPIFFS.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorMP3.h"
//#include "AudioOutputI2SNoDAC.h"
//百度语音生成的mp3 最后一汉字播放有问题
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"

//初始化I2S DAC
void init_speak_i2s();

//播放 SPIFFS存储空间里的声音文件(mp3,wav文件均可)
//百度文字转声音的mp3文件最后一个字播放不出来，虽然wav文件占用的空间大一些，但最终选择用wav文件
void playwav(String playfn);
