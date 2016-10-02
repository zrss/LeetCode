class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		map<string, vector<pair<string, double>>> adj;
		int num = equations.size();
		for (int i = 0; i < num; ++i) {
			adj[equations[i].first].push_back(pair<string, double>(equations[i].second, values[i]));
			adj[equations[i].second].push_back(pair<string, double>(equations[i].first, 1 / values[i]));
		}

		num = queries.size();
		vector<double> result(num, 0.0);
		for (int i = 0; i < num; ++i) {
			double rel = 1.0;
			set<string> visited;
			visited.insert(queries[i].first);
			result[i] = dfs(adj, visited, queries[i].first, queries[i].second, rel) ? rel : -1.0;
		}
		
		return result;
	}

	bool dfs(map<string, vector<pair<string, double>>>& adj, set<string>& visited, const string& source, const string& target, double& rel) {
		map<string, vector<pair<string, double>>>::iterator itrMap = adj.find(source);
		if (itrMap == adj.end())
			return false;

		if (source == target) {
			return true;
		}

		vector<pair<string, double>>& nodes = itrMap->second;
		for (vector<pair<string, double>>::iterator itr = nodes.begin(); itr != nodes.end(); ++itr) {
			if (visited.count(itr->first) == 0) {
				visited.insert(itr->first);
				
				rel *= itr->second;

				if (dfs(adj, visited, itr->first, target, rel))
					return true;

				rel /= itr->second;
			}
		}

		return false;
	}
};