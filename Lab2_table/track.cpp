#include "track.h"

track::track(std::string&& name, std::string&& poster, std::string&& music_file) :
	m_name(std::move(name)){
	m_poster = cv::imread(poster);
	if (!m_music.loadFromFile(music_file)) 
		throw std::logic_error("Can't open music file");
}

void track::show() const {
	cv::imshow(m_name, m_poster);
}

void track::play() const {
	sf::Sound sound;
	sound.setBuffer(m_music);
	sound.play();
}

std::ostream& operator<<(std::ostream& out, const track& track) {
	out << track.m_name;
	return out;
}
