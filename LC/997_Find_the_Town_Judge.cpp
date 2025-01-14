//? Difficulty -> Easy

//? In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
//? If the town judge exists, then:
//? The town judge trusts nobody. Everybody (except for the town judge) trusts the town judge.
//? There is exactly one person that satisfies properties 1 and 2.
//? You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.
//? Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

//! Question Tags -> Array, Hash Table, Graph

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> trust)
    {
        if (trust.size() == 0 && n == 1)
            return 1;

        vector<int> count(n + 1);
        for (auto person : trust)
        {
            //* count[person[0]]--; decrements the trust count of the first person in the pair. This is done because if the first person trusts the second person,
            //* it means that the first person does not trust themselves.
            count[person[0]]--;
            //* count[person[1]]++; increments the trust count of the second person in the pair. This is done because if the first person trusts the second person,
            //* it means that the second person is trusted by the first person.
            count[person[1]]++;
        }

        for (int person = 0; person < count.size(); person++)
        {
            //* check if there is a person who is trusted by everyone except themselves (n-1 people) and if such person exists it returns the index of that person.
            if (count[person] == n - 1)
                return person;
        }

        return -1;
    }
};