#include "stdafx.h"

extern HINSTANCE G_Inst;
extern HWND hMain;

BOOL GetSourceName(wchar_t* fname, wchar_t* title, wchar_t*filter, wchar_t* DefExt)
 {
  BOOL res;
	 OPENFILENAME fileopeninfo;
	 fname[0]=NULL;

	 fileopeninfo.lStructSize=sizeof(OPENFILENAME);
	 fileopeninfo.hwndOwner=hMain;
	 fileopeninfo.hInstance=G_Inst;
	 fileopeninfo.lpstrFilter=filter;
	 fileopeninfo.lpstrCustomFilter=NULL;
	 fileopeninfo.nMaxCustFilter=0;
	 fileopeninfo.nFilterIndex=1;
	 fileopeninfo.lpstrFile=fname;
	 fileopeninfo.nMaxFile=255;
	 fileopeninfo.lpstrFileTitle=NULL;
	 fileopeninfo.nMaxFileTitle=0;
	 fileopeninfo.lpstrInitialDir=NULL;
	 fileopeninfo.lpstrTitle=title;
	 fileopeninfo.Flags=OFN_HIDEREADONLY | OFN_NONETWORKBUTTON;
	 fileopeninfo.nFileOffset=0;
	 fileopeninfo.nFileExtension=0;
	 fileopeninfo.lpstrDefExt=DefExt;

	 res=GetOpenFileName(&fileopeninfo);
  return res;
 }

BOOL GetTargetName(wchar_t* fname, wchar_t* Title, wchar_t *filter, wchar_t* DefExt)
 {
  BOOL res;
 	OPENFILENAME fileopeninfo;
 
	 fileopeninfo.lStructSize=sizeof(OPENFILENAME);
	 fileopeninfo.hwndOwner=hMain;
	 fileopeninfo.hInstance=G_Inst;
	 fileopeninfo.lpstrFilter=filter;
 	 fileopeninfo.lpstrCustomFilter=NULL;
 	 fileopeninfo.nMaxCustFilter=0;
	 fileopeninfo.nFilterIndex=1;
	 fileopeninfo.lpstrFile=fname;
	 fileopeninfo.nMaxFile=255;
	 fileopeninfo.lpstrFileTitle=NULL;
	 fileopeninfo.nMaxFileTitle=0;
	 fileopeninfo.lpstrInitialDir=NULL;
	 fileopeninfo.lpstrTitle=Title;
	 fileopeninfo.Flags=OFN_HIDEREADONLY | OFN_NONETWORKBUTTON;
	 fileopeninfo.nFileOffset=0;
	 fileopeninfo.nFileExtension=0;
	 fileopeninfo.lpstrDefExt=DefExt; 

	 res=GetSaveFileName(&fileopeninfo);
  return res;
 }