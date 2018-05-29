#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>

using namespace std;

int writesubs(string video_file_name,string out_file_name,string duration)
{
	//if(setenv("GOOGLE_APPLICATION_CREDENTIALS","/home/stylo/Downloads/key.json",1)) return 0; // set the environmentv variable GOOGLE_APPLICATION_CREDENTIALS change the path to the path of your key
	string str="ffmpeg -i ";
	str=str + video_file_name +" -ar 16000 -ac 1 temp/outaudio.wav";  //output audio with 40000 sampling rate and single channel
	if(system(str.c_str())) return 0;			//calling the ffmpeg command
	string str2="python3 script2.py " ;
	str2=str2 + out_file_name;
	str2=str2+" ";
	str2 = str2+duration;				
	if(system(str2.c_str())) return 0;						//calling the python script using system command
	string str3= "rm -r -f temp/outaudio.wav";
	//if(system(str3.c_str())) return 0;
	return 1;
	
} 
	//if command runs system() returns 0 else something else
