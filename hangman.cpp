int generateRandomNumber(const int min, const int max)
{
    // TODO: Return a random integer number between min and max
     return rand() % (max - min + 1) + min;
}
vector<string> readWordListFromFile(const string& filePath)
bool isCharInWord(const char ch, const string& word)
{
    // TODO: return true if ch is in word else return false
    for (int i = 0; i < word.size(); i++) {
        if (word[i] == ch) return true;
    }
    return false;
}
/***
    Returns:
        answer (string) : the lowercase word is in the position index of wordList
***/
string chooseWordFromList(const vector<string>& wordList, int index) 
{
    // TODO: Return a lowercase word in the index position of the vector wordList.
    string answer;
    answer = wordList[index];
    for ( int i = 0; i < answer.size(); i++) answer[i]=tolower(answer[i]);
    return answer;
}
string generateHiddenCharacters(string answerWord){
    // TODO: Based on answerWord's length, generate hidden characters in form of "---"
    string secretWord;
    secretWord = answerWord;
    for ( int i = 0; i < answerWord.size();i++) secretWord[i]='-';
    return secretWord;
}
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    // TODO: Update the secret word if the character ch is in the answer word.
    for(int i=0;i<word.size();i++)
    {
        if(word[i]==ch) secretWord[i]=ch;
    }
}

/***
    Returns:
        void
***/

void updateEnteredChars(const char ch, string& chars){
    // TODO: append the character ch is in end of the text chars
    chars = chars + ch + " ";
}
void updateIncorrectGuess(int& incorrectGuess){
    // TODO: increase the value of incorrectGuess by 1
    incorrectGuess += 1;
}

/***
    Args:
        ch (char): a citharacter that player enter to console
        word (string): answer word that play needs to guess
        secretWord (string): answer word in hidden form
        correctChars (string): a string that stores correct inputs of player
            update incorrectGuess: call updateIncorrectGuess() function
            update incorrectChars: call updateEnteredChars() function
    ***/
    if (isCharInWord(ch , word)) {
        updateSecretWord(secretWord,ch,word);
        updateEnteredChars(ch,correctChars);
    } else{
        updateIncorrectGuess(incorrectGuess);
        updateEnteredChars(ch,incorrectChars);
    }
}
