#include <iostream>

class audio_data {
public:
	virtual void print();
	virtual ~audio_data() {}

	virtual audio_data* clone () const = 0;
	uint64_t hash = 0;
	std::string title = "unknown title";
	std::string artist = "unknown artist";
	std::string album = "unknown album";
	std::string comment = "empty comment";
	std::string date = "00_00_00";
	std::string year = "0000";
	std::string genre = "unknown genre";
};

class mp3_data: public audio_data {
public:
	mp3_data* clone () const override {
		return new mp3_data{*this};
	} 
	mp3_data();
	mp3_data(const char *);
};

class flac_data: public audio_data {
public:
	flac_data* clone () const override {
		return new flac_data{*this};
	} 
	flac_data();
	flac_data(const char *);	
};