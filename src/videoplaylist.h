#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

/** A class used to represent a Playlist */

class VideoPlaylist {
private:
	std::string Name;
	bool findVideo(std::string videoId);
	std::vector<std::string> videos;

public:
	VideoPlaylist(std::string name);
	std::string getName();
	std::vector<std::string> getVideos();
	bool addToPlaylist(std::string video);
	bool removeFromPlaylist(std::string video);
	void clearPlaylist();
	bool operator==(const VideoPlaylist& v) const {
		if (this->Name.compare(v.Name)) {
			return 1;
		}
		else {
			return 0;
		}
	}
};
