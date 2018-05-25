import io
import os
import sys

# Imports the Google Cloud client library
from google.cloud import speech
from google.cloud.speech import enums
from google.cloud.speech import types


def writesubs( str_out_file):
	# Instantiates a client
	client = speech.SpeechClient()

	# The name of the audio file to transcribe
	file_name = os.path.join(
	    os.path.dirname(__file__),
	    'temp',
	    'outaudio.wav')

	# Loads the audio into memory
	with io.open(file_name, 'rb') as audio_file:
	    content = audio_file.read()
	    audio = types.RecognitionAudio(content=content)

	config = types.RecognitionConfig(
	    encoding=enums.RecognitionConfig.AudioEncoding.LINEAR16,
	    sample_rate_hertz=40000,		#take care of the sampling rate
	    language_code='en-US',
	    enable_word_time_offsets=True)

	# Detects speech in the audio file
	operation = client.long_running_recognize(config, audio)

	print('Waiting for operation to complete...')
	result = operation.result(timeout=90)

	file=open("{}".format(str_out_file),"w")

	for result in result.results:
	       alternative = result.alternatives[0]
	  #      print(u'Transcript: {}'.format(alternative.transcript))
	   #     print('Confidence: {}'.format(alternative.confidence))
	i=1
	for word_info in alternative.words:
	            word = word_info.word
	            start_time = word_info.start_time
	            end_time = word_info.end_time
	            #print('Word: {}, start_time: {}, end_time: {}'.format(
	             #   word,
	              #  start_time.seconds + start_time.nanos * 1e-9,
	               # end_time.seconds + end_time.nanos * 1e-9))
	            file.write("{}\n".format(i))
	            file.write("{}\n{}\n".format(start_time.seconds + start_time.nanos * 1e-9,
	                end_time.seconds + end_time.nanos * 1e-9))
	            file.write("{}\n\n".format(word))
	            i=i+1

writesubs(sys.argv[1])


