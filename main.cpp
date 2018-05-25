#include "write_subtitles.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string video_file ="test_video2.mp4";	
	//cout << mystring <<endl;
	string text_file ="subs.txt";
	writesubs(video_file.c_str(),text_file.c_str());
	return 0;
}

//comment added by harshit
