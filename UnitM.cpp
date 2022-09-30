//---------------------------------------------------------------------------

#include <vcl.h>
#include <StrUtils.hpp>
#include <map>
#include <DateUtils.hpp>
#include "ShellAPI.h"
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
				SyslogMessageGrid->Canvas->Brush->Color = sMap.at(Field->AsInteger);
			}

		}
	}
	SyslogMessageGrid->DefaultDrawDataCell(Rect, Field, State);
}
//---------------------------------------------------------------------------

void __fastcall TMainW::ButtonSearchClick(TObject *Sender)
{   System::String HeaderLikeStr = "";
	System::String BodyLikeStr = "";
	System::String IpLikeStr = "";
	System::String NotKeyW = "";
	System::String SeverityMax = " AND severity <= " + IntToStr(SeverityMaxCb->ItemIndex) + " ";
	if(HeaderFinde->Text.Length() >= 2)
	{
		if(CBHeaderExclude->Checked){
			NotKeyW = " NOT ";
		}
		HeaderLikeStr = " AND headertext " +NotKeyW+"LIKE '%" + HeaderFinde->Text + "%' ";
		NotKeyW = "";
	}

	if(BodyFinde->Text.Length() >= 2)
	{
		if(CBBodyExclude->Checked){
			NotKeyW = " NOT ";
		}
		BodyLikeStr = " AND msgbody " +NotKeyW+"LIKE '%" + BodyFinde->Text + "%' ";
		NotKeyW = "";
	}
	if(SenderIpe->Text.Length() >= 2)
	{
		if(CBIPExclude->Checked){
			NotKeyW = " NOT ";
		}
		IpLikeStr = " AND senderip " +NotKeyW+"LIKE '%" + SenderIpe->Text + "%' ";
        NotKeyW = "";
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
	SyslogTable->SQL->Text = SQLQuery;
	SyslogTable->SQL->Add("ORDER BY addedtime DESC");

	SyslogTable->FetchOptions->Mode = fmOnDemand;
	SyslogTable->Active = true;
	StatusBarSq->Panels->Items[1]->Text = "Record count: " + String(SyslogTable->RecordCount);

}
//---------------------------------------------------------------------------

void __fastcall TMainW::FormCreate(TObject *Sender)
{
	StatusBarSq->Panels->Items[0]->Text = "Disconnected";
	TDateTime dt = Now();
	dt = IncHour(dt, -1);
	DateTimePickerFrom->DateTime = System::Sysutils::Now();
	DateTimePickerTo->DateTime = System::Sysutils::Now();
	DateTimePickertFrom->Time =   System::Sysutils::Now();
	DateTimePickerTo->DateTime =   dt;
	DateTimePickerFrom->Time = DateTimePickertFrom->Time;
	DateTimePickertTo->Time = DateTimePickerTo->Time;

		int CnCount = FDManagerSyslog->ConnectionDefs->Count;
		FDManagerSyslog->Active = true;
		if(CnCount > 0){
			for(int a = 0; a < CnCount; a++){
				ConnectionSelect->Items->Add(FDManagerSyslog->ConnectionDefs->Items[a]->Name);
				ConnectionSelect->ItemIndex = 0;
			}
		}

}
//---------------------------------------------------------------------------

void __fastcall TMainW::IntervalSelectionCbChange(TObject *Sender)
{
	TDateTime dt = Now();
	DateTimePickerTo->Enabled = false;
	DateTimePickertTo->Enabled = false;
	DateTimePickerFrom->Enabled = false;
	DateTimePickertFrom->Enabled = false;
	switch(IntervalSelectionCb->ItemIndex){
		case 0: dt = IncMinute(dt, -10);
		break;
		case 1: dt = IncMinute(dt, -30);
		break;
		case 2: dt = IncHour(dt, -1);
		break;
		case 3: dt = IncHour(dt, -24);
		break;
		case 4: dt = IncMinute(dt, -10);
		DateTimePickerTo->Enabled = true;
		DateTimePickertTo->Enabled = true;
		DateTimePickerFrom->Enabled = true;
		DateTimePickertFrom->Enabled = true;
		break;
		default:
		break;
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
	if(PgconnConnection->Connected){
		PgconnConnection->Connected = false;
		ButtonSearch->Enabled = false;
		btnExport->Enabled = false;
        StatusBarSq->Panels->Items[0]->Text = "Disconnect";
		ConnectBt->Caption = "Connect";
		TMenuItem* SettigsFileMenuItem = MainMenu->Items->Items[1];
		SettigsFileMenuItem->Enabled = true;
		ConnectionSelect->Enabled = true;
	}else{
		ButtonSearch->Enabled = false;
		PgconnConnection->ConnectionDefName = FDManagerSyslog->ConnectionDefs->Items[ConnectionSelect->ItemIndex]->Name;
		PgconnConnection->Connected = true;
		if(PgconnConnection->Connected){
			TMenuItem* SettigsFileMenuItem = MainMenu->Items->Items[1];
			SettigsFileMenuItem->Enabled = false;
			ButtonSearch->Enabled = true;
            btnExport->Enabled = true;
			ConnectionSelect->Enabled = false;
			StatusBarSq->Panels->Items[0]->Text = "Connected";
			ButtonSearchClick(this);
			ConnectBt->Caption = "Disconnect";
		}
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
	System::String oldSql =  SyslogTable->SQL->Text;
	if(SyslogTable->SQL->Count > 1){
		SyslogTable->Active = false;
		SyslogTable->SQL->Delete(SyslogTable->SQL->Count - 1);
		SyslogTable->SQL->Add(cnSort);
		SyslogTable->Active = true;
	}

}
//---------------------------------------------------------------------------



void __fastcall TMainW::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

bool __fastcall TMainW::ApplicationEvents1Help(WORD Command, NativeInt Data, bool &CallHelp)

{
	String TheFile = "SyslogUI.pdf";
	ShellExecute(NULL, L"open",TheFile.c_str(),NULL, NULL, SW_SHOWNORMAL);
	return true;
}

//---------------------------------------------------------------------------

void __fastcall TMainW::Action1Execute(TObject *Sender)
{
  String TheFile = "SyslogUI.pdf";
  ShellExecute(NULL, L"open",TheFile.c_str(),NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainW::Action2Execute(TObject *Sender)
{
	String Prog = "notepad.exe";
	String TheFile = "dbsettings.ini";
	ShellExecute(NULL, L"open", Prog.c_str(), TheFile.c_str(), NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------


void __fastcall TMainW::ApplicationEvents1Activate(TObject *Sender)
{
		if(PgconnConnection->Connected == false){
			FDManagerSyslog->Active = false;
			int CnCount = FDManagerSyslog->ConnectionDefs->Count;
			FDManagerSyslog->Active = true;
			if(CnCount > 0){
				ConnectionSelect->Items->Clear();
				for(int a = 0; a < CnCount; a++){
					ConnectionSelect->Items->Add(FDManagerSyslog->ConnectionDefs->Items[a]->Name);
					ConnectionSelect->ItemIndex = 0;
				}
			}
		}

}
//---------------------------------------------------------------------------

void __fastcall TMainW::btnExportClick(TObject *Sender)
{
	if(SaveDialogExport->Execute())
	{
		if(SyslogTable->Active)
		{
			String FileNameAndPath = SaveDialogExport->FileName;
			_di_IXMLDocument XmlExport = NewXMLDocument("1.0");
			_di_IXMLNode Root = XmlExport->CreateNode("SyslogData",ntElement,L"");
			XmlExport->SetDocumentElement(Root);

			String ID,Time,IP,Severity,Facility,Header,Body;
			SyslogTable->DisableControls();
			SyslogTable->First();

			for(SyslogTable->First();!SyslogTable->Eof;SyslogTable->Next()){
				ID = SyslogTable->Fields->Fields[0]->AsString;
				Time = SyslogTable->Fields->Fields[1]->AsString;
				IP =  SyslogTable->Fields->Fields[2]->AsString;
				Severity = SyslogTable->Fields->Fields[3]->AsString;
				Facility = SyslogTable->Fields->Fields[4]->AsString;
				Header = SyslogTable->Fields->Fields[5]->AsString;
				Body = SyslogTable->Fields->Fields[6]->AsString;
				_di_IXMLNode Node  = Root->AddChild("Record");
				_di_IXMLNode ChildNodeID  = Node->AddChild("ID");
				ChildNodeID->Text = ID;
				_di_IXMLNode ChildNodeIP  = Node->AddChild("IP");
				ChildNodeIP->Text = IP;
				_di_IXMLNode ChildNodeTime  = Node->AddChild("Time");
				ChildNodeTime->Text = Time;
				_di_IXMLNode ChildNodeSeverity  = Node->AddChild("Severity");
				ChildNodeSeverity->Text = Severity;
				_di_IXMLNode ChildNodeFacility  = Node->AddChild("Facility");
				ChildNodeFacility->Text = Facility;
				_di_IXMLNode ChildNodeHeader  = Node->AddChild("Header");
				ChildNodeHeader->Text = Header;
				_di_IXMLNode ChildNodeBody  = Node->AddChild("Message");
				ChildNodeBody->Text = Body;
			}

			SyslogTable->First();
			SyslogTable->EnableControls();
			XmlExport->SaveToFile(FileNameAndPath);
		}
		
	}
}
//---------------------------------------------------------------------------

