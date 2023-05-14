#include <iostream>
#include "audio_data_reader.h"
#include <fstream>
#include <json/json.h>

void write(const char * path, std::vector<audio::audio_data*> &tracks) {
	std::ofstream file_id;
	file_id.open(path);
	Json::Value json_tracks;

	for (int i = 0; i < tracks.size(); i++) 
		json_tracks[i] = tracks[i]->get_json_info();

	Json::StyledWriter styledWriter;
	file_id << styledWriter.write(json_tracks);

	file_id.close();
}

int main() {
	audio::mp3_data* data = new audio::mp3_data("/home/varvara/projects/mp3_data_reader/Tim Buckley - Once I Was.mp3");
	data->print_file_info();
	audio::flac_data* data1 = new audio::flac_data("/home/varvara/Music/Tool/2019. Fear Inoculum (Digital Version) [none]/04. Invincible.flac");
	data1->print_file_info();

	// Json::Value track;
    // std::ifstream user_tracks("/home/varvara/projects/audio_data_reader/file.json", std::ifstream::binary);
    // user_tracks >> track;
	// std::cout << track;

	// audio_data* trck = new audio_data(track);
	// std::vector<audio_data*> tracks = {trck, trck, trck};
	// write("/home/varvara/projects/audio_data_reader/file1.json", tracks);
	// trck->print_track_info();

	return 0;
}