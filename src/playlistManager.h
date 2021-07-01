#pragma once
#include <iostream>
#include "videoplaylist.h"
#include "helper.h"

/*
	A class to hold a list of playlists created and interact with each of them individually.
*/

class PlaylistManager
{
public:
	
	bool createPlaylist(std::string playlistName);
	
	void showPlaylists();

	std::vector<std::string> getPlaylistContent(std::string playlistName);

	bool addToPlaylist(std::string playlistName, std::string videoId);

	void deletePlaylist(std::string playlistName);

	bool removeFromPlaylist(std::string playlistName, std::string videoId);

	void clearPlaylist(std::string playlistName);
private:

	bool playlistExists(std::string playlistName);

	VideoPlaylist getPlaylist(std::string name);

	std::vector<VideoPlaylist> playlists;
};

