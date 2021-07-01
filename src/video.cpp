#include "video.h"

#include <iostream>
#include <utility>
#include <vector>

Video::Video(std::string&& title, std::string&& videoId,
             std::vector<std::string>&& tags) :
  mTitle(std::move(title)),
  mVideoId(std::move(videoId)),
  mTags(std::move(tags)) {
}

const std::string& Video::getTitle() const { return mTitle; }

const std::string& Video::getVideoId() const { return mVideoId; }

const std::vector<std::string>& Video::getTags() const { return mTags; }

std::string  Video::getTagsString() {
    std::string result = "[";
    for (int i = 0; i < mTags.size(); i++) {
        result += mTags.at(i);
        // Check ensure that the tag is not the last in the list to add a "," or "]"
        if (i < mTags.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}