# include <iostream>
# include <string>
# include <set>
using namespace std;
int findMaxLength(string str)
{
	int len = str.length();
	if (len <= 1)
		return len;
	int cnt = 1, begin = 0, end = 1;
	set<char> s;
	s.insert(str[0]);
	while (begin < len && end < len)
	{
		if (s.find(str[end]) == s.end())
		{
			s.insert(str[end]);
			end++;
		}
		else
		{
			if (cnt < (end - begin))
				cnt = end - begin;
			int pos = begin;
			while (str[pos] != str[end])
			{
				s.erase(str[pos]);
				pos++;
				
			}
				
			begin = pos + 1;
			end++;
		}
	}
	return cnt;
}
//主函数
int main()
{
	string str;
	cin >> str;
	cout << findMaxLength(str) << endl;
	return 0;
}