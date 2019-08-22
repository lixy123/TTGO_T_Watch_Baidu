
#include "MAX98357_speak.h"

AudioGeneratorMP3 *mp3_player;
AudioGeneratorWAV *wav_player;
AudioFileSourceSPIFFS *audiofile;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;


void init_speaker_i2s()
{
  Serial.println("init_speak_i2s");
  
  //注意：i2s麦克风占用通道0, 此处必须用通道1， 否则冲突！
  out = new AudioOutputI2S(1);  
  
  // bool SetPinout(int bclkPin, int wclkPin, int doutPin);
  //配置i2s引脚
  out->SetPinout(TWATCH_DAC_IIS_BCK, TWATCH_DAC_IIS_WS,TWATCH_DAC_IIS_DOUT);
  out->SetGain(0.2); //调节音量大小 外接无源扬声器声音也很响亮
  mp3_player = new AudioGeneratorMP3();
  wav_player = new AudioGeneratorWAV();

  audiofile = new AudioFileSourceSPIFFS();
  id3 = new AudioFileSourceID3(audiofile);
}


//播放完声音文件后扬声器不断发出微小噪音
//解决方案：
//1.随后播放1秒钟的空白的mp3
//2.也可以给I2S输给一段连续的0x0,0x0的静音数据
void playwav(String playfn)
{
 
  Serial.println("begin playmusic " + playfn);

  String tmpfn ;
  tmpfn = playfn;

  //file = new AudioFileSourceSPIFFS( tmpfn.c_str());
  //id3 = new AudioFileSourceID3(file);
  audiofile->open(tmpfn.c_str());

  uint32_t all_starttime;
  uint32_t all_endtime;
  all_starttime = millis() / 1000;

  //mp3最后一个字播放不出来？
  if ( playfn.endsWith(".mp3"))
  {
    mp3_player->begin(id3, out);
    Serial.println("play mp3 start:" + playfn);
    while (true)
    {
      if (mp3_player->isRunning()) {
        if (!mp3_player->loop())
        {          
          mp3_player->stop();
        }
      }
      else
        break;
    }

    Serial.println("end playmusic mp3");
  }

  else if ( playfn.endsWith(".wav"))
  {
    
    wav_player->begin(id3, out);
    Serial.println("play wav start:" + playfn);
    while (true)
    {
      if (wav_player->isRunning()) {
        if (!wav_player->loop())
          wav_player->stop();
      }
      else
        break;
    }

    Serial.println("end playmusic wav");
  }
  else
    Serial.println("file can not play!");
  all_endtime = millis() / 1000;
  audiofile->close();
  Serial.println("play time=" + String(all_endtime - all_starttime) + "秒");
}
