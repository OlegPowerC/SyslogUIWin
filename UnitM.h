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
	TFDManager *FDManagerSyslog;
	TFDPhysPgDriverLink *FDPhysPgDriverLink1;
	TStatusBar *StatusBarSq;
	TPanel *Panel2;
	TPanel *Panel3;
	TGroupBox *GroupBox1;
	TLabel *Label3;
	TLabel *Label2;
	TComboBox *IntervalSelectionCb;
	TDateTimePicker *DateTimePickerFrom;
	TDateTimePicker *DateTimePickerTo;
	TDateTimePicker *DateTimePickertTo;
	TLabel *Label8;
	TComboBox *ConnectionSelect;
	TButton *ConnectBt;
	TGroupBox *GroupBox2;
	TEdit *HeaderFinde;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *BodyFinde;
	TEdit *SenderIpe;
	TLabel *Label6;
	TComboBox *SeverityMaxCb;
	TLabel *Label7;
	TPanel *Panel4;
	TButton *ButtonSearch;
	TDateTimePicker *DateTimePickertFrom;
	TCheckBox *CBHeaderExclude;
	TCheckBox *CBBodyExclude;
	TCheckBox *CBIPExclude;
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
