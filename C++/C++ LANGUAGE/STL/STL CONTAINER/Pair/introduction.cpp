// in this we will study about pairs and everything about them
// in pair (which is a container ) we store values of any data type in some sequence which first and second value as name suggest it will make a pair of them in that they will be considered as a element as a whole .

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lli long long int
#define ulli unsigned long long int
#define endl '\n'
#define voi vector<int>
#define vof vector<float>
#define vod vector<double>
#define vold vector<long double>
#define vos vector<string>
#define poii pair<int, int>
#define poif pair<int, float>
#define poid pair<int, double>
#define pois pair<int, string>
#define poild pair<int,long double>
#define vopoi vector<pi>
#define f(i, m) for (int i = 0; i < m; i++)
#define fi(i, m) for (int i = 1; i <= m; i++)
#define fir(i, n, m) for (int i = n; i <= m; i++)
#define mo 1000000007
using namespace std;
int main()
{
    // pair of same type
    pair<int,int> p(10,0); // in this way we can initialise the pair .
    for(int i = 0;i<10;i++){
        cout<<p.first<<" "<<p.second<<" ";
    }

    // pair of two different types
    int n;
    cin>>n;
    pair<int , float> p[n];
    for(int i =0;i<n;i++)
    {
        int x ;
        float y;
        cin>>p[i].first>>p[i].second;
    }
    for(int i =0;i<n;i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }

    // pair of string and integer
    int n;
    cin >> n;
    pois p[n];
    f(i,n)
        cin >> p[i].first >> p[i].second;
    f(i,n)
        cout << p[i].first << " " << p[i].second << endl;

    // Nested pair
    int n;
    cin>>n;
    pair<poii,poii> p[n];
    f(i,n){
        cin>>p[i].first.first>>p[i].first.second>>p[i].second.first>>p[i].second.second;
    }
    f(i,n)
    {
        cout<<p[i].first.first<<" "<<p[i].first.second<<" "<<p[i].second.first<<" "<<p[i].second.second<<endl;
    }

    // one more nested pair 
    int n;
    cin>>n;
    pair<pair<pois,poid>,pair<poif,poii>> p[n];
    f(i,n)
    {
        cin>>p[i].first.first.first>>p[i].first.first.second>>p[i].first.second.first>>p[i].first.second.second>>p[i].second.first.first>>p[i].second.first.second>>p[i].second.second.first>>p[i].second.second.second;
    }
    f(i,n){
        cout<<p[i].first.first.first<<" "<<p[i].first.first.second<<endl<<" "<<p[i].first.second.first<<" "<<p[i].first.second.second<<endl<<"  "<<p[i].second.first.first<<" "<<p[i].second.first.second<<endl<<"   "<<p[i].second.second.first<<" "<<p[i].second.second.second<<endl<<"    ";
    }
    

    // dynamic pair 
    
    pair<poii,poii> p = {{1,2},{2,3}};
    cout<<p.first.second<<endl;
}