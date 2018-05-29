#include<iostream>
#include<stdlib.h>
#include<string>
#include<string.h>

using namespace std;

int saveframes(string video_file_path,string no_of_frames,string time,string word,string directory,double gap_between_frames)
{
	int a=1/gap_between_frames;
	string s=to_string(a);
	string str="ffmpeg -i ";
	str=str + video_file_path + " -ss ";
	str=str + "00:00:" + time + " -vframes ";
	str=str+ no_of_frames + " -vf fps=1"+s+" "+directory+"/outimg_:" + word + "_" + time + "seconds_%d.jpg";
	//cout << str;
	system(str.c_str());
	return 0;
}

// I am assuming that the directory string has a / in the end if not then insert.
