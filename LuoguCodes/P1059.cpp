#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<int> v2;
    for (int i = 0; i < n; ++i)
    {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    	if (i != 0)
    		if (v[i] != v[i - 1])
    			v2.push_back(v[i]);
    		else
    			;
    	else
    		v2.push_back(v[i]);
    //cout << endl;
    cout << v2.size() << endl;
	for (auto i : v2)
		cout << i << " ";
    return 0;
}