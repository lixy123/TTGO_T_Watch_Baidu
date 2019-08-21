用 TTGO_T_Watch_Baidu  进行图灵语音对话

一.基本原理 <br/>
          &nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;之前在网上看到这篇文章, https://www.cnblogs.com/robertx/p/10719302.html 介绍了python实现图灵语音对话, 看完后比较感兴趣,
       但是运行环境至少是linux系统或windows系统, 运行成本较高. 网上查到esp32芯片,发现通过附加廉价的录音及播放附件也能实现相同的功能,就业余时间尝试写了一些代码实现了相关功能. 
       正好芯元研发团队推出TTGO_T_Watch, 硬件主体是ESP32芯片, 后继又集成了录音及播放附件, 花了几天时间把原先的功能移植到了此硬件上. 
       <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;图灵语音对话并不需要显示屏,原先的想法是要求小巧,有外部供电能力,最好能做成普通充电头大小直插到充电宝或墙上. 
       用TTGO_T_Watch有些浪费硬件资源,体积有优势,但是至少好过我直接用ESP32自已焊接麦克风.
       <br/>
       &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;感谢芯元公司的技术支持和硬件赞助.

二.软件说明 <br/>
      &nbsp;&nbsp;&nbsp;&nbsp;上一版本 https://github.com/lixy123/TTGO_T_Watch_Baidu_Rec
      没有声音输出功能， 这版本增加了声音输出.
