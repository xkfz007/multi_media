#! /bin/sh
#��򵥵Ļ���FFmpeg��AVFilter���ӣ�����ˮӡ�� ----MinGW�����б���
#Simplest FFmpeg AVfilter Example (Watermark)----Compile in MinGW 
#
#������ Lei Xiaohua
#leixiaohua1020@126.com
#�й���ý��ѧ/���ֵ��Ӽ���
#Communication University of China / Digital TV Technology
#http://blog.csdn.net/leixiaohua1020
#
#compile
g++ simplest_ffmpeg_video_filter.cpp -g -o simplest_ffmpeg_video_filter.exe \
-I /usr/local/include -L /usr/local/lib \
-lmingw32 -lSDLmain -lSDL -lavformat -lavcodec -lavutil -lavfilter -lswscale
