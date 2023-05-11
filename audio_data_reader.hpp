#include <iostream>
#include <map>
#include <vector>
#include <json/json.h>


struct track_info {
	std::string title = "unknown title";
	std::string artist = "unknown artist";
	std::string album = "unknown album";
	std::string composer = "unknown composer";
	std::string genre = "unknown genre";
	std::string date = "00_00_00";
	std::string performer = "unknown performer";
	std::string text = "";
	std::string comment = "empty comment";
	std::string year = "0000";
	std::string description = "";
};

class audio_data {
public:
	track_info info;

	void print_file_info();
	void print_track_info();
	void write(const char *);
	void read_from_json(Json::Value);
	// void set_file_path(const char* file_path) {file_path_ = file_path;}

	track_info get_info() { return info; }
	Json::Value get_json_info();
	// std::string get_file_path() {return file_path_;}
	audio_data();
	audio_data(Json::Value);

	virtual ~audio_data() {}
	// virtual audio_data* clone () const = 0;
	
protected:
	uint64_t hash_ = 0;
	std::string file_path_;
	std::vector<std::string> tags_ = {};
};

class mp3_data: public audio_data {
public:
	// mp3_data* clone () const override {
	// 	return new mp3_data{*this};
	// } 
	mp3_data();
	mp3_data(const char *);
};

class flac_data: public audio_data {
public:
	// flac_data* clone () const override {
	// 	return new flac_data{*this};
	// } 
	flac_data();
	flac_data(const char *);
};