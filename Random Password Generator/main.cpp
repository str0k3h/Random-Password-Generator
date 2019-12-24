/*
str0k3h's Random Password Generator
Website: https://str0k3h.github.io
Media {
Instagram: @str0k3h
GitHub: @str0k3h
}
*/

#include<iostream>
#include<cstdlib> 
#include<ctime> 
#include <string>
#include <Windows.h>


using namespace std;
//character set
static const char alphnum[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int strLen = sizeof(alphnum) - 1;

void toClipboard(HWND hwnd, const string &s);

char RandomGen()
{
	return alphnum[rand() % strLen];
}

int main()
{

	SetConsoleTitle("str0k3h random password generator");
	system("color 2");

	int plength, c = 0, s = 0;
	srand((unsigned int)time(0));
	cout << "enter password length = ";
	cin >> plength;
	cout << "generating a random password with " << plength << " characters" << endl;
	cout << "generated password: ";

loopGen:
	char C;
	string passw;
	for (int z = 0; z < plength; z++)
	{
		C = RandomGen();
		passw += C;
		if (isdigit(C))
		{
			c++;
		}
		//special character
		if (C == '!' || C == '@' || C == '$' || C == '%' || C == '^' || C == '&' || C == '*' || C == '#')
		{
			s++;
		}
	}
	if (plength>2 && (s == 0 || c == 0))
	{
		goto loopGen;
	}

	cout << passw;
	cout << endl << endl << "password copied to clipboard, console closing in 4 seconds";
	size_t len = strlen(passw.c_str());
	HWND hwnd = GetDesktopWindow();
	toClipboard(hwnd, passw);
	cin.clear();
	cin.ignore(255, '\n');

	//shutdown timer
	Sleep(4000);

	return 0;
}

//allocate password string value in clipboard memory
void toClipboard(HWND hwnd, const string &s) {
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}