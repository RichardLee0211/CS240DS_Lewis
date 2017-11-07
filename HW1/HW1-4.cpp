#include<iostream>
#include<vector>
#include<string>

typedef unsigned int uint;

using namespace std;


class Team{
    public:
        string strTeamName;
        uint wins;
        uint loses;

    public:
        Team(string teamName){
            this->strTeamName = teamName;
            this->wins = 0;
            this->loses = 0;
            return;
        };

        Team(string teamName, uint wins, uint loses){
            this->strTeamName = teamName;
            this->wins = wins;
            this->loses = loses;
            return;
        };
        Team& operator=(const Team& rhs){
            this->strTeamName = rhs.strTeamName;
            this->wins = rhs.wins;
            this->loses = rhs.loses;
            return *this;
        };

        /* friend functions */
        friend bool operator< (const Team& lhs, const Team& rhs);
        friend bool operator> (const Team& lhs, const Team& rhs);
        friend bool operator>= (const Team& lhs, const Team& rhs);
        friend bool operator<= (const Team& lhs, const Team& rhs);
};

/* global functions related to Team */
bool operator< (const Team& lhs, const Team& rhs){
    float lhsWinP = (float) lhs.wins/(lhs.wins+lhs.loses);
    float rhsWinP = (float) rhs.wins/(rhs.wins+rhs.loses);
    bool result = lhsWinP < rhsWinP;
    return result;
    // TODO: ??
    // return ((float)(lhs.wins/(lhs.wins+lhs.loses)) < (float)(rhs.wins/(rhs.wins+rhs.loses)));
};
bool operator> (const Team& lhs, const Team& rhs){
    return rhs<lhs;
};
bool operator<=(const Team& lhs, const Team& rhs){
    return !(lhs>rhs);
};
bool operator>=(const Team& lhs, const Team& rhs){
    return !(lhs<rhs);
};



// TODO: T::iterator isn't a type
// int mergeSort(T container, T::iterator begin, T::iterator end){
// parameter decleard auto
// int mergeSort(T container, auto begin, auto end){
template<class T>
int mergeSort(T container, int begin, int end){
    // TODO: iterator and merge sort
    return 0;
}

void merge(vector<Team>& left, vector<Team>& right, vector<Team>& bars){
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR)
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
    return;
}

void sort(vector<Team> & bar) {
    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    vector<Team> left;
    vector<Team> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    sort(left);
    sort(right);
    merge(left, right, bar);
    return;
}

int main(){
    vector<Team> vecTeams;
    vecTeams.push_back(Team("team1", (uint)8, (uint)2));
    vecTeams.push_back(Team("team2", (uint)3, (uint)2));
    vecTeams.push_back(Team("team3", (uint)2, (uint)2));
    vecTeams.push_back(Team("team4", (uint)1, (uint)2));
    vecTeams.push_back(Team("team5", (uint)9, (uint)2));

    // mergeSort(vecTeams);
    sort(vecTeams);

    for(auto team: vecTeams){
        cout<<team.strTeamName<<endl;
    }

    return 0;
}
