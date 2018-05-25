#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>

using namespace std;

int writesubs(const char* video_file_name,const char* out_file_name)
{
	setenv("GOOGLE_APPLICATION_CREDENTIALS","/home/stylo/Downloads/key.json",1); // set the environmentv variable GOOGLE_APPLICATION_CREDENTIALS change the path to the path of your key
	string str="ffmpeg -i ";
	str=str + video_file_name +" -ar 40000 -ac 1 resources/outaudio.wav";  //output audio with 40000 sampling rate and single channel
	int i=system(str.c_str());			//calling the ffmpeg command
	string str2="python script.py " ;
	str2=str2 + out_file_name;				
	system(str2.c_str());						//calling the python script using system command
	string str3= "rm -r -f resources/outaudio.wav";
	system(str3.c_str());
	return 0;
	
} 
	//if command runs system() returns 0 else something else
