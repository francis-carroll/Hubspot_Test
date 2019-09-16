#include <iostream>
#include <string>
#include <vector>
#include <list>

static const int MAX_STRING_SIZE = 20;

int main()
{
	std::vector<std::string> regString;

	std::string var;

	for (int i = 0; i < 1; i++)
	{
		std::cin >> var;
		regString.push_back(var);
	}

	int count = 0;
	int unevenCheck = -1;
	int unevenIndex = -1;
	std::list<char> sol;

	/*for (int fill = 0; fill < regString.size(); fill++)
	{
		sol.push_back(0);
	}*/

	for (auto &string : regString)
	{
		int m_count = string.size();

		if (m_count % 2 == 0)
		{
			for (int i = 0; i < m_count; i++)
			{
				for (int j = i; j < m_count; j++)
				{
					if (i != j)
					{
						if (string.at(i) == string.at(j))
						{
							count++;
							sol.push_back(string.at(i));
							sol.push_front(string.at(j));
						}
					}
				}
			}
		}
		else
		{
			std::list<std::string>::iterator it;
			for (int i = 0; i < m_count; i++)
			{
				for (int j = i; j < m_count; j++)
				{
					if (i != j)
					{
						if (string.at(i) == string.at(j))
						{
							unevenCheck = count;
							count++;
							sol.push_back(string.at(i));
							sol.push_front(string.at(j));
						}
					}
				}
				if (unevenCheck != count && count - unevenCheck == 1)
				{
					unevenIndex = count;
				}
			}
		}
	}

	system("Pause");
}