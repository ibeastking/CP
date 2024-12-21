//? Difficulty -> Easy

//? Given an array of strings words, 
//? return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//? In the American keyboard:
//? the first row consists of the characters "qwertyuiop",
//? the second row consists of the characters "asdfghjkl", and
//? the third row consists of the characters "zxcvbnm".

//! Question Tag -> Array, Hash Table, String

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;

        vector<int> rows({2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3});
        vector<int> rowc({2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3});

        for(auto word: words){
            bool flag = true;
            for(int i=0;i<word.length()-1;i++){
                if(word[i] >= 'A' and word[i] <= 'Z'){
                    if(word[i+1] >= 'A' and word[i+1] <= 'Z'){
                        if(rowc[word[i] - 'A'] != rowc[word[i+1] - 'A']){
                            flag = false;
                            break;
                        }
                    }else{
                        if(rowc[word[i] - 'A'] != rows[word[i+1] - 'a']){
                            flag = false;
                            break;
                        }
                    }
                }else{
                    if(word[i+1] >= 'A' and word[i+1] <= 'Z'){
                        if(rows[word[i] - 'a'] != rowc[word[i+1] - 'A']){
                            flag = false;
                            break;
                        }
                    }else{
                        if(rows[word[i] - 'a'] != rows[word[i+1] - 'a']){
                            flag = false;
                            break;
                        }
                    }
                }
            }

            if(flag) res.push_back(word);
        }

        return res;
    }
};