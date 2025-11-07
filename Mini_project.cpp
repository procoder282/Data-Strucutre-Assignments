include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_SONGS = 30;

struct Song {
    string artist;
    string album;
    string title;
    string lyrics;
};

// For sorting songs by title
bool compareByTitle(const Song &a, const Song &b) {
    return a.title < b.title;
}

// Binary search on titles for exact match (case-insensitive)
int binarySearchByTitle(Song library[], int n, const string &query) {
    int low = 0, high = n - 1;
    string lowerQuery = query;
    // convert query to lowercase for case-insensitive compare
    transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

    while (low <= high) {
        int mid = (low + high) / 2;
        string midTitle = library[mid].title;
        transform(midTitle.begin(), midTitle.end(), midTitle.begin(), ::tolower);

        if (midTitle == lowerQuery) {
            return mid; // found
        } else if (midTitle < lowerQuery) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // not found
}

void printSong(const Song &song) {
    cout << "Title : " << song.title << "\n";
    cout << "Artist: " << song.artist << "\n";
    cout << "Album : " << song.album << "\n";
    cout << "Lyrics: " << song.lyrics << "\n";
    cout << "-----------------------------\n";
}

int main() {
    Song library[MAX_SONGS] = {
        // (Fill this with the same 30 songs data as before)
        {"Arijit Singh", "Aashiqui 2", "Tum Hi Ho",
         "Hum tere bin ab reh nahi sakte, Tere bina kya wajood mera"},
        {"Arijit Singh", "Barfi!", "Ala Barfi",
         "Ala barfi chha gaya, pyar ke jharne chha gaya"},
        {"Arijit Singh", "Ae Dil Hai Mushkil", "Channa Mereya",
         "Acha chalta hoon, duaon mein yaad rakhna"},
        {"Arijit Singh", "Tamasha", "Agar Tum Saath Ho",
         "Agar tum saath ho, behti rahe yeh nadiya saath ho"},

        {"The Beatles", "Abbey Road", "Come Together",
         "Here come old flat top, He come grooving up slowly"},
        {"The Beatles", "Let It Be", "Let It Be",
         "When I find myself in times of trouble, Mother Mary comes to me"},
        {"The Beatles", "Revolver", "Eleanor Rigby",
         "Ah, look at all the lonely people"},
        {"The Beatles", "Help!", "Help!",
         "Help, I need somebody, Help, not just anybody"},

        {"Taylor Swift", "1989", "Shake It Off",
         "Cause the players gonna play, play, play, play, play"},
        {"Taylor Swift", "Red", "I Knew You Were Trouble",
         "I knew you were trouble when you walked in"},
        {"Taylor Swift", "Fearless", "Love Story",
         "We were both young when I first saw you"},
        {"Taylor Swift", "Reputation", "Look What You Made Me Do",
         "I'm sorry, the old Taylor can't come to the phone right now"},

        {"Lata Mangeshkar", "Dil To Pagal Hai", "Dholna",
         "Dholna dholna re, dholna dholna re"},
        {"Lata Mangeshkar", "Mughal-e-Azam", "Pyar Kiya To Darna Kya",
         "Pyar kiya to darna kya, pyar kiya koi chori nahi ki"},
        {"Lata Mangeshkar", "Guide", "Tere Mere Sapne",
         "Tere mere sapne ab ek rang hain"},

        {"Ed Sheeran", "Divide", "Shape of You",
         "I'm in love with the shape of you, We push and pull like a magnet do"},
        {"Ed Sheeran", "Multiply", "Photograph",
         "We keep this love in a photograph"},
        {"Ed Sheeran", "Plus", "The A Team",
         "And they say she's in the Class A Team"},

        {"Kishore Kumar", "Amar Prem", "Chingari Koi Bhadke",
         "Chingari koi bhadke, toh saawan use bujhaye"},
        {"Kishore Kumar", "Aradhana", "Roop Tera Mastana",
         "Roop tera mastana, pyaar mera deewana"},
        {"Kishore Kumar", "Bobby", "Main Shayar To Nahin",
         "Main shayar to nahin, magar ae haseen"},

        {"Adele", "21", "Rolling in the Deep",
         "We could have had it all, Rolling in the deep"},
        {"Adele", "25", "Hello",
         "Hello from the other side"},
        {"Adele", "19", "Chasing Pavements",
         "Should I give up or should I just keep chasing pavements?"},

        {"Neha Kakkar", "Dheeme Dheeme", "Dheeme Dheeme",
         "Dheeme dheeme se chal, dil mein chhu le"},
        {"Neha Kakkar", "Kala Chashma", "Kala Chashma",
         "Tenu kala chashma jachda ae"},
        {"Neha Kakkar", "Nikle Currant", "Nikle Currant",
         "Nikle current, current, current, current"},

        {"Shreya Ghoshal", "Devdas", "Silsila Ye Chaahat Ka",
         "Silsila ye chaahat ka, na kabhi khatam ho"},
        {"Shreya Ghoshal", "Barfi!", "Saawali Si Raat",
         "Saawali si raat hai, dhundla sa raag hai"},
        {"Shreya Ghoshal", "Rab Ne Bana Di Jodi", "Phir Le Aaya Dil",
         "Phir le aaya dil majboor kya keeje"},
    };

    // Sort the library by song title before binary search
    sort(library, library + MAX_SONGS, compareByTitle);

    cout << "Welcome to Music Player Binary Search (Title Exact Match)\n";
    cout << "Enter exact song title to search: ";
    string query;
    getline(cin, query);

    int idx = binarySearchByTitle(library, MAX_SONGS, query);
    if (idx != -1) {
        cout << "Song found:\n";
        printSong(library[idx]);
    } else {
        cout << "Song with title \"" << query << "\" not found.\n";
    }

    return 0;
}
