#include "videoplaylist.h"

VideoPlaylist::VideoPlaylist(std::string name) {
	Name = name;
}

std::string VideoPlaylist::getName() { return Name; }

std::vector<std::string> VideoPlaylist::getVideos() { return videos; }

bool VideoPlaylist::findVideo(std::string videoId) {
	bool found = false;
	std::string current;
	for (int i = 0; i < videos.size() ; i++) {
		current = videos.at(i);
		if (current.compare(videoId) == 0) {
			found = true;
			break;
		}
	}
	return found;
}

bool VideoPlaylist::addToPlaylist(std::string video) {
	if (!findVideo(video)) {
		videos.push_back(video);
		return true;
	}
	else {
		std::cout << "Cannot add video to " + Name + ": Video already added";
		return false;
	}
}

bool VideoPlaylist::removeFromPlaylist(std::string video) {
	if (findVideo(video)) {
		std::remove(videos.begin(), videos.end(), video);
		return true;
	}
	else {
		std::cout << "Cannot remove video from " + Name
			+ ": Video is not in playlist";
		return false;
	}
}
void VideoPlaylist::clearPlaylist() {
	videos.clear();
	std::cout << "Successfully removed all videos from " + Name;
}