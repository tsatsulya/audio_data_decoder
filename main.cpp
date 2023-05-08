#include <iostream>
#include "audio_data_reader.hpp"

int main() {
	mp3_data* data = new mp3_data("/home/varvara/projects/mp3_data_reader/Tim Buckley - Once I Was.mp3");
	data->print();
	flac_data* data1 = new flac_data("/home/varvara/Music/02 - Light Waves - In The Space.flac");
	data1->print();
	return 0;
}