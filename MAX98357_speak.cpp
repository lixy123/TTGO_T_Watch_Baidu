#include "MAX98357_speak.h"

AudioGeneratorMP3 *mp3_player;
AudioGeneratorWAV *wav_player;
AudioFileSourceSPIFFS *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;


void init_speak_i2s()
{
  Serial.println("init_speak_i2s");
  out = new AudioOutputI2S();
  // bool SetPinout(int bclkPin, int wclkPin, int doutPin);
  //配置i2s引脚
  out->SetPinout(26, 25,33);
  //out->SetGain(0.7); //调节音量大小
  mp3_player = new AudioGeneratorMP3();
  wav_player = new AudioGeneratorWAV();
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

  file = new AudioFileSourceSPIFFS( tmpfn.c_str());
  id3 = new AudioFileSourceID3(file);

  uint32_t all_starttime;
  uint32_t all_endtime;
  all_starttime = millis() / 1000;

  if ( playfn.endsWith(".mp3"))
  {
    mp3_player->begin(id3, out);

    Serial.println("play start " + playfn);
    //delay(100);
    while (true)
    {
      if (mp3_player->isRunning()) {
        if (!mp3_player->loop())
          mp3_player->stop();
      }
      else
        break;
    }
    Serial.println("end playmusic mp3");
  }

  else if ( playfn.endsWith(".wav"))
  {
    Serial.println("wav_player->begin ");
    wav_player->begin(id3, out);
    //delay(100);
    Serial.println("play start " + playfn);
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
  Serial.println("play time=" + String(all_endtime - all_starttime) + "秒");
}
