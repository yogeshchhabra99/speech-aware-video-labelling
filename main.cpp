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
	//writesubs(video_file,text_file);
	string no_of_frames="5";
	string time="6";
	string word="hello";
	saveframes(video_file,no_of_frames,time,word);

	return 0;
}

//comment added by harshit
