#include "arrayalgorithms.h"
#include <unordered_map>
#include <algorithm>

bool stringContainsUniqueCharacters(char word[], int count)
{
    std::unordered_map<char,int> characters;
    for(int index = 0; index < count; index++)
    {
        characters[word[index]] += 1;
        if (characters[word[index]] > 1)
            return false;
    }
    return true;
}

bool stringContainsUniqueCharacters_Inplace(char word[], int count)
{
    std::sort(word,word+count);
    for(int index = 0; index < count-1; index++)
    {
        if(word[index] == word[index+1])
            return false;
    }
    return true;
}

bool stringsArePermutations(std::string s1, std::string s2)
{
    std::unordered_map<char,int> comparisonmap;
    int index = 0;

    while(s1[index] != '\0')
    {
        comparisonmap[s1[index]] += 1;
        index++;
    }
    index = 0;

    while (s2[index] != '\0')
    {
        comparisonmap[s1[index]] -= 1;
        index++;
    }
    for(auto value: comparisonmap)
    {
        if(value.second != 0)
            return false;
    }
    return true;
}

std::string URLify(std::string URL)
{
    int tail = URL.length()-1;
    int lead = tail;

    while(URL[lead] == ' ')
    {
        lead--;
    }

    while(lead >= 0)
    {
        if(URL[lead] != ' ')
            URL[tail] = URL[lead];
        else
        {
            URL[tail--] = '0';
            URL[tail--] = '2';
            URL[tail] = '%';
        }
        lead--;
        tail--;
    }
    return URL;
}
