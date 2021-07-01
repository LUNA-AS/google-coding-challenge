#include "videoplayer.h"

#include <iostream>

void VideoPlayer::numberOfVideos() {
  std::cout << mVideoLibrary.getVideos().size() << " videos in the library"
            << std::endl;
}

void VideoPlayer::showAllVideos() {
    std::vector <Video> videos = mVideoLibrary.getVideos();
    std::vector<std::string> results;
    std::string result;
    std::string videoTitle;
    std::string videoId ;
    std::vector<std::string> videoTags;
    std::string tagsString ;
    for (int i = 0; i < videos.size(); i++) {
        videoTitle = videos.at(i).getTitle();
        videoId = "(" + videos.at(i).getVideoId() + ")";
        tagsString = videos.at(i).getTagsString();
        result = videoTitle + videoId + tagsString ;
        results.push_back(result);
        tagsString = "";
    }
    std::sort(results.begin(), results.end());
    for (int i = 0; i < results.size(); i++) {
        std::cout << results.at(i) << std::endl;
    }
}

void VideoPlayer::playVideo(const std::string& videoId) {
    if (mVideoLibrary.getVideo(videoId, false)) {
        playerPaused = false;
        Video requestedVid = *mVideoLibrary.getVideo(videoId, false);
        std::string title = requestedVid.getTitle();
        if (mVideoLibrary.getVideo(nowPlaying, false)) {
            std::string stopMessage = "Stopping video: " + mVideoLibrary.getVideo(nowPlaying)->getTitle() ;
            std::cout << stopMessage << std::endl;
        }
        std::cout << "Playing video: " << title << std::endl;
        nowPlaying = requestedVid.getVideoId();
    }
    else {
        std::cout << "Cannot play video: Video does not exist";
    }
}

void VideoPlayer::stopVideo() {
    if (mVideoLibrary.getVideo(nowPlaying,false)) {
        std::cout << "Stopping video: " << mVideoLibrary.getVideo(nowPlaying, false)->getTitle() << std::endl;
        nowPlaying = "";
        playerPaused = false;
    }
    else {
        std::cout << "Cannot stop video: No video is currently playing" << std::endl;
    }
}

void VideoPlayer::playRandomVideo() {
    std::vector<Video> videos = mVideoLibrary.getVideos();
    srand(time(NULL));
    int randomIndex = rand() % videos.size();
    playVideo(videos.at(randomIndex).getVideoId());
}

void VideoPlayer::pauseVideo() {
    if (mVideoLibrary.getVideo(nowPlaying, false)) {
        if (!playerPaused) {
            playerPaused = true;
            std::cout << "Pausing video: "
                + mVideoLibrary.getVideo(nowPlaying, false)->getTitle() 
                << std::endl;
        }
        else {
            std::cout << "Video already paused: " 
                + mVideoLibrary.getVideo(nowPlaying, false)->getTitle()
                << std::endl;
        }
    }
    else {
        std::cout << "Cannot pause video: No video is currently playing" << std::endl;
    }
}

void VideoPlayer::continueVideo() {
    if (mVideoLibrary.getVideo(nowPlaying, false)) {
        if (playerPaused) {
            playerPaused = false;
            std::cout << "Continuing video: "
                + mVideoLibrary.getVideo(nowPlaying, false)->getTitle()
                << std::endl;
        }
        else {
            std::cout << "Cannot continue video: Video is not paused" << std::endl;
        }
    }
    else {
        std::cout << "Cannot continue video: No video is currently playing" << std::endl;
    }
}

void VideoPlayer::showPlaying() {
    if (mVideoLibrary.getVideo(nowPlaying, false)) {
        Video currentVid = *mVideoLibrary.getVideo(nowPlaying, false);
        std::string paused = "";
        if (playerPaused) {
            paused = " - PAUSED";
        }
        std::cout << "Currently playing: " 
            + currentVid.getTitle()
            + " (" + currentVid.getVideoId() + ") "
            + currentVid.getTagsString() + paused<< std::endl;
    }
    else {
        std::cout << "No video is currently playing" ;
    }
}

void VideoPlayer::createPlaylist(const std::string& playlistName) {
    mPlaylistManager.createPlaylist(playlistName);
}

void VideoPlayer::addVideoToPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
    if (mVideoLibrary.getVideo(videoId, false)) {
        if (mPlaylistManager.addToPlaylist(playlistName, videoId)) {
            std::cout << "Added video to " + playlistName 
                + ": " + mVideoLibrary.getVideo(videoId,false)->getTitle() ;
        }
    }
    else {
        std::cout << "Cannot add video to " + playlistName 
            + ": Video does not exist" << std::endl;
    }
    
}

void VideoPlayer::showAllPlaylists() {
    mPlaylistManager.showPlaylists();
}

void VideoPlayer::showPlaylist(const std::string& playlistName) {
    std::vector<std::string> playlistVids = mPlaylistManager.getPlaylistContent(playlistName);
    for (int i = 0; i < playlistVids.size() ; i++) {
        std::cout << playlistVids.at(i) << std::endl;
    }
    if (playlistVids.size() ==0 ) {
        std::cout << "No videos here yet";
    }
}

void VideoPlayer::removeFromPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
    if (mPlaylistManager.removeFromPlaylist(playlistName, videoId)) {
        std::cout << "Removed video from " + playlistName
            + ": " + mVideoLibrary.getVideo(videoId)->getTitle() << std::endl;
    }
}

void VideoPlayer::clearPlaylist(const std::string& playlistName) {
    mPlaylistManager.clearPlaylist(playlistName);
}

void VideoPlayer::deletePlaylist(const std::string& playlistName) {
    mPlaylistManager.deletePlaylist(playlistName);
}

void VideoPlayer::searchVideos(const std::string& searchTerm) {
  std::cout << "searchVideos needs implementation" << std::endl;
}

void VideoPlayer::searchVideosWithTag(const std::string& videoTag) {
  std::cout << "searchVideosWithTag needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId, const std::string& reason) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::allowVideo(const std::string& videoId) {
  std::cout << "allowVideo needs implementation" << std::endl;
}
