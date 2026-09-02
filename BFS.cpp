#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

vector<int> bfs(int N, int E, vector<vector<int>> edges, int s)
{
    map<int, vector<int>> g;
    vector<bool> vis(N + 1, false);
    vector<int> ans(N + 1, -1);

    for (int i = 0; i < E; i++)
    {
        vector<int> edge = edges[i];
        int a = edge[0], b = edge[1];
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    vis[s] = true;
    while (!q.empty())
    {
        auto [city, ecnt] = q.front();
        q.pop();
        for (int othc : g[city])
        {
            if (!vis[othc])
            {
                q.push(make_pair(othc, ecnt + 1));
                ans[othc] = ecnt + 1;
                vis[othc] = true;
            }
        }
    }

    vector<int> res;

    for (int c = 1; c <= N; c++)
    {
        if (c == s)
            continue;
        if (ans[c] == -1)
        {
            res.push_back(-1);
        }
        else
        {
            res.push_back(ans[c] * 6);
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++)
        {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++)
            {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++)
        {
            fout << result[i];

            if (i != result.size() - 1)
            {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
