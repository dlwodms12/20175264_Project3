#include <iostream>
#include <cstring>
#include <compare>

using namespace std;

//String Å¬·¡½º
class String
{
private:
	char* _chars;
public:
	String() {}
	String(const char* chars) : _chars{ new char[strlen(chars) + 1] }
	{
		strcpy_s(_chars, strlen(chars) + 1, chars);
	}

	bool operator==(const String& s)const
	{
		return strcmp(_chars, s._chars) == 0;
	}

	bool operator!=(const String& s)const
	{
		return strcmp(_chars, s._chars) != 0;
		//return !(*this == s);
	}

	bool operator>(const String& s)const
	{
		return strcmp(_chars, s._chars) > 0;
	}

	bool operator<=(const String& s)const
	{
		return !(*this > s);
	}

	bool operator<(const String& s)const
	{
		return strcmp(_chars, s._chars) < 0;
	}

	bool operator>=(const String& s)const
	{
		return !(*this < s);
	}

};

int main()
{
	String str0{ "abc" };
	String str1{ "cda" };

	if (str0 == str1)
	{
		cout << "equal" << endl;
	}
	
	if (str0 > str1)
	{
		cout << "str0 > str1" << endl;
	}

	if (str0 <= str1)
	{
		cout << "str0 <= str1" << endl;
	}

	return 0;
}