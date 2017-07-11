#ifndef XSYDStringObjectH
	#define XSYDStringObjectH
	#include <stdlib.h>
	#include <string>
	class StringP {
		private:
			char* CharArray;
			unsigned long StrLen;
		public:
			StringP();
			StringP(const char* Text);
			StringP(const StringP& Text);
			~StringP();
			StringP operator + (const StringP& rhs);
			StringP operator + (const char* rhs);
			StringP operator + (const long int rhs);
			StringP& operator = (const StringP& rhs);
			StringP& operator = (const char* rhs);
			bool operator == (const StringP& rhs);
			bool operator == (const char* rhs);
			StringP& operator += (const StringP& rhs);
			StringP& operator += (const char* rhs);
			StringP& operator += (const long int rhs);
			void InsertString(const char* Text,const unsigned long Place);
			void InsertString(const StringP& Text, const unsigned long Place);
			void DeleteSubString(const unsigned long Start, const unsigned long Length);
			void ReplaceSubString(const char* Text, const unsigned long Place);
			void ReplaceSubString(const StringP& Text, const unsigned long Place);
			StringP SubString(const unsigned long Start, const unsigned long Length);
			char CharAt(const unsigned long place);
			void SetCharAt(const unsigned long Place, char MyC);
			void InsertCharAt(const unsigned long Place, char MyC);
			void DeleteCharAt(const unsigned long Place);
			long FindStr(const char* Text, const unsigned long Start = 0);
			long FindStr(const StringP& Text, const unsigned long Start = 0);
			StringP MiddleText(const StringP& LeftText, const StringP& RightText, unsigned long Start = 0);
			StringP MiddleText(const char* LeftText, const char* RightText, unsigned long Start = 0);
			void Replace(const StringP& FindText, const StringP& ReplaceText, unsigned long Start, int Limit = -1);
			char* ToCharArray();
			unsigned long GetStrLen();
	};
#endif
