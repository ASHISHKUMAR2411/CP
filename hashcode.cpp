#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define mod 1000000007
#define ulli unsigned long long int
#define endl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define vii vector<pi>
#define pb push_back
#define sz(x) (int)(x).size()
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
using namespace std;
int main(){
    fast;
    // person data
    int no_of_people, no_of_projects;
    cin >> no_of_people >> no_of_projects;
    vector<pair<string, vector<pair<string, int>>>> people_assigned(no_of_people);
    // project data
    // vector<string, vector<pair<string, int>>> people_not_assigned(no_of_people);
    for (int i = 0; i < no_of_people; i++)
    {
        string name;
        int no_of_skills;
        cin >> name >> no_of_skills;
        vector<pair<string, int>> people_skill(no_of_skills);
        for (int j = 0; j < no_of_skills; j++)
        {
            string skill;
            int skill_level;
            cin >> skill >> skill_level;
            people_skill[j]  = make_pair(skill, skill_level);
        }
        people_assigned[i] = make_pair(name, people_skill);
    }

    // projects requirements
    vector<pair<string, int>> projects_requirements(no_of_projects);
    for (int i = 0; i < no_of_projects; i++){
        string project_name;
        int no_of_skills, x ,y , z ;
        cin >> project_name >> no_of_skills;
        vector<pair<string, int>> project_requirements(no_of_skills);
        for (int j = 0; j < no_of_skills; j++){
            string skill;
            int skill_level;
            cin >> skill >> skill_level;
            project_requirements[j] = make_pair(skill, skill_level);
        }
        projects_requirements[i] = make_pair(project_name, project_requirements);
    }
}