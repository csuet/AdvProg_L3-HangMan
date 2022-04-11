#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <windows.h>

using namespace std;

int misTake=-1;

string newWord();

void drawHangman(int misTake);

void guessPlay(string secretWord);

void Cls();

string updateWord(char charWord , string secretWord , string guessWord);

bool checkGuess(string secretWord , string guessWord);

int randomNumber(){

	int r;
    srand((int)time(0));

        r = rand() % 7 +1;
        return r;

}

int main(int argc, char const *argv[])
{
	string guessWord = newWord();
	string secretWord = guessWord;
	int dLength = secretWord.length();
	for (int i = 0; i < dLength; ++i)
	{
		secretWord[i]='-';
	}

	drawHangman(misTake);
	cout<<"\n \n";
	guessPlay(secretWord);
	while(1){
	char charWord;
	cout<<'\n';
	cin>>charWord;
    Cls();
	secretWord = updateWord(charWord , secretWord , guessWord);
    drawHangman(misTake);
    cout<<"\n \n";
    guessPlay(secretWord);
    if(misTake==6){cout<<"\n LOSS..."; break;}
    if(checkGuess(secretWord,guessWord)){cout<<"\n WIN..."; break;}
    }
	return 0;
}

void drawHangman(int misTake){
	//cout<<misTake;
	cout<<"-------- \n";
	cout<<"|     ";
	if (misTake >=0) cout<<"|";
	cout<<"\n";
	cout<<"|     ";
	if (misTake >=1)
	cout<<"O"; cout<<"\n";
	cout<<"|    ";
    if (misTake >=2) cout<<"/";
    if (misTake >=3)
    cout<<"|";
    if (misTake >=4) cout<<"\\";
    cout<<"\n";
	cout<<"|    ";
	if (misTake >=5) cout<<"/ ";
    if (misTake >=6) cout<<"\\";
    cout<<"\n";
    cout<<"| \n";
	cout<<"^^^^^^";
}

void guessPlay(string secretWord){
     cout<<secretWord;
}

void Cls(){
    system(cls);
}

string updateWord(char charWord , string secretWord , string guessWord){
	int dLength = guessWord.length();
    int check = 0;
	for (int i = 0; i < dLength; ++i)
	{
		if(guessWord[i]==charWord){
			secretWord[i] = charWord;
			check++;
		}
	}
	if(check==0) misTake++;
	return secretWord;
}

string newWord(){
	string word;
	ifstream file ("dictionary.txt");
	if(file.is_open()){
		for (int i = 1; i <=randomNumber() ; i++)
		{
			getline(file,word);

		}
		file.close();
	}
	word.erase(word.begin()+0);
	return word;
}

bool checkGuess(string secretWord , string guessWord){
	int dLength = guessWord.length();
	for (int i = 0; i < dLength; ++i)
	{
		if(secretWord[i]!=guessWord[i]) return false;
	}
	return true;
}
