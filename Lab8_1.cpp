//ОСНОВНАЯ ПРОГРАММА

#include <iostream>
#include <string>
#include <fstream>

const int N_Max = 2000;

bool Read(int& n, int& cnt, std::string words[N_Max]) 
{ 
    std::ifstream in("input.txt"); 
    if(!in.is_open()) 
    { 
        std::cerr << "File not found" << std:: endl; 
        return false; 
    } 
     
    in >> n; 
    cnt = 0; 
    while (!in.eof()) 
    { 
        in >> words[cnt]; 
        cnt++; 
    } 
    return true; 
} 


void ClearWords(int cnt, std:: string words[N_Max])
{
    for(int i=0; i<cnt; i++)
        for(int j=0; j<words[i].length();j++)
        {
            if(!isalpha(words[i][j]))
            {
                words[i].erase(j, 1);
                j--;
                continue;
            }
            words[i][j]=tolower(words[i][j]);
        }
                
}

bool HasThreeOrMoreOccurrences(const std::string& word)
{
    char letters[256] = {0};
    for (char c : word)
    {
        letters[tolower(c)]++;
        //if('A' <= c && c <= 'Z')
        //    c += 32;
    }
    for (int i = 0; i < 256; i++)
    {
        if (letters[i] >= 3)
            return true;
    }
    return false;
}

void UniqueWords(int& cnt, std::string words[N_Max])
{
    int uniqueCount = 0;
    for (int i = 0; i < cnt; i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; j++)
        {
            if (words[i] == words[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate && !words[i].empty())
        {
            words[uniqueCount++] = words[i];
        }
    }
    cnt = uniqueCount;
}

void SortByLength(int cnt, std::string words[N_Max])
{
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (words[j].length() > words[j + 1].length())
            {
                std::string temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

void WriteToOutput(int n, int cnt, std::string words[N_Max])
{
    std::ofstream out("output.txt");
    if (!out.is_open())
    {
        std::cerr << "Error opening output file" << std::endl;
        return;
    }

    for (int i = 0; i < cnt && n > 0; i++)
    {
        out << words[i] << std::endl;
        n--;
    }
}

int main()
{
    int n = 0;
    int cnt = 0;
    std::string words[N_Max];

    if (!Read(n, cnt, words))
        return -1;

    ClearWords(cnt, words);

    UniqueWords(cnt, words);

    int validWordCount = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (HasThreeOrMoreOccurrences(words[i]))
        {
            words[validWordCount++] = words[i];
        }
    }
    cnt = validWordCount;

    SortByLength(cnt, words);
    WriteToOutput(n, cnt, words);

    return 0;
}
