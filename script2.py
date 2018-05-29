#!/usr/bin/env python
import os
import sys
import sphinxbase as sb
import pocketsphinx as ps

def writesubs(str_out_file,duration):
	MODELDIR = '/usr/local/lib/python3.6/dist-packages/pocketsphinx/model'
	DATADIR = 'temp'

	# Create a decoder with certain model
	config = ps.Decoder.default_config()
	config.set_string('-hmm', os.path.join(MODELDIR, 'en-us'))
	config.set_string('-lm', os.path.join(MODELDIR, 'en-us.lm.bin'))
	config.set_string('-dict', os.path.join(MODELDIR, 'cmudict-en-us.dict'))
	#config.set_string('-sampling_rate','16000')
	#config.set_string('-buffer_size','1024')
	decoder = ps.Decoder(config)
	
	# Decode streaming data.
	decoder.start_utt()
	stream = open(os.path.join(DATADIR, 'outaudio.wav'), 'rb')
	while True:
	    buf = stream.read(1024)
	    if buf:
	        decoder.process_raw(buf, False, False)
	    else:
	        break
	decoder.end_utt()
	stream.close()
	#print('Best hypothesis segments:', [(seg.word, seg.start_frame, seg.end_frame) for seg in decoder.seg()])
	file=open("{}".format(str_out_file),"w")
	i=1
	t_0=999999
	t_n=0
	for seg in decoder.seg():
		if seg.start_frame<t_0:
			t_0 = seg.start_frame
		if seg.end_frame>t_n:
			t_n = seg.end_frame
	multiplier=int("{}".format(duration))/(t_n-t_0)
	for seg in decoder.seg():
		if seg.word=="<s>" or seg.word=="[SPEECH]" or seg.word=="</s>" or seg.word=="<sil>":	
			continue
		word=seg.word
		if word[len(word)-1]==')':
			word=word[:-3]
		file.write("{}\n".format(i))
		file.write("{:.3f}\n".format((seg.start_frame-t_0)*multiplier))
		file.write("{:.3f}\n".format((seg.end_frame-t_0)*multiplier))
		file.write("{}\n\n".format(word))
		i=i+1

writesubs(sys.argv[1],sys.argv[2])

