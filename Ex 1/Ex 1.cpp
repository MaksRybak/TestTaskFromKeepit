#include <iostream>
#include <string>
#include <set>
#include <fstream>


bool CheckRegister(std::string value)
{
	for (const auto& i : value)
		if (static_cast<int>(i) < 97 || static_cast<int>(i) > 122)
			return false;
	return true;
}

bool CeckUniqueWords(std::string word, std::string namefile)
{
	std::ifstream fin;
	fin.open("test2.txt");
	std::string str;
	while (!fin.eof())
	{
		fin >> str;
		if (str == word)
		{
			fin.close();
			return false;
		}
	}
	return true;

}

int ReadFromFile()
{
	std::ifstream fin;
	std::ofstream fout;
	fin.open("test.txt");
	fout.open("test2.txt");
	std::string temp;
	int count = 0;
	while (!fin.eof())
	{
		fin >> temp;
		if (CeckUniqueWords(temp, "") && CheckRegister(temp))
		{
			fout << temp << std::endl;
			count++;
		}
	}
	fout.close();
	fin.close();
	return count;
}

int ReadFromCosole()
{
	std::set<std::string> mySet;
	std::cout << "Input your text pls: ";

	std::string* text = new std::string;

	std::getline(std::cin, *text);

	std::string copyText = *text;
	std::string temp;
	int position(0);

	while (position >= 0)
	{
		position = text->find(' ');
		temp = text->substr(0, position);
		text->erase(0, position + 1);
		if (CheckRegister(temp))
			mySet.insert(temp);
	}

	text->clear();

	return mySet.size();
}

int main()
{
	using namespace std;

	int choose;

	cout << "Make yout choose: \n\t1)Read txt file (for big data);\n\t2)Write in console" << endl;
	cin >> choose;
	cin.ignore(3200, '\n');

	if (choose == 1)
	{
		cout << "Count words: " << ReadFromFile() << endl;
	}

	else if (choose == 2)
	{
		int count = ReadFromCosole();
		cout << "Count words: " << count << endl;
	}
	else
		cout << "You didn't choose =(" << endl;

	system("pause");
	return 0;
}

//if (choose == 1)
//{
//	ifstream fin;
//	fin.open("test.txt");
//
//	string temp;
//
//	while (!fin.eof())
//	{
//		fin >> temp;
//		if (CheckRegister(temp))
//			mySet.insert(temp);
//	}
//	cout << "The count util words is: " << mySet.size() << endl;
//}