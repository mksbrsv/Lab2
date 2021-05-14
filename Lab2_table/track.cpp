#include "track.h"

track::track(std::string&& name, std::string&& poster, std::string&& music_file) :
	m_name(std::move(name)) {
	m_poster = cv::imread(poster);
	if (!m_music.loadFromFile(music_file)) 
		throw std::logic_error("Can't open music file");
}

void track::show() const {
	cv::imshow(m_name, m_poster);
	cv::waitKey();
}

void track::play() const {
	sf::Sound sound;
	sound.setBuffer(m_music);
	sound.play();
	cv::waitKey(m_music.getDuration().asMilliseconds());
}

void track::set_name(std::string &&name) { m_name = name; }

void track::set_poster(std::string &&poster) { m_poster = cv::imread(poster); }

void track::set_music(std::string &&music) {
  if (!m_music.loadFromFile(music))
    throw std::logic_error("Can't open music file");
}

std::ostream& operator<<(std::ostream& out, const track& track) {
	out << track.m_name;
	return out;
}
