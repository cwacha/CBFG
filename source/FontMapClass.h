#ifndef _FONTMAPCLASS_H
#define _FONTMAPCLASS_H

#include <windows.h>
#include "cbfgdefs.h"
#include "UtilFunctions.h"

class BFontMap
 {
  public:
   BFontMap();
   ~BFontMap();
   void SetAutoSize(bool NewAutoSize);
   bool GetAutoSize();
   void CalculateAutoSize();
   int  GetSize(int Which);
   int  SetSize(int Which, int NewSize);
   unsigned char GetBaseChar();
   unsigned char SetBaseChar(int);
   char GetGlobal(int Which);
   char SetGlobal(int Which, char NewVal);
   char GetCharVal(int Char, int Which);
   char SetCharVal(int Char, int Which, char NewVal );
   long GetFontHeight();
   long SetFontHeight(long);
   long GetFontWidth();
   long SetFontWidth(long);
   long GetFontWeight();
   long SetFontWeight(long);
   long GetFontQuality();
   long SetFontQuality(long);
   long GetFontItalic();
   long SetFontItalic(long);
   wchar_t* GetFontName();
   bool SetFontName(wchar_t*);
   bool CalcWidths(HDC);
   HBITMAP* DrawFontMap(int Flags, int Sel);

   int  LoadConfig(char *fname);
   bool SaveConfig(char *fname, bool Grid, bool Width);
   void ResetOffsets();

   bool SaveFont(int Format, wchar_t*fname, int Flags=0);
   int  ExportMap(wchar_t* fname, int fmt);
   bool ImportData(wchar_t*fname);

   void SetCol(int Which, BYTE Red, BYTE Green, BYTE Blue);
   void SetCol(int Which, BFG_RGB Col);
   BFG_RGB GetCol(int Which);

   bool SetAlphabet(wchar_t* text);
   wchar_t* GetAlphabet();
   void enableAlphabet(bool newvalue);
   bool AlphabetEnabled();

  private:
   LOGFONT FntDef;
   HFONT fnt;
   bool AutoSize;
   int TextureCols, TextureRows;
   int  MapWidth,MapHeight;
   int  CellHeight,CellWidth;
   unsigned char BaseChar;
   unsigned char BaseWidth[256];
   char WidthMod[256];
   char VMod[256];
   char HMod[256];
   char gWidthMod,gHMod,gVMod;
   BFG_RGB BkCol,TextCol,GridCol,WidthCol,SelCol;
   bool useAlphabet;
   wchar_t Alphabet[512];

   bool IsPower(int TestVal);
   bool SaveBFF2(wchar_t*fname, char OutputBPP, bool Invert, bool RGBSat);
   bool ExportCSVData(wchar_t*fname);
   bool ExportBinData(wchar_t*fname);
 };

#endif