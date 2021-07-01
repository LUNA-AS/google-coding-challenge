#include "playlistmanager.h"

bool PlaylistManager::playlistExists(std::string playlistName) {
	bool found = false;
	std::string temp;
	for (int i = 0; i < playlists.size(); i++) {
		temp = playlists.at(i).getName();
		if (temp.compare(playlistName) == 0) {
			found = true;
		}
	}
	return found;
}

VideoPlaylist PlaylistManager::getPlaylist(std::string name){
	unsigned int index;
	for (int i = 0; i < playlists.size(); i++) {
		if (name.compare(playlists.at(i).getName()) == 0) {
			index = i;
			break;
		}
	}
	return playlists.at(index);
}

bool PlaylistManager::createPlaylist(std::string playlistName) {
	bool success = false;
	if (!playlistExists(playlistName)) {
		VideoPlaylist newPlaylist = VideoPlaylist(playlistName);
		playlists.push_back(newPlaylist);
		std::cout << "Successfully created new playlist: " << playlistName << std::endl;
		success = true;
	}
	else if(playlistExists(playlistName)){
		std::cout << "Cannot create playlist: A playlist with the same name already exists" << std::endl;
	}
	return success;
}

void PlaylistManager::showPlaylists() {
	for (int i = 0; i < playlists.size(); i++) {
		std::cout << playlists.at(i).getName() << std::endl;
	}
	if (playlists.size() < 1) {
		std::cout << "No playlists exist yet" << std::endl;
	}
}

std::vector<std::string> PlaylistManager::getPlaylistContent(std::string playlistName) {
	std::vector<std::string> videos;
	if (playlistExists(playlistName)) {
		VideoPlaylist result = getPlaylist(playlistName);
		videos = result.getVideos();
		
	}
	else {
		std::cout << "Cannot show playlist " + playlistName + ": Playlit does not exist" << std::endl;
	}
	return videos;
}

bool PlaylistManager::addToPlaylist(std::string playlistName, std::string videoId) {
	if (playlistExists(playlistName)) {
		VideoPlaylist result = getPlaylist(playlistName);
		return result.addToPlaylist(videoId);
	}
	else {
		std::cout << "Cannot add video to " + playlistName
			+ ": Playlist does not exist"<< std::endl;
		return false;
	}
}

void PlaylistManager::deletePlaylist(std::string playlistName) {
	if (playlistExists(playlistName)) {
		std::remove(playlists.begin(), playlists.end(), playlistName);
		std::cout << "Deleted playlist: " + playlistName << std::endl;
	}
	else {
		std::cout << "Cannot delete " + playlistName
			+ " : Playlist does not exist" << std::endl;
	}
}

bool PlaylistManager::removeFromPlaylist(std::string playlistName, std::string videoId) {
	if (playlistExists(playlistName)) {
		VideoPlaylist result = getPlaylist(playlistName);
		return result.removeFromPlaylist(videoId);
	}
	else {
		std::cout << "Cannot remove video from " + playlistName
			+ ": Playlist does not exist";
		return false;
	}
}

void PlaylistManager::clearPlaylist(std::string playlistName) {
	if (playlistExists(playlistName)) {
		VideoPlaylist result = getPlaylist(playlistName);
		result.clearPlaylist();
	}
	else {
		std::cout<<"Cannot clear " + playlistName + ": Playlist does not exist" << std::endl;
	}
}