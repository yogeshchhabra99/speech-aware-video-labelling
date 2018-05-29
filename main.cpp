#include "write_subtitles.h"
#include <iostream>
#include <string>
#include "frames.h"

using namespace std;

int main()
{
	string video_file ="test_video2.mp4";	
	//cout << mystring <<endl;
	string text_file ="subs.txt";
	string duration="9";
	writesubs(video_file,text_file,duration);
	string no_of_frames="5";
	string time="6";
	string word="hello";
	string directory="/home/stylo/Pictures";
	double gap=0.2;
	//saveframes(video_file,no_of_frames,time,word,directory,gap);

	return 0;
}

//comment added by harshit
