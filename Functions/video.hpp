#ifndef VIDEO_HPP_INCLUDED
#define VIDEO_HPP_INCLUDED

void Game::video(std::string videoName)
{
    sftheora::Video mVideo;
    mVideo.loadClip("Media/" + videoName);
}


#endif // VIDEO_HPP_INCLUDED
