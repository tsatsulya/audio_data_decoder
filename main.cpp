#include <iostream>
#include "audio_data_reader.hpp"
#include <fstream>
#include <json/json.h>

int main() {
	mp3_data* data = new mp3_data("/home/varvara/projects/mp3_data_reader/Tim Buckley - Once I Was.mp3");
	data->print_file_info();
	flac_data* data1 = new flac_data("/home/varvara/Music/02 - Light Waves - In The Space.flac");
	data1->print_file_info();

	Json::Value track;
    std::ifstream user_tracks("/home/varvara/projects/audio_data_reader/file.json", std::ifstream::binary);
    user_tracks >> track;
	std::cout << track;

	audio_data* trck = new audio_data(track);
	trck->print_track_info();

	audio_data r;
	r.print_track_info();
	return 0;
}