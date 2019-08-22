用 TTGO_T_Watch_Baidu  进行图灵语音对话

一.基本原理 <br/>
&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;之前在网上看到这篇文章, https://www.cnblogs.com/robertx/p/10719302.html 介绍了python实现图灵语音对话, 看完后比较感兴趣,但是运行环境至少是linux系统或windows系统, 运行成本较高. 网上查到esp32芯片,发现通过附加廉价的录音及播放附件也能实现相同的功能,就业余时间尝试写了一些代码实现了相关功能. 正好芯元研发团队推出TTGO_T_Watch, 硬件主体是ESP32芯片, 后继又集成了录音及播放附件, 花了几天时间把原先的功能移植到了此硬件上. 
<br/>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;图灵语音对话并不需要显示屏,原先的想法是要求小巧,有外部供电能力,最好能做成普通充电头大小直插到充电宝或墙上. 
用TTGO_T_Watch有些浪费硬件资源.  TTGO_T_Watch硬件集成度好,体积有优势,好过我自个手工用ESP32焊接麦克风和喇叭.
<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;感谢芯元公司的技术支持和硬件赞助.

二.软件说明 <br/>
&nbsp;&nbsp;&nbsp;&nbsp;上一版本 https://github.com/lixy123/TTGO_T_Watch_Baidu_Rec
没有声音输出功能， 这版本增加了声音输出.

三.效果演示 <br/>

毕竟esp32是廉价wifi芯片，处理声音文件上传下载速度较慢，且有一定概率失败，不能保证稳定性，不太适合做商业产品的语音应用. 实际测试,语音转文字有2-3%概率网络中断出错，文字转声音有2-5%的概率网络中断出错. 相同网络条件下对比测试，在树莓派上进行百度语音与文字互相转换时几乎从不出错，且速度大部分情况下比esp32快。


<p>
<img src= 'https://raw.githubusercontent.com/lixy123/TTGO_T_Watch_Baidu/master/t-watch.jpg' />
</p>
演示视频地址
   https://github.com/lixy123/TTGO_T_Watch_Baidu/raw/master/VID_20190821.avi
