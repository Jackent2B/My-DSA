#include <bits/stdc++.h>
using namespace std;

int maxScoreWords(vector<string> &words, vector<int> &letterCounts, vector<int> score, int i){

	if(i = words.size())
		return 0;

	// If the word is not included
	int wordno = 0 + maxScoreWords(words,letterCounts, score, i+1);

	// If Word Included
	int wordscore = 0;

	string w = words[i];
	bool flag = true;

	char ch;
	for (int i = 0; i < w.length(); ++i)
	{
		ch = w[i];
		
		//If the frequency of any letter of the word is already 0,
		// then we can not use this word.
		if(letterCounts[ ch - 'a'] == 0){
			flag = false;
		}

		letterCounts[ch - 'a']--;
		wordscore = wordscore + score[ch-'a'];
	}

	int wordyes = 0;
	if(flag){
		wordyes = wordscore + maxScoreWords(words,letterCounts, score , i+1);
	}
	
	//Backtrack
	for(int i=0; i<w.length(); i++){
		letterCounts[ch-'a']++;
	}

	return max(wordno,wordyes);
} 

int main()
{
    vector<string> words = { "dog", "cat", "dad", "good" };
    vector<char> letters = { 'a', 'a', 'c', 'd', 'd','d', 'g', 'o', 'o' };
    vector<int> score= { 1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0,
            0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	vector<int> letterCounts(26,0);
 	
 	for(int i =0; i<letters.size(); i++){
 		letterCounts[letters[i] - 'a']++;
 	}

    cout<<maxScoreWords(words, letterCounts, score,0);
}
