#pragma once
#include <iostream>
#include <vector>
using namespace std;

class MyOwnLibraryString
{

private:
	string _Value;


public:
	MyOwnLibraryString()
	{};

	MyOwnLibraryString(string Value)
	{
		_Value = Value;
	};

	void SetValue(string Value)
	{
		_Value = Value;
	};

	string  GetValue()
	{
		return _Value;
	};

	void Push_Back(string S1)
	{
		_Value += S1;
	};

	bool empty()
	{
		if (_Value.length() == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	};

	short Length()
	{
		return _Value.length();
	};

	void Append(string Value)
	{
		_Value = Value;
	};

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short CountWords(string S1)
	{
		short Position = 0;
		string Word;
		short Counter = 0;
		string Delimiter = " ";
		while ((Position = S1.find(Delimiter)) != std::string::npos)
		{

			Word = S1.substr(0, Position);
			if (Word != "")
			{
				Counter++;

			}
			S1.erase(0, Position + Delimiter.length());
		}
		if (S1 != "")
		{
			Counter++;
		}
		return Counter++;
	};

	short CountWords()
	{
		return  CountWords(_Value);
	}

	static string UpperTheFirstLetterOfEachWord(string S1)
	{
		bool Is_Not_Space = true;
		char Space = ' ';

		for (int i = 0; i < S1.length(); i++)
		{
			if( (S1[i] != Space)&& Is_Not_Space)
			{
				S1[i] = toupper(S1[i]);
			}
			Is_Not_Space = (Space == S1[i]) ? true : false;
		}
		return S1;
	}

	void UpperTheFirstLetterOfEachWord()
	{
		_Value = UpperTheFirstLetterOfEachWord(_Value);
	}

	static string LowerTheFirstLetterOfEachWord(string S1)
	{
		bool Is_Not_Space = true;
		char Space = ' ';

		for (int i = 0; i < S1.length(); i++)
		{
			if ((S1[i] != Space) && Is_Not_Space)
			{
				S1[i] = tolower(S1[i]);
			}
			Is_Not_Space = (Space == S1[i]) ? true : false;
		}
		return S1;
	}
	
	void LowerTheFirstLetterOfEachWord()
	{
		_Value = LowerTheFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Char1)
	{
		return (isupper(Char1) ? tolower(Char1) : toupper(Char1));
	}

	static string InvertALLLettersCase(string S1)
	{
		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}

	void InvertALLLettersCase()
	{
		_Value = InvertALLLettersCase(_Value);
	}

	enum enWhatToCount{ SmallLetters = 1, CapitalLetters = 2, AllLetters = 3};

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::AllLetters)
	{
		short Counter = 0;
		if (S1 =="")
		{
			return 0;
		}

		if (WhatToCount == enWhatToCount::AllLetters)
		{
			for (int i = 0; i < S1.length(); i++)
			{
				if(isalpha(S1[i]))
				{
					Counter++;
				}
			}
		}

		if (WhatToCount == enWhatToCount::CapitalLetters)
		{
			for (int i = 0; i < S1.length(); i++)
			{
				if (isupper(S1[i]))
				{
					Counter++;
				}
			}
		}

		if (WhatToCount == enWhatToCount::SmallLetters)
		{
			for (int i = 0; i < S1.length(); i++)
			{
				if (islower(S1[i]))
				{
					Counter++;
				}
			}
		}
		
		return  Counter;
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		if (S1 == "")
		{
			return 0;
		}

		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short  CountCapitalLetters()
	{
		return  CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		if (S1 == "")
		{
			return 0;
		}

		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short  CountSmallLetters()
	{
		return  CountSmallLetters(_Value);
	}

	static short CountSpecificLetters(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i]==Letter && MatchCase==false)
			{
				Counter++;
			}
			if (MatchCase)
			{
				if (toupper(S1[i]) == toupper(Letter))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}

	short CountSpecificLetters(char Letter, bool MatchCase = true)
	{
		return  CountSpecificLetters(_Value, Letter,  MatchCase);
	}

	static bool IsVowel(char Character) {
		Character = tolower(Character);
		return ((Character == 'a' || Character == 'e' || Character == 'u' || Character == 'i' || Character == 'o') ? true : false);

	}

	static short CountVowels(string Text) {
		short Count = 0;
		for (int i = 0; i < Text.length(); i++)
		{
			if (IsVowel(Text[i])) {
				Count++;
			}
		}
		return Count;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static vector <string> Split(string Text, string Delim) {
		vector <string> vWord;
		short Position = 0;
		string Word;
		while ((Position = Text.find(Delim)) != std::string::npos)
		{
			Word = Text.substr(0, Position);
			if (Word != "")
			{
				vWord.push_back(Word);
			}
			Text.erase(0, Position + Delim.length());

		}
		if (Text != "")
		{
			vWord.push_back(Text);

		}
		return vWord;


	}

	vector <string> Split(string Delim)
	{
		return  Split(_Value, Delim);
	}

	static string TrimLeft(string Text) {
		int Pos = 0;
		string St, Word;

		for (int i = 0; i < Text.length(); i++)
		{
			if (isalpha(Text[i]))
			{
				return Text.substr(i, Text.length() - 1);

			}

		}

		return "";
	}

	void TrimLeft()
	{
		Value = TrimLeft(_Value);
	}

	static string TrimRight(string Text) {
		int Pos = 0;
		string St, Word;
		for (int i = Text.length() - 1; i > 0; i--)
		{
			Pos++;
			if (Text[i] != ' ')
			{
				return  Text.substr(0, Text.length() - Pos - 1);

			}

		}
		return "";

	}

	void TrimRight()
	{
		Value = TrimRight(_Value);
	}

	static string Trim(string Text)
	{
		return TrimRight(TrimLeft((Text)));
	}

	void Trim()
	{
		Value = Trim(_Value);
	}

	static string JoinString(vector <string> vWords, string Delim) {
		string sText;
		for (auto&& i : vWords)
		{
			sText = sText + i + Delim;
		}
		return sText.substr(0, sText.length() - Delim.length());
	}

	static string JoinString(string sArray[], int Length, string Delim) {
		string sText;
		for (int i = 0; i < Length; i++)
		{
			sText = sText + sArray[i] + Delim;
		}
		return sText.substr(0, sText.length() - Delim.length());
	}

	static string ReverseString(string &Text) {
		vector <string> vWord;
		string Ts;
		vWord = Split(Text, " ");
		vector <string> ::iterator iterate = vWord.end();
		while (iterate != vWord.begin())
		{
			--iterate;
			Ts = Ts + *iterate + " ";
		}
		Ts = Ts.substr(0, Ts.length() - 1);
		return Ts;
	}

	void ReverseString()
	{
		_Value= ReverseString(_Value);
	}

	static string ReplaceSting(string vWord, string Record, string UpdateTo)
	{
		short Position = vWord.find(Record);
		string Text;
		while (Position != std::string::npos)
		{
			vWord = vWord.replace(Position, Record.length(), UpdateTo);
			Position = vWord.find(Record);
		}

		return vWord;
	}

	void ReplaceSting(string Record, string UpdateTo)
	{
		_Value =  ReplaceSting(_Value, Record, UpdateTo);
	}

	static string RemovePunctuations(string sText) {
		string TS = "";
		for (int i = 0; i < sText.length(); i++)
		{
			if (!ispunct(sText[i])) {
				TS += sText[i];
			}
		}
		return TS;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}


};

