
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

/**
 * Read in files of nouns
 * Have a pre-made Madlibs template
 * Output the words to the terminal while making the computer read the words outloud
 * When the computer comes to a point where it needs to select the words from the user,
 *      it will pick a random word from the list given by the user and use that word.
 *  This will continue untill the story finishes
 *
 **/
 // read in the file (nouns,adjectives,etc.)
  // store all the strings in a vector
 void storeWords (ifstream &fin, vector<string> &randomWords) {
     string dummy;
     while(getline(fin,dummy)) {
         randomWords.push_back(dummy);
     }

 }
 string random_word_generator(vector<string> &randomWords) {
     srand(time(0));
     int random = rand() % 50;
     //cout << random;
     return randomWords[random];
 }

// read in the madlibs template
void storeTemplate(vector<string> &madlibs_story) {
    ifstream fin2("madlibs_template.txt");
    string dummy;
     while(fin2 >> dummy) {
         madlibs_story.push_back(dummy);
     }
}

// change the __ in the madlibs template accordingly
void clean_template(vector<string> &madlibs_story,vector<string> &randomWords ) {
    for(size_t i = 0 ; i < madlibs_story.size() ;++i) {
        int index = madlibs_story[i].find("__");
        while (index != string::npos) {
            // start the replacement at the index of where "__" was found, replace two characters, and replace it w/ random word
            string new_random_word = random_word_generator(randomWords);
            string corrected_name = madlibs_story[i].replace(index,2,new_random_word);
            madlibs_story[i]  = corrected_name;
		system("sleep 1.5");
            break;
        }
    }
}

// print to the terminal (no tts)
void cout_ouput(const vector<string> &madlibs_story) {
    for(size_t i = 0 ; i < madlibs_story.size() ;++i) {
        // print out each word in the story vector to the terminal
        cout << madlibs_story[i] << " ";

    }
}

// print to terminal and make the computer read the story (fun!)
void tts_ouput(const vector<string> &madlibs_story) {

    for(size_t i = 0 ; i < madlibs_story.size() ;++i) {
       
        string word = madlibs_story[i];
        string pf = "printf ";
        string q1 ="'";
        string q2 = "'";
        // Adds appropriate quotes to each word (so strings with multiple words will also be printed)
        string word_w_quotes = q1 + word + q2;
        // Creates string for the printf command
        string clean_word = pf + word_w_quotes;
        // change the word (of string type) to char* type
        char* convert;
        convert = &clean_word[0];
        system(convert); 
        system("printf ' '");
        //system("sleep 0.1");

        // Set up and run the text to speech
        string say = "say " + madlibs_story[i];
        char* convert2;
        convert2 = &say[0];
        system(convert2);
}
}


int main () {
    // Get the neccssary file
    cout << "Gimme a file with adjectives:" << endl;
    string filename;
    cin >> filename;
    ifstream fin(filename);

    // store the random words
    vector <string> randomWords;
    storeWords(fin,randomWords);

    // store the madlibs template story
    vector <string> madlibs_story;
    storeTemplate(madlibs_story);

    // clean the data of the madlibs
    clean_template(madlibs_story,randomWords);

    // output the story without text to speech (tts)
    //cout_output(madlibs_story);

    // output the story with text to speech (tts)
    tts_ouput(madlibs_story);

    cout << endl;
 //cout << "Once upon a time, there was a girl named Cinderella." << endl;
 //cout << "She lived in a " << random_word_generator(randomWords) << " " << "town with her two sisters." << endl;




/**
for(size_t i = 0 ; i < madlibs_story.size() ;++i) {

 string word = madlibs_story[i];
    string pf = "printf ";
    string q1 ="'";
    string q2 = "'";
    // Adds appropriate quotes to each word (so strings with multiple words will also be printed)
    string word_w_quotes = q1 + word + q2;
    // Creates string for the printf command
    string clean_word = pf + word_w_quotes;
    // change the word (of string type) to char* type
    char* convert;
    convert = &clean_word[0];
    system(convert); 
    system("printf ' '");
    system("sleep 0.9");

    // Set up and run the text to speech
    string y = "say " + madlibs_story[i];
    char* convert2;
    convert2 = &y[0];
    system(convert2);


}
**/


//cout << madlibs_story[0] << " ";
//system("sleep 3");
}

// *****************************************
//  - clear the terminal screen before outputting the story
//  - create a nice looking banner at the very start of the program
//  - make it so the user cna select different options and perhaps input their own words if they so choose
// - make the program have no time delay (ie generate random words when you get to them)
// *****************************************
 // Pick five random words in from the vector of strings
// Place those five random words into
 // Make the computer output and read the story with those random words

 // store madlibs template in a vector of strings
    // replace __ with random words
    // create a print function that will output the words and make the computer say the words
        //(for loop w/ sleep and say system calls)

/** Once upon a time, there was a girl named Cinderella.
She lived in a __ town with her two sisters.
They were very __ and __.
They were also very __ and they made Cinderella do all the work.
**/