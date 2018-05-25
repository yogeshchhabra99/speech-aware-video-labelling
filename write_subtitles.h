#include<iostream.h>
#include<stdlib.h>
#include<string.h>

void writesubs(const char* video_file_name,const char* out_file_name)
	string str="ffmpeg -i ";
	str=str + video_file_name +" -ar 40000 resources/outaudio.wav";  //output audio with 40000 sampling rate
	system(str.c_str());						//calling the ffmpeg command
	str2="python script.py "+out_file_name;				
	system(str2.c_str());						//calling the python script using system command 
	
