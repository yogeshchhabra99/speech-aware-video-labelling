#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>

using namespace std;

int saveframes(string video_file_path,string no_of_frames,string time,string word)
{
	string str="ffmpeg -i ";
	str=str + video_file_path + " -ss ";
	str=str + "00:00:" + time + " -vframes ";
	str=str+ no_of_frames + " -vf fps=10 outimg_:" + word + "_" + time + "seconds_%d.jpg";
	//cout << str;
	system(str.c_str());
	return 0;
}
