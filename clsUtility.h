#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

class clsUtility
{

public:
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static string Encryption(string Password, short Key = 2)
	{
		

		for (int i = 0; i < Password.length(); i++)
		{
			Password[i] = char(int(Password[i]) + Key);
		}
		return Password;

	}

	static string Decryption(string Password, short Key = 2)
	{
		

		for (int i = 0; i < Password.length(); i++)
		{
			Password[i] = char(int(Password[i]) - Key);
		}
		return Password;

	}

	static int RandomNumber(int FromNumber, int ToNumber)
	{
		int Number = 0;
		Number = rand()%(ToNumber - FromNumber + 1) + FromNumber;
		return Number;
	}

	static void Swap(string &S1,string &S2)
	{
		string Temp;
		Temp = S1;
		S1 = S2;
		S2 = Temp;
	}

	static void Swap(char& c1, char &c2)
	{
		char Temp;
		Temp = c1;
		c1 = c2;
		c2 = Temp;
	}

	static void Swap(int &N1, int& N2)
	{
		N1 += N2;
		N2 = N1- N2;
		N1 = N1 - N2;
		
		

	}

	static void Swap(clsUtility& Date1, clsUtility& Date2 )
	{
		clsUtility Temp;
		Temp = Date1;
		Date1 = Date2;
		Date2 = Temp;
	}

	static void Swap(clsUtility *Date1, clsUtility *Date2)
	{
		clsUtility Temp;
		Temp = *Date1;
		*Date1 = *Date2;
		*Date2 = Temp;
	}

	enum enRandomCharacter
	{
		CapitalLetter=1,SmallLetter=2,Digits=3,MixChara=4

	};

	static char RandomChar(enRandomCharacter RandomCharacter)
	{
		if (RandomCharacter == enRandomCharacter::MixChara)
		{
			RandomCharacter = (enRandomCharacter)RandomNumber(1, 3);
			
		}
		switch (RandomCharacter)
		{
		case enRandomCharacter::CapitalLetter:
			return char(RandomNumber(65,90));
			break;
		case enRandomCharacter::SmallLetter:
			return char(RandomNumber(97,122));
			break;
		case enRandomCharacter::Digits:
			return char(RandomNumber(49,57));
			break;
		default:
			break;
		}
	}

	static char RandomCharacter(enRandomCharacter RandomCharacter)
	{
		

		if (RandomCharacter == enRandomCharacter::MixChara)
		{
			RandomCharacter = (enRandomCharacter)RandomNumber(1, 2);

		}
		switch (RandomCharacter)
		{
		case enRandomCharacter::CapitalLetter:
			return char(RandomNumber(65, 90));
			break;
		case enRandomCharacter::SmallLetter:
			return char(RandomNumber(97, 122));
			break;
		default:
			break;
		}
	}

	static string GenerateWord(enRandomCharacter RandomCharacter,short LengthOfWord=4)
	{
		string Word;
		for (int i = 1; i <= LengthOfWord; i++)
		{
			Word += RandomChar(RandomCharacter);
			
		}
		return Word;
	}

	static string GenerateKey(enRandomCharacter RandomCharacter)
	{
		string Key;
		for (int i = 1; i <= 25; i++)
		{
			Key += RandomChar(RandomCharacter);

			if (i % 5 == 0 && i < 25)
			{
				Key += "-";
			}

		}
		return Key;
	}

	static void GenerateKeys(short HowManyKeys ,enRandomCharacter RandomCharacter)
	{
		cout << "\nThe keys : \n";
		for (int i = 0; i < HowManyKeys; i++)
		{
			cout << GenerateKey(RandomCharacter) << endl;;
		}
	}

	static void FillArrayWithRandomNumbers(int Array[100], int Length, short StartRange, short EndRange) {
		
		for (int i = 0; i < Length; i++) {
			Array[i] = RandomNumber(StartRange, EndRange);
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enRandomCharacter RandomCharacter, short Wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(RandomCharacter, Wordlength);

	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enRandomCharacter CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static  void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}

	}

};

