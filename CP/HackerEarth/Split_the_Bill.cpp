#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> &p1, pair<int,int> &p2){
	return p1.second < p2.second;
}
int main() {
	// ID of the person: 1 to N 
	// transcation id, paid by: [[ID, price_paid]], split : [[ID, pay]]
	// Total of paid by = Total of split 
	// Its a group payment that doesn't every member of the group has to pay, it can be a list of person who has to pay, and has paid, 
	// What we need 
	// In each payment: payee and payer should not be same 
	// In all payments: payee and payer should not be the same
	int n, m;
	cin >> n >> m;
	vector<int> pay(n + 1, 0);
	for(int i = 0; i < m; i++){
		string trans_id;
		cin >> trans_id;
		int n_payers, n_splits;
		cin >> n_payers >> n_splits;
		for(int j = 0; j < n_payers; j++){
			int id, amount;
			cin >> id >> amount;
			pay[id] -= amount;
		}
		for(int j = 0; j < n_splits; j++){
			int id, amount;
			cin >> id >> amount;
			pay[id] += amount;
		}
	}
	vector<pair<int,int>> keep, give;
	for(int i = 1; i <= n; i++){
		if(pay[i] > 0){
			give.push_back({i, pay[i]});
		}
		else if(pay[i] < 0){
			keep.push_back({i, -pay[i]});
		}
	} 
	sort(keep.begin(), keep.end(), comp);
	sort(give.begin(), give.end(), comp);
	int i = 0, j = 0;
	int n_ = keep.size();
	int m_ = give.size();
	vector<vector<int>> ans;
	while(i < n_ and j < m_){
		// vector<int> a;
		if(keep[i].second == give[j].second){
			ans.push_back({keep[i].first, give[j].first, keep[i].second});
			keep[i].second -= give[j].second;
			i++;
			j++;
		}
		else if(keep[i].second > give[j].second){
			ans.push_back({keep[i].first, give[j].first, give[j].second});
			keep[i].second -= give[j].second;
			j++;
		}
		else{
			
			ans.push_back({keep[i].first, give[j].first, keep[i].second});
			give[j].second -= keep[i].second;
			i++;
		}
	}
	// cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
	for(int i = 0; i < (int)(ans.size()); i++){
		cout << ans[i][1] << " " << ans[i][0] << " " << ans[i][2] << endl;
	}
	
}