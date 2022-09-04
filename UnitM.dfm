object MainW: TMainW
  Left = 0
  Top = 0
  Caption = 'SyslogUI'
  ClientHeight = 643
  ClientWidth = 1279
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object SyslogMessageGrid: TDBGrid
    Left = 0
    Top = 145
    Width = 1279
    Height = 498
    Align = alClient
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawDataCell = SyslogMessageGridDrawDataCell
    OnTitleClick = SyslogMessageGridTitleClick
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1279
    Height = 145
    Align = alTop
    TabOrder = 1
    object Label1: TLabel
      Left = 53
      Top = 21
      Width = 38
      Height = 13
      Caption = 'Interval'
    end
    object Label2: TLabel
      Left = 248
      Top = 21
      Width = 82
      Height = 13
      Caption = 'Date and time To'
    end
    object Label3: TLabel
      Left = 688
      Top = 21
      Width = 94
      Height = 13
      Caption = 'Date and time From'
    end
    object Label4: TLabel
      Left = 53
      Top = 48
      Width = 35
      Height = 13
      Caption = 'Header'
    end
    object Label5: TLabel
      Left = 67
      Top = 75
      Width = 24
      Height = 13
      Caption = 'Body'
    end
    object Label6: TLabel
      Left = 81
      Top = 102
      Width = 10
      Height = 13
      Caption = 'IP'
    end
    object Label7: TLabel
      Left = 5
      Top = 129
      Width = 86
      Height = 13
      Caption = 'Maximum severity'
    end
    object SQLQuery: TLabel
      Left = 1
      Top = 131
      Width = 1277
      Height = 13
      Align = alBottom
      Color = clBlack
      ParentColor = False
      ExplicitWidth = 3
    end
    object Label8: TLabel
      Left = 841
      Top = 102
      Width = 65
      Height = 13
      Caption = 'Syslog server'
    end
    object DateTimePickerFrom: TDateTimePicker
      Left = 336
      Top = 13
      Width = 186
      Height = 21
      Date = 44805.000000000000000000
      Time = 0.386717951390892300
      Enabled = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 0
    end
    object DateTimePickerTo: TDateTimePicker
      Left = 784
      Top = 13
      Width = 186
      Height = 21
      Date = 44805.000000000000000000
      Time = 0.386896192132553600
      Enabled = False
      TabOrder = 1
    end
    object ButtonSearch: TButton
      Left = 1063
      Top = 13
      Width = 75
      Height = 21
      Caption = 'Search'
      Enabled = False
      TabOrder = 2
      OnClick = ButtonSearchClick
    end
    object DateTimePickertFrom: TDateTimePicker
      Left = 520
      Top = 13
      Width = 89
      Height = 21
      Date = 44805.000000000000000000
      Time = 0.386717951390892300
      Enabled = False
      Kind = dtkTime
      ParentShowHint = False
      ShowHint = False
      TabOrder = 3
    end
    object DateTimePickertTo: TDateTimePicker
      Left = 968
      Top = 13
      Width = 89
      Height = 21
      Date = 44805.000000000000000000
      Time = 0.386717951390892300
      Enabled = False
      Kind = dtkTime
      ParentShowHint = False
      ShowHint = False
      TabOrder = 4
    end
    object IntervalSelectionCb: TComboBox
      Left = 97
      Top = 13
      Width = 145
      Height = 21
      Style = csDropDownList
      ItemIndex = 2
      TabOrder = 5
      Text = '1 hours'
      OnChange = IntervalSelectionCbChange
      Items.Strings = (
        '10 min'
        '30 min'
        '1 hours'
        '24 hours'
        'Custom')
    end
    object HeaderFinde: TEdit
      Left = 97
      Top = 40
      Width = 541
      Height = 21
      TabOrder = 6
    end
    object BodyFinde: TEdit
      Left = 97
      Top = 67
      Width = 541
      Height = 21
      TabOrder = 7
    end
    object SenderIpe: TEdit
      Left = 97
      Top = 94
      Width = 541
      Height = 21
      TabOrder = 8
    end
    object SeverityMaxCb: TComboBox
      Left = 97
      Top = 121
      Width = 145
      Height = 21
      Style = csDropDownList
      ItemIndex = 7
      TabOrder = 9
      Text = '7 - Debug'
      Items.Strings = (
        '0 - Emergency'
        '1 - Alert'
        '2 - Critical'
        '3 - Error'
        '4 - Warning'
        '5 - Notice'
        '6 - Informational'
        '7 - Debug')
    end
    object ConnectionSelect: TComboBox
      Left = 912
      Top = 94
      Width = 145
      Height = 21
      Style = csDropDownList
      TabOrder = 10
      OnChange = IntervalSelectionCbChange
    end
    object ConnectBt: TButton
      Left = 1063
      Top = 94
      Width = 75
      Height = 21
      Caption = 'Connect'
      TabOrder = 11
      OnClick = ConnectBtClick
    end
  end
  object PgconnConnection: TFDConnection
    LoginPrompt = False
    Left = 62
    Top = 256
  end
  object SyslogTable: TFDQuery
    Connection = PgconnConnection
    UpdateOptions.AssignedValues = [uvRefreshMode]
    Left = 166
    Top = 208
    object SyslogTableid: TIntegerField
      FieldName = 'id'
      Origin = 'id'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      ReadOnly = True
    end
    object SyslogTableaddedtime: TSQLTimeStampField
      DisplayLabel = 'time'
      DisplayWidth = 20
      FieldName = 'addedtime'
      Origin = 'addedtime'
      ReadOnly = True
    end
    object SyslogTablesenderip: TWideStringField
      DisplayLabel = 'sender ip address'
      FieldName = 'senderip'
      Origin = 'senderip'
      ReadOnly = True
      Size = 15
    end
    object SyslogTableseverity: TIntegerField
      FieldName = 'severity'
      Origin = 'severity'
      ReadOnly = True
    end
    object SyslogTablefacility: TIntegerField
      FieldName = 'facility'
      Origin = 'facility'
      ReadOnly = True
    end
    object SyslogTableheadertext: TWideMemoField
      DisplayLabel = 'header'
      DisplayWidth = 40
      FieldName = 'headertext'
      Origin = 'headertext'
      ReadOnly = True
      OnGetText = SyslogTableheadertextGetText
      BlobType = ftWideMemo
    end
    object SyslogTablemsgbody: TWideMemoField
      DisplayLabel = 'body'
      DisplayWidth = 200
      FieldName = 'msgbody'
      Origin = 'msgbody'
      ReadOnly = True
      OnGetText = SyslogTablemsgbodyGetText
      BlobType = ftWideMemo
    end
  end
  object DataSource1: TDataSource
    DataSet = SyslogTable
    Left = 168
    Top = 264
  end
  object FDManagerSyslog: TFDManager
    ConnectionDefFileName = 'dbsettings.ini'
    FormatOptions.AssignedValues = [fvMapRules]
    FormatOptions.OwnMapRules = True
    FormatOptions.MapRules = <>
    Active = True
    Left = 248
    Top = 208
  end
  object FDPhysPgDriverLink1: TFDPhysPgDriverLink
    DriverID = 'PGDlib'
    VendorLib = 'libpq.dll'
    Left = 64
    Top = 208
  end
end
