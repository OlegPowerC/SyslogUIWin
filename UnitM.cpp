//---------------------------------------------------------------------------

#include <vcl.h>
#include <StrUtils.hpp>
#include <map>
#include <DateUtils.hpp>
#pragma hdrstop

#include "UnitM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainW *MainW;
std::map<int,TColor> sMap = {{0, clWebSalmon},{1, clWebSalmon},{4, clWebLemonChiffon},{2, clWebLemonChiffon},{3, clWebBlanchedAlmond},{5, clWebAliceBlue},{6, clWebLavender},{7, clWebLavenderBlush}};

//---------------------------------------------------------------------------
__fastcall TMainW::TMainW(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TMainW::SyslogTablemsgbodyGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
    Text = (WideString)Sender->AsWideString;
}
//---------------------------------------------------------------------------

void __fastcall TMainW::SyslogTableheadertextGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
    	Text = (WideString)Sender->AsWideString;
}
//---------------------------------------------------------------------------


void __fastcall TMainW::SyslogMessageGridDrawDataCell(TObject *Sender, const TRect &Rect, TField *Field,
          TGridDrawState State)
{
	if(Field->FieldName == "severity")
	{
		if(Field->AsInteger >= 0)
		{
			if(sMap.find(Field->AsInteger) != sMap.end())
			{
				TMainW::SyslogMessageGrid->Canvas->Brush->Color = sMap.at(Field->AsInteger);
			}

		}
	}
	TMainW::SyslogMessageGrid->DefaultDrawDataCell(Rect, Field, State);
}
//---------------------------------------------------------------------------

void __fastcall TMainW::ButtonSearchClick(TObject *Sender)
{   System::String HeaderLikeStr = "";
	System::String BodyLikeStr = "";
	System::String IpLikeStr = "";
	System::String SeverityMax = " AND severity <= " + IntToStr(SeverityMaxCb->ItemIndex) + " ";
	if(TMainW::HeaderFinde->Text.Length() >= 2)
	{
		HeaderLikeStr = " AND headertext LIKE '%" + TMainW::HeaderFinde->Text + "%' ";
	}
	if(TMainW::BodyFinde->Text.Length() >= 2)
	{
		BodyLikeStr = " AND msgbody LIKE '%" + TMainW::BodyFinde->Text + "%' ";
	}
	if(TMainW::SenderIpe->Text.Length() >= 2)
	{
		HeaderLikeStr = " AND senderip LIKE '%" + TMainW::SenderIpe->Text + "%' ";
	}


	DateTimePickerFrom->Time = DateTimePickertFrom->Time;
	DateTimePickerTo->Time = DateTimePickertTo->Time;
	System::String DateFromStr = DateTimePickerFrom->Date.FormatString("yyyy-mm-dd");
	System::String TimeFromStr = DateTimePickerFrom->Time.FormatString("hh:mm:ss.00000");
	System::String DateToStr = DateTimePickerTo->Date.FormatString("yyyy-mm-dd");
	System::String TimeToStr = DateTimePickerTo->Time.FormatString("hh:mm:ss.00000");
	System::String SqlFromParam = DateFromStr + " " + TimeFromStr;
	System::String SqlToParam = DateToStr + " " + TimeToStr;
	System::String SQLQuery = "SELECT id,addedtime,senderip,severity,facility,headertext,msgbody FROM syslog WHERE addedtime BETWEEN '" +  SqlToParam + "' AND '" + SqlFromParam + "'"+ HeaderLikeStr + BodyLikeStr + IpLikeStr + SeverityMax;
	TMainW::SyslogTable->SQL->Text = SQLQuery;
	TMainW::SyslogTable->SQL->Add("ORDER BY addedtime DESC");
	//TMainW::SQLQuery->Caption = SQLQuery;
	TMainW::SyslogTable->Active = true;
}
//---------------------------------------------------------------------------

