//---------------------------------------------------------------------------

#ifndef UnitMH
#define UnitMH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <FireDAC.Phys.PG.hpp>
#include <FireDAC.Phys.PGDef.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TMainW : public TForm
{
__published:	// IDE-managed Components
	TFDConnection *PgconnConnection;
	TFDQuery *SyslogTable;
	TIntegerField *SyslogTableid;
	TSQLTimeStampField *SyslogTableaddedtime;
	TWideStringField *SyslogTablesenderip;
	TIntegerField *SyslogTableseverity;
	TIntegerField *SyslogTablefacility;
	TWideMemoField *SyslogTableheadertext;
	TWideMemoField *SyslogTablemsgbody;
	TDBGrid *SyslogMessageGrid;
	TDataSource *DataSource1;
	TPanel *Panel1;
	TDateTimePicker *DateTimePickerFrom;
	TDateTimePicker *DateTimePickerTo;
	TButton *ButtonSearch;
	TDateTimePicker *DateTimePickertFrom;
	TDateTimePicker *DateTimePickertTo;
	TComboBox *IntervalSelectionCb;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *HeaderFinde;
	TEdit *BodyFinde;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *SenderIpe;
	TLabel *Label6;
	TComboBox *SeverityMaxCb;
	TLabel *Label7;
	TLabel *SQLQuery;
	TFDManager *FDManagerSyslog;
	TFDPhysPgDriverLink *FDPhysPgDriverLink1;
	TComboBox *ConnectionSelect;
	TButton *ConnectBt;
	TLabel *Label8;
	void __fastcall SyslogTablemsgbodyGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall SyslogTableheadertextGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText);
	void __fastcall SyslogMessageGridDrawDataCell(TObject *Sender, const TRect &Rect, TField *Field,
          TGridDrawState State);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall IntervalSelectionCbChange(TObject *Sender);
	void __fastcall ConnectBtClick(TObject *Sender);
	void __fastcall SyslogMessageGridTitleClick(TColumn *Column);

private:	// User declarations
public:		// User declarations
	__fastcall TMainW(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainW *MainW;
//---------------------------------------------------------------------------
#endif