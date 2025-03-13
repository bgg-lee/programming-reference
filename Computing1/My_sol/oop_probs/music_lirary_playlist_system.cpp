/*
You are building a Music Library system. Each track can be of different genres (e.g., Rock, Pop, Jazz), and each track can have additional attributes depending on its genre. You also need a class to manage a playlist or a library of tracks, performing operations like adding, removing, and listing all tracks.
Core Requirements:
Abstract Base Class: MusicTrack
    Data: track ID (int), title (std::string), duration (in seconds), plus a boolean for “is playing” or “is paused.”
    Pure virtual function void play(), void stop(), and maybe std::string getGenreName() const = 0;
    Virtual destructor.
    Possibly a virtual function void printInfo() const; to show track ID, title, duration, playing state.
Derived Classes (at least 2–3):
    RockTrack: might have a bandName property, or a loudnessFactor to illustrate an extra field.
    PopTrack: might have a danceability rating, or producerName.
    JazzTrack: might have a soloistName, or a complexity rating.
    Each must override:
    play(): sets “is playing” to true, maybe prints “Playing Rock track: ...”
    stop(): sets “is playing” to false
    getGenreName(): returns "Rock", "Pop", "Jazz", etc.
    Possibly override printInfo() to show genre-specific data.
Playlist / LibraryManager:
    Class with a container std::vector<std::unique_ptr<MusicTrack>> tracks;
    void addTrack(std::unique_ptr<MusicTrack> track);
    MusicTrack* findTrackByID(int id);
    void listAllTracks() const; – calls track->printInfo()
    void playTrack(int id);, void stopTrack(int id); – calls the appropriate track’s play() or stop().
Demonstration:
    In main(), create a few tracks of different genres, add to library/playlist, show them, play/stop certain tracks, etc.
Key OOP Concepts:
    Inheritance: MusicTrack → RockTrack / PopTrack / JazzTrack
    Virtual Functions: play(), stop(), getGenreName(), possibly printInfo()
    Polymorphism: a container of std::unique_ptr<MusicTrack> storing multiple derived types.
    Function Overriding in derived classes.
*/
/*********************************************************
 * MusicLibrary.cpp
 * Demonstrates a music library system with polymorphic
 * MusicTrack objects (Rock, Pop, etc.) and a manager.
 *********************************************************/

 #include <iostream>
 #include <string>
 #include <vector>
 #include <memory>
 #include <stdexcept>
 
 //------------------------------------------------
 // 1) Abstract Base Class: MusicTrack
 //------------------------------------------------
 class MusicTrack {
 protected:
     int id;
     std::string title;
     int duration;    // in seconds
     bool isPlaying;
 
 public:
     MusicTrack(int trackId, const std::string& trackTitle, int dur)
         : id(trackId), title(trackTitle), duration(dur), isPlaying(false) {}
 
     virtual ~MusicTrack() {}
 
     // pure virtual methods
     virtual void play() = 0;
     virtual void stop() = 0;
 
     // we can also have a pure virtual: virtual std::string getGenreName() const = 0;
     // but let's do a simpler approach
 
     virtual void printInfo() const {
         std::cout << "[Track] ID=" << id
                   << ", Title=\"" << title << "\""
                   << ", Duration=" << duration << "s";
         if(isPlaying) {
             std::cout << " [PLAYING]";
         }
         std::cout << "\n";
     }
 
     int getId() const { return id; }
     bool getIsPlaying() const { return isPlaying; }
 };
 
 //------------------------------------------------
 // 2) Derived Class: RockTrack
 //------------------------------------------------
 class RockTrack : public MusicTrack {
 private:
     std::string bandName;
 public:
     RockTrack(int trackId, const std::string& title, int dur,
               const std::string& band)
         : MusicTrack(trackId, title, dur), bandName(band)
     {}
 
     void play() override {
         isPlaying = true;
         std::cout << "RockTrack::play() -> Playing '" << title
                   << "' by " << bandName << "\n";
     }
     void stop() override {
         isPlaying = false;
         std::cout << "RockTrack::stop() -> Stopped '" << title << "'\n";
     }
     void printInfo() const override {
         std::cout << "[Rock] ";
         MusicTrack::printInfo();
         std::cout << "   (Band: " << bandName << ")\n";
     }
 };
 
 //------------------------------------------------
 // 3) Derived Class: PopTrack
 //------------------------------------------------
 class PopTrack : public MusicTrack {
 private:
     std::string producerName;
 public:
     PopTrack(int trackId, const std::string& title, int dur,
              const std::string& producer)
         : MusicTrack(trackId, title, dur), producerName(producer)
     {}
 
     void play() override {
         isPlaying = true;
         std::cout << "PopTrack::play() -> Playing '" << title
                   << "' (producer " << producerName << ")\n";
     }
     void stop() override {
         isPlaying = false;
         std::cout << "PopTrack::stop() -> Stopped '" << title << "'\n";
     }
 
     void printInfo() const override {
         std::cout << "[Pop] ";
         MusicTrack::printInfo();
         std::cout << "   (Producer: " << producerName << ")\n";
     }
 };
 
 //------------------------------------------------
 // 4) Manager Class: LibraryManager
 //------------------------------------------------
 class LibraryManager {
 private:
     std::vector<std::unique_ptr<MusicTrack>> tracks;
 
 public:
     void addTrack(std::unique_ptr<MusicTrack> mt) {
         tracks.push_back(std::move(mt));
     }
 
     MusicTrack* findTrackByID(int id) {
         for(auto &t : tracks) {
             if(t->getId() == id) {
                 return t.get();
             }
         }
         return nullptr;
     }
 
     void listAllTracks() const {
         std::cout << "\n=== Listing All Tracks ===\n";
         for(const auto &t : tracks) {
             t->printInfo();
         }
     }
 
     void playTrack(int id) {
         MusicTrack* t = findTrackByID(id);
         if(!t) {
             std::cerr << "No track with ID=" << id << "\n";
             return;
         }
         t->play();
     }
 
     void stopTrack(int id) {
         MusicTrack* t = findTrackByID(id);
         if(!t) {
             std::cerr << "No track with ID=" << id << "\n";
             return;
         }
         t->stop();
     }
 };
 
 //------------------------------------------------
 // 5) main() - Test Cases
 //------------------------------------------------
 int main() {
     LibraryManager manager;
 
     // Create some tracks
     auto rock1 = std::make_unique<RockTrack>(101, "Bohemian Rhapsody", 355, "Queen");
     auto pop1  = std::make_unique<PopTrack>(102, "Bad Romance", 300, "Lady Gaga");
     auto rock2 = std::make_unique<RockTrack>(103, "Enter Sandman", 330, "Metallica");
 
     // Add them to manager
     manager.addTrack(std::move(rock1));
     manager.addTrack(std::move(pop1));
     manager.addTrack(std::move(rock2));
 
     // Show all tracks
     manager.listAllTracks();
 
     // Play track 102
     manager.playTrack(102);
 
     // Stop track 101 (which is not playing yet, but let's see)
     manager.stopTrack(101);
 
     // Attempt to find an invalid track
     manager.playTrack(999); // error
 
     return 0;
 }
 