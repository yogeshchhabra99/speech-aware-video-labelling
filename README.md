# speech-aware-video-labelling
We are using qt, ffmpeg and speech to text api to create a tool that takes video as input and labels it according to its audio part 
-------------------------------------------
write_subtitles.h
------------------------------------------
this header file has the function writesubs(const char pointer to video file path,constant char pointer to output txt file path)
whch calls the script which uses google cloud api for speech to text, see below for the key. The video file is onverted to audio using ffmpeg system command and stores the audio with 40000 sampling rate in the resources folder to be used by the python script. Then the script writes the text in subtitles format in the selected output text file.


------
api key
-----
contact chhabra99yogesh@gmail.com if u need a user key or setup your own, steps given on google cloud are quite easy to understand
> Link for setting up google cloud environment : https://cloud.google.com/sdk/docs/#deb



