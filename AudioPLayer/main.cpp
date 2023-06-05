#include <iostream>
#include <vector>
#include <string>
#include <ctime>

// Track class to represent an audio recording
class Track {
private:
    std::string name;
    std::tm creationDate;
    int duration;

public:
    Track(const std::string& trackName, const std::tm& date, int trackDuration)
            : name(trackName), creationDate(date), duration(trackDuration) {}

    std::string getName() const {
        return name;
    }

    std::tm getCreationDate() const {
        return creationDate;
    }

    int getDuration() const {
        return duration;
    }
};

// Player class to simulate the operation of an audio player
class Player {
private:
    std::vector<Track> tracks;
    bool isPlaying;
    bool isPaused;
    int currentTrackIndex;

public:
    Player() : isPlaying(false), isPaused(false), currentTrackIndex(0) {}

    void addTrack(const Track& track) {
        tracks.push_back(track);
    }

    void play(const std::string& trackName) {
        if (!isPlaying) {
            for (int i = 0; i < tracks.size(); i++) {
                if (tracks[i].getName() == trackName) {
                    std::cout << "Now playing: " << tracks[i].getName() << std::endl;
                    std::cout << "Creation date: " << tracks[i].getCreationDate().tm_year + 1900 << "-" << tracks[i].getCreationDate().tm_mon + 1 << "-" << tracks[i].getCreationDate().tm_mday << std::endl;
                    std::cout << "Duration: " << tracks[i].getDuration() << " seconds" << std::endl;
                    isPlaying = true;
                    isPaused = false;
                    currentTrackIndex = i;
                    return;
                }
            }
            std::cout << "Track not found." << std::endl;
        }
    }

    void pause() {
        if (isPlaying && !isPaused) {
            std::cout << "Playback paused." << std::endl;
            isPaused = true;
        }
    }

    void next() {
        if (isPlaying) {
            currentTrackIndex = rand() % tracks.size();
            std::cout << "Skipping to next track: " << tracks[currentTrackIndex].getName() << std::endl;
            std::cout << "Creation date: " << tracks[currentTrackIndex].getCreationDate().tm_year + 1900 << "-" << tracks[currentTrackIndex].getCreationDate().tm_mon + 1 << "-" << tracks[currentTrackIndex].getCreationDate().tm_mday << std::endl;
            std::cout << "Duration: " << tracks[currentTrackIndex].getDuration() << " seconds" << std::endl;
            isPaused = false;
        }
    }

    void stop() {
        if (isPlaying) {
            std::cout << "Playback stopped for track: " << tracks[currentTrackIndex].getName() << std::endl;
            isPlaying = false;
            isPaused = false;
        }
    }

    void exit() {
        std::cout << "Exiting the program." << std::endl;
        isPlaying = false;
        isPaused = false;
    }
};

int main() {
    // Create some sample tracks
    std::tm date;
    date.tm_year = 2022 - 1900; // Year since 1900
    date.tm_mon = 0; // Month (0 - 11)
    date.tm_mday = 1; // Day of the month

    Track track1("Track 1", date, 180);
    Track track2("Track 2", date, 240);
    Track track3("Track 3", date, 200);

    // Create a player and add tracks to it
    Player player;
    player.addTrack(track1);
    player.addTrack(track2);
    player.addTrack(track3);

    std::string command;
    std::string trackName;

    // Main program loop
    while (true) {
        std::cout << "Enter a command ('play', 'pause', 'next', 'stop', 'exit'): ";
        std::cin >> command;

        if (command == "play") {
            std::cout << "Enter track name: ";
            std::cin.ignore();
            std::getline(std::cin, trackName);
            player.play(trackName);
        } else if (command == "pause") {
            player.pause();
        } else if (command == "next") {
            player.next();
        } else if (command == "stop") {
            player.stop();
        } else if (command == "exit") {
            player.exit();
            break;
        } else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }

    return 0;
}
