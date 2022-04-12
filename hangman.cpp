#include <iostream>
#include<ctime>
#include "hangman.h"

using std::string;
@@ -17,7 +18,12 @@ using std::cin;
int generateRandomNumber(const int min, const int max)
{
    // TODO: Return a random integer number between min and max
    return 1;
    srand(time(NULL));

    int a = rand() % (max-min) + min;

    return a;

}

vector<string> readWordListFromFile(const string& filePath)
@@ -51,7 +57,12 @@ vector<string> readWordListFromFile(const string& filePath)
bool isCharInWord(const char ch, const string& word)
{
    // TODO: return true if ch is in word else return false
    return true;
    for(int i = 0; i < word.size(); i++){
        if(ch == word[i]){
            return true;
        }
    }
    return false;
}

/***
@@ -64,8 +75,10 @@ bool isCharInWord(const char ch, const string& word)
string chooseWordFromList(const vector<string>& wordList, int index) 
{
    // TODO: Return a lowercase word in the index position of the vector wordList.
    string answer;

    string answer = wordList[index];
    for(int i = 0; i < answer.size(); i++){
        answer[i] = tolower(answer[i]);
    }
    return answer;
}

@@ -78,6 +91,9 @@ string chooseWordFromList(const vector<string>& wordList, int index)
string generateHiddenCharacters(string answerWord){
    // TODO: Based on answerWord's length, generate hidden characters in form of "---"
    string secretWord;
    for(int i = 0; i < answerWord.size(); i++){
        secretWord[i] = '-';
    }

    return secretWord;
}
@@ -99,6 +115,13 @@ char getInputCharacter() {
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    // TODO: Update the secret word if the character ch is in the answer word.
    if(isCharInWord(ch, word) == true){
        for(int i = 0; i < word.size(); i++){
            if(ch == word[i]){
                secretWord[i] == ch;
            }
        }
    }
}

/***
@@ -110,6 +133,7 @@ void updateSecretWord(string& secretWord, const char ch, const string& word)
***/
void updateEnteredChars(const char ch, string& chars){
    // TODO: append the character ch is in end of the text chars
    chars += ch;
}

/***
@@ -120,6 +144,7 @@ void updateEnteredChars(const char ch, string& chars){
***/
void updateIncorrectGuess(int& incorrectGuess){
    // TODO: increase the value of incorrectGuess by 1
    incorrectGuess++;
}

/***
@@ -146,5 +171,13 @@ void processData(const char ch, const string& word,
            update incorrectGuess: call updateIncorrectGuess() function
            update incorrectChars: call updateEnteredChars() function
    ***/
   if(isCharInWord(ch, word) == true){
       updateSecretWord(secretWord, ch, word);
       updateEnteredChars(ch, correctChars);
   }
   else {
       updateIncorrectGuess(incorrectGuess);
       updateEnteredChars(ch, incorrectChars);
   }
}
