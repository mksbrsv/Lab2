#ifndef TRACK_H
#define TRACK_H
#include <opencv2/opencv.hpp>
#include <SFML/Audio.hpp>
class track {
public:
	track() = default;
	track(std::string&& name, std::string&& poster, std::string&& music_file);
	void show() const;
	void play() const;
	friend std::ostream& operator<<(std::ostream& out, const track& track);
private:
	std::string m_name;
	cv::Mat m_poster;
	sf::SoundBuffer m_music;
};
#endif