void __fastcall TMainW::FormCreate(TObject *Sender)
{
	TDateTime dt = Now();
	dt = IncHour(dt, -1);
	DateTimePickerFrom->DateTime = System::Sysutils::Now();
	DateTimePickerTo->DateTime = System::Sysutils::Now();
	DateTimePickertFrom->Time =   System::Sysutils::Now();
	DateTimePickerTo->DateTime =   dt;
	DateTimePickerFrom->Time = DateTimePickertFrom->Time;
	DateTimePickertTo->Time = DateTimePickerTo->Time;

		int CnCount = TMainW::FDManagerSyslog->ConnectionDefs->Count;
		TMainW::FDManagerSyslog->Active = true;
		if(CnCount > 0){
			for(int a = 0; a < CnCount; a++){
				ConnectionSelect->Items->Add(TMainW::FDManagerSyslog->ConnectionDefs->Items[a]->Name);
				ConnectionSelect->ItemIndex = 0;
			}
		}

}
//---------------------------------------------------------------------------

void __fastcall TMainW::IntervalSelectionCbChange(TObject *Sender)
{
	TDateTime dt = Now();
	switch(TMainW::IntervalSelectionCb->ItemIndex){
		case 0: dt = IncMinute(dt, -10);
		DateTimePickerTo->Enabled = false;
		DateTimePickertTo->Enabled = false;
		DateTimePickerFrom->Enabled = false;
		DateTimePickertFrom->Enabled = false;
		break;
		case 1: dt = IncMinute(dt, -30);
        DateTimePickerTo->Enabled = false;
		DateTimePickertTo->Enabled = false;
		DateTimePickerFrom->Enabled = false;
		DateTimePickertFrom->Enabled = false;
		break;
		case 2: dt = IncHour(dt, -1);
        DateTimePickerTo->Enabled = false;
		DateTimePickertTo->Enabled = false;
		DateTimePickerFrom->Enabled = false;
		DateTimePickertFrom->Enabled = false;
		break;
		case 3: dt = IncHour(dt, -24);
		DateTimePickerTo->Enabled = false;
		DateTimePickertTo->Enabled = false;
		DateTimePickerFrom->Enabled = false;
		DateTimePickertFrom->Enabled = false;
		break;
		case 4: dt = IncMinute(dt, -10);
		DateTimePickerTo->Enabled = true;
		DateTimePickertTo->Enabled = true;
		DateTimePickerFrom->Enabled = true;
		DateTimePickertFrom->Enabled = true;
		break;
		default:
		DateTimePickerTo->Enabled = false;
		DateTimePickertTo->Enabled = false;
		DateTimePickerFrom->Enabled = false;
		DateTimePickertFrom->Enabled = false;
	}


	DateTimePickerFrom->DateTime = System::Sysutils::Now();
	DateTimePickerTo->DateTime = System::Sysutils::Now();
	DateTimePickertFrom->Time =   System::Sysutils::Now();
	DateTimePickerTo->DateTime =   dt;
	DateTimePickerFrom->Time = DateTimePickertFrom->Time;
	DateTimePickertTo->Time = DateTimePickerTo->Time;
}
//---------------------------------------------------------------------------






void __fastcall TMainW::ConnectBtClick(TObject *Sender)
{
	TMainW::PgconnConnection->Connected = false;
	ButtonSearch->Enabled = false;
	TMainW::PgconnConnection->ConnectionDefName = TMainW::FDManagerSyslog->ConnectionDefs->Items[ConnectionSelect->ItemIndex]->Name;
	TMainW::PgconnConnection->Connected = true;
	if(TMainW::PgconnConnection->Connected){
		ButtonSearch->Enabled = true;
		TMainW::ButtonSearchClick(this);
   }

}
//---------------------------------------------------------------------------


void __fastcall TMainW::SyslogMessageGridTitleClick(TColumn *Column)
{
	System::String cnSortDirection = " ASC";
	if(Column->FieldName == "addedtime"){
		cnSortDirection = " DESC";
	}
	System::String cnSort = "ORDER BY " + Column->FieldName + cnSortDirection;
	System::String oldSql =  TMainW::SyslogTable->SQL->Text;
	if(TMainW::SyslogTable->SQL->Count > 1){
		TMainW::SyslogTable->Active = false;
		TMainW::SyslogTable->SQL->Delete(TMainW::SyslogTable->SQL->Count - 1);
		TMainW::SyslogTable->SQL->Add(cnSort);
		TMainW::SyslogTable->Active = true;
	}

}
//---------------------------------------------------------------------------

