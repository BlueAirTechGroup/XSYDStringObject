#include "stringplus.h"

StringP::StringP()
{
	this->CharArray = NULL;
	this->StrLen = 0;
}

StringP::~StringP()
{
	if (this->StrLen != 0) {
		free(this->CharArray);
	}
	this->StrLen = 0;
}

StringP::StringP(const char * Text)
{
	if (Text != NULL) {
		this->StrLen = strlen(Text);
		this->CharArray = (char*)malloc(sizeof(char)*(this->StrLen + 1));
		strcpy_s(this->CharArray, this->StrLen + 1, Text);
		this->CharArray[this->StrLen] = '\0';
	}
	else {
		this->StrLen = 0;
		this->CharArray = NULL;
	}

}

StringP::StringP(const StringP & Text)
{
	if (Text.StrLen != 0) {
		this->StrLen = Text.StrLen;
		this->CharArray = (char*)malloc(sizeof(char)*(this->StrLen + 1));
		strcpy_s(this->CharArray, this->StrLen + 1, Text.CharArray);
		this->CharArray[this->StrLen] = '\0';
	}
	else {
		this->StrLen = 0;
		this->CharArray = NULL;
	}
}

StringP StringP::operator+(const StringP & rhs)
{
	StringP NewData(this->CharArray);
	NewData += rhs;
	return NewData;
}

StringP StringP::operator+(const char * rhs)
{
	StringP NewData(this->CharArray);
	NewData += rhs;
	return NewData;
	// TODO: 在此处插入 return 语句
}

StringP StringP::operator+(const long int rhs)
{
	StringP NewData(this->CharArray);
	NewData += rhs;
	return NewData;
}


StringP & StringP::operator=(const StringP& rhs)
{
	// TODO: 在此处插入 return 语句
	if (this->StrLen > 0) {
		free(this->CharArray);
	}
	char* NCArray;
	this->StrLen = rhs.StrLen;
	NCArray = (char*) malloc(sizeof(char)*(this->StrLen + 1));
	strcpy_s(NCArray, this->StrLen + 1, rhs.CharArray);
	NCArray[this->StrLen] = '\0';
	this->CharArray = NCArray;
	return *this;
}

StringP & StringP::operator=(const char * rhs)
{
	if (this->StrLen > 0) {
		free(this->CharArray);
	}
	char* NCArray;
	this->StrLen = strlen(rhs);
	NCArray = (char*)malloc(sizeof(char)*(this->StrLen + 1));
	strcpy_s(NCArray, this->StrLen + 1, rhs);
	NCArray[this->StrLen] = '\0';
	this->CharArray = NCArray;
	return *this;
}

bool StringP::operator==(const StringP & rhs)
{
	int CompareRST = strcmp(this->CharArray, rhs.CharArray);
	if (CompareRST == 0 && rhs.StrLen == this->StrLen) {
		return true;
	}
	else {
		return false;
	}
}

bool StringP::operator==(const char * rhs)
{
	int CompareRST = strcmp(this->CharArray, rhs);
	if (CompareRST == 0) {
		return true;
	}
	else {
		return false;
	}
}

StringP & StringP::operator+=(const StringP & rhs)
{
	char* NewCharArray = (char*)malloc(sizeof(char)*(this->StrLen + rhs.StrLen + 1));
	if (this->StrLen > 0) {
		strcpy_s(NewCharArray, this->StrLen + 1, this->CharArray);
	}
	strcpy_s(NewCharArray + this->StrLen, rhs.StrLen + 1, rhs.CharArray);
	NewCharArray[this->StrLen + rhs.StrLen] = '\0';
	this->StrLen = this->StrLen + rhs.StrLen;
	if (this->StrLen > 0) {
		free(this->CharArray);
	}
	this->CharArray = NewCharArray;
	return *this;
}
StringP & StringP::operator+=(const char* rhs)
{
	unsigned long RHSSL = strlen(rhs);
	char* NewCharArray = (char*)malloc(sizeof(char)*(this->StrLen + RHSSL + 1));
	if (this->StrLen > 0) {
		strcpy_s(NewCharArray, this->StrLen + 1, this->CharArray);
	}
	strcpy_s(NewCharArray + this->StrLen, RHSSL + 1, rhs);
	NewCharArray[this->StrLen + RHSSL] = '\0';
	this->StrLen = this->StrLen + RHSSL;
	if (this->StrLen > 0) {
		free(this->CharArray);
	}
	this->CharArray = NewCharArray;
	return *this;
}

StringP & StringP::operator+=(const long int rhs)
{
	char NumberText[20];
	_itoa_s(rhs, (char*)NumberText, 19, 10);
	unsigned long NumLeng = strlen(NumberText);
	char* NewText = (char*)malloc(sizeof(char)*(this->StrLen + NumLeng + 1));
	strcpy_s(NewText, this->StrLen + 1, this->CharArray);
	strcpy_s(NewText + this->StrLen, NumLeng + 1, (char*)NumberText);
	if (this->StrLen > 0) { free(this->CharArray); }
	this->CharArray = NewText;
	this->StrLen += NumLeng;
	return *this;
	// TODO: 在此处插入 return 语句
}

void StringP::InsertString(const char * Text, const unsigned long Place)
{
	if (Place > this->StrLen) {
		return;
	}
	unsigned long TextLen = strlen(Text);
	this->StrLen += TextLen;
	char* NewCharArray = (char*)malloc(sizeof(char)*(this->StrLen + 1));
	if (this->StrLen > TextLen) {
		strncpy_s(NewCharArray, this->StrLen + 1, this->CharArray, Place);
	}
		strncpy_s(NewCharArray + Place, TextLen + 1, Text, TextLen);
	if (this->StrLen > TextLen) {
		strncpy_s(NewCharArray + Place + TextLen, this->StrLen - Place - TextLen + 1, this->CharArray + Place, this->StrLen - Place - TextLen);
	}
	NewCharArray[this->StrLen] = '\0';
	if (this->CharArray != NULL) {
		free(this->CharArray);
	}
	this->CharArray = NewCharArray;
	return;
}

void StringP::InsertString(const StringP & Text, const unsigned long Place)
{
	if (Place > this->StrLen) {
		return;
	}
	unsigned long TextLen = Text.StrLen;
	this->StrLen += TextLen;
	char* NewCharArray = (char*)malloc(sizeof(char)*(this->StrLen + 1));
	if (this->StrLen > TextLen) {
		strncpy_s(NewCharArray, this->StrLen + 1, this->CharArray, Place);
	}
	strncpy_s(NewCharArray + Place, TextLen + 1, Text.CharArray, TextLen);
	if (this->StrLen > TextLen) {
		strncpy_s(NewCharArray + Place + TextLen, this->StrLen - Place - TextLen + 1, this->CharArray + Place, this->StrLen - Place - TextLen);
	}
	NewCharArray[this->StrLen] = '\0';
	if (this->CharArray != NULL) {
		free(this->CharArray);
	}
	this->CharArray = NewCharArray;
	return;
}

void StringP::DeleteSubString(const unsigned long Start, const unsigned long Length)
{
	if (Start + Length > this->StrLen) {
		return;
	}
	char* NewCharArray = (char*)malloc(sizeof(char)*(this->StrLen - Length + 1));
	if (this->StrLen > 0) {
		strncpy_s(NewCharArray, this->StrLen - Length + 1, this->CharArray, Start);
		strncpy_s(NewCharArray + Start, this->StrLen - Length - Start + 1, this->CharArray + Start + Length, this->StrLen - Length - Start);
		NewCharArray[this->StrLen - Length] = '\0';
	}
	
	if (this->StrLen > 0) {
		free(this->CharArray);
	}
	this->StrLen = this->StrLen - Length;
	this->CharArray = NewCharArray;
}

void StringP::ReplaceSubString(const char * Text, const unsigned long Place)
{
	this->DeleteSubString(Place, strlen(Text));
	this->InsertString(Text, Place);
}

void StringP::ReplaceSubString(const StringP & Text, const unsigned long Place)
{
	this->DeleteSubString(Place, Text.StrLen);
	this->InsertString(Text, Place);
}

StringP StringP::SubString(const unsigned long Start, const unsigned long Length)
{
	StringP NewString;
	if (Start + Length > this->StrLen) {
		return NewString;
	}
	char* MySubStr = (char*) malloc(sizeof(char)*(Length + 1));
	strncpy_s(MySubStr, Length + 1, this->CharArray + Start, Length);
	NewString = MySubStr;
	free(MySubStr);
	return NewString;
}

char StringP::CharAt(const unsigned long place)
{
	return this->CharArray[place];
}

void StringP::SetCharAt(const unsigned long Place, char MyC)
{
	if (Place > this->StrLen) {
		return;
	}
	this->CharArray[Place] = MyC;
	return;
}

void StringP::InsertCharAt(const unsigned long Place, char MyC)
{
	char* NewText = (char*)malloc(sizeof(char)*(this->StrLen + 1 + 1));
	if (this->StrLen > 0) {
		strncpy_s(NewText, this->StrLen + 1 + 1, this->CharArray, Place);
		strncpy_s(NewText + Place + 1, this->StrLen + 1 + 1 - Place - 1, this->CharArray + Place, this->StrLen - Place);
	}
	NewText[Place] = MyC;
	NewText[this->StrLen + 1] = '\0';
	if (this->StrLen > 0) {
		free(this->CharArray);
	}
	this->CharArray = NewText;
	this->StrLen++;
	return;
}

void StringP::DeleteCharAt(const unsigned long Place)
{
	if (Place >= this->StrLen) {
		return;
	}
	char* NewText = (char*)malloc(sizeof(char)*(this->StrLen));
	strncpy_s(NewText, this->StrLen - 1, this->CharArray, Place);
	strncpy_s(NewText + Place, this->StrLen - Place, this->CharArray + Place + 1, this->StrLen - 1 - Place);
	if (this->StrLen > 0) {
		free(this->CharArray);
	}
	this->StrLen--;
	this->CharArray = NewText;
	return;
}

long StringP::FindStr(const char * Text, const unsigned long Start)
{
	unsigned int FindTextLen = strlen(Text);
	if (Start + FindTextLen > this->StrLen) {
		return -1;
	}
	bool RealFind = false;
	for (unsigned long XH = Start; XH <= this->StrLen - FindTextLen;XH++) {
		if (this->CharArray[XH] == Text[0]) {
			RealFind = true;
			for (unsigned int XH2 = 1;XH2 < FindTextLen;XH2++) {
				if (CharArray[XH + XH2] != Text[XH2]) {
					RealFind = false;
				}
			}
			if (RealFind) {
				return XH;
			}
		}
	}
	return -1;
}

long StringP::FindStr(const StringP & Text, const unsigned long Start)
{
	unsigned int FindTextLen = Text.StrLen;
	if (Start + FindTextLen > this->StrLen) {
		return -1;
	}
	bool RealFind = false;
	for (unsigned long XH = Start; XH <= this->StrLen - FindTextLen;XH++) {
		if (this->CharArray[XH] == Text.CharArray[0]) {
			RealFind = true;
			for (unsigned int XH2 = 1;XH2 < FindTextLen;XH2++) {
				if (CharArray[XH + XH2] != Text.CharArray[XH2]) {
					RealFind = false;
				}
			}
			if (RealFind) {
				return XH;
			}
		}
	}
	return -1;
}

StringP StringP::MiddleText(const StringP & LeftText, const StringP & RightText, unsigned long Start)
{
	
	unsigned int LeftLen = LeftText.StrLen;
	unsigned int RightLen = RightText.StrLen;
	StringP MyMT;
	if (Start + LeftLen + RightLen >= this->StrLen) {
		return MyMT;
	}
	long LeftFind = this->FindStr(LeftText, Start);
	long RightFind = this->FindStr(RightText, Start + LeftLen);
	if (LeftFind == -1 || RightFind == -1) {
		return MyMT;
	}
	MyMT = SubString(LeftFind + LeftLen, RightFind - LeftFind - LeftLen);
	return MyMT;
}

StringP StringP::MiddleText(const char * LeftText, const char * RightText, unsigned long Start)
{
	unsigned int LeftLen = strlen(LeftText);
	unsigned int RightLen = strlen(RightText);
	StringP MyMT;
	if (Start + LeftLen + RightLen >= this->StrLen) {
		return MyMT;
	}
	long LeftFind = this->FindStr(LeftText, Start);
	long RightFind = this->FindStr(RightText, Start + LeftLen);
	if (LeftFind == -1 || RightFind == -1) {
		return MyMT;
	}
	MyMT = SubString(LeftFind + LeftLen, RightFind - LeftFind - LeftLen);
	return MyMT;
	return StringP();
}

void StringP::Replace(const StringP & FindText, const StringP & ReplaceText, unsigned long Start, int Limit)
{
	unsigned long PianYi = Start;
	unsigned int RTL = ReplaceText.StrLen;
	unsigned int FTL = FindText.StrLen;
	long FindedPlace = 0;
	int RPT = 0;
	while (PianYi + RTL <= this->StrLen && FindedPlace != -1 && (RPT < Limit || Limit == -1)) {
		FindedPlace = this->FindStr(FindText, PianYi);
		if (FindedPlace != -1) {
			this->DeleteSubString(FindedPlace, FTL);
			this->InsertString(ReplaceText, FindedPlace);
			PianYi = FindedPlace + RTL;
			RPT++;
		}
	}
	return;
}



char * StringP::ToCharArray()
{
	char* MyCharArray = (char*)malloc(sizeof(char)*(this->StrLen + 1));
	strcpy_s(MyCharArray, this->StrLen + 1, this->CharArray);
	MyCharArray[this->StrLen] = '\0';
	return MyCharArray;
}

unsigned long StringP::GetStrLen()
{
	return this->StrLen;
}
