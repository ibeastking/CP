//* Difficulty -> Medium

//? You have a browser of one tab where you start on the homepage and you can visit another url,
//? get back in the history number of steps or move forward in the history number of steps.
//? Implement the BrowserHistory class:
//? BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
//? void visit(string url) Visits url from the current page. It clears up all the forward history.
//? string back(int steps) Move steps back in history.
//? If you can only return x steps in the history and steps > x, you will return only x steps.
//? Return the current url after moving back in history at most steps.
//? string forward(int steps) Move steps forward in history.
//? If you can only forward x steps in the history and steps > x, you will forward only x steps.
//? Return the current url after forwarding in history at most steps.

#include <iostream>
#include <vector>
using namespace std;

class BrowserHistory
{
public:
    vector<string> vt;
    int idx;

    BrowserHistory(string homepage)
    {
        idx = 0;
        vt.push_back(homepage);
    }

    void visit(string url)
    {
        vt.resize(idx + 1);
        vt.push_back(url);
        idx++;
    }

    string back(int steps)
    {
        int curr_idx = max(0, idx - steps);
        idx = curr_idx;
        return vt[idx];
    }

    string forward(int steps)
    {
        int curr_idx = min((int)vt.size() - 1, idx + steps);
        idx = curr_idx;
        return vt[idx];
    }
};
