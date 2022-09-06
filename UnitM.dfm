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
    Top = 169
    Width = 1279
    Height = 455
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
    Top = 57
    Width = 1279
    Height = 112
    Align = alTop
    TabOrder = 1
    object GroupBox2: TGroupBox
      Left = 1
      Top = 1
      Width = 1127
      Height = 110
      Align = alClient
      Caption = 'Filter'
      TabOrder = 0
      ExplicitWidth = 1178
      object Label4: TLabel
        Left = 36
        Top = 19
        Width = 35
        Height = 13
        Caption = 'Header'
      end
      object Label5: TLabel
        Left = 47
        Top = 47
        Width = 24
        Height = 13
        Caption = 'Body'
      end
      object Label6: TLabel
        Left = 56
        Top = 73
        Width = 10
        Height = 13
        Caption = 'IP'
      end
      object Label7: TLabel
        Left = 381
        Top = 73
        Width = 86
        Height = 13
        Caption = 'Maximum severity'
      end
      object HeaderFinde: TEdit
        Left = 77
        Top = 16
        Width = 541
        Height = 21
        TabOrder = 0
      end
      object BodyFinde: TEdit
        Left = 77
        Top = 43
        Width = 541
        Height = 21
        TabOrder = 1
      end
      object SenderIpe: TEdit
        Left = 77
        Top = 70
        Width = 196
        Height = 21
        TabOrder = 2
      end
      object SeverityMaxCb: TComboBox
        Left = 473
        Top = 70
        Width = 145
        Height = 21
        Style = csDropDownList
        ItemIndex = 7
        TabOrder = 3
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
      object CBHeaderExclude: TCheckBox
        Left = 624
        Top = 18
        Width = 97
        Height = 17
        Caption = 'exclude'
        TabOrder = 4
      end
      object CBBodyExclude: TCheckBox
        Left = 624
        Top = 47
        Width = 97
        Height = 17
        Caption = 'exclude'
        TabOrder = 5
      end
      object CBIPExclude: TCheckBox
        Left = 279
        Top = 72
        Width = 97
        Height = 17
        Caption = 'exclude'
        TabOrder = 6
      end
    end
    object Panel4: TPanel
      Left = 1128
      Top = 1
      Width = 150
      Height = 110
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 1
      object ButtonSearch: TButton
        Left = 54
        Top = 84
        Width = 75
        Height = 21
        Caption = '&Search'
        Enabled = False
        TabOrder = 0
        OnClick = ButtonSearchClick
      end
    end
  end
  object StatusBarSq: TStatusBar
    Left = 0
    Top = 624
    Width = 1279
    Height = 19
    Panels = <
      item
        Width = 100
      end
      item
        Width = 50
      end>
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 1279
    Height = 57
    Align = alTop
    TabOrder = 3
    object Panel3: TPanel
      Left = 984
      Top = 1
      Width = 294
      Height = 55
      Align = alRight
      BevelOuter = bvNone
      TabOrder = 0
      StyleElements = [seFont, seClient]
      object Label8: TLabel
        Left = 21
        Top = 4
        Width = 65
        Height = 13
        Caption = 'Syslog server'
      end
      object ConnectionSelect: TComboBox
        Left = 21
        Top = 20
        Width = 168
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        OnChange = IntervalSelectionCbChange
      end
      object ConnectBt: TButton
        Left = 203
        Top = 18
        Width = 75
        Height = 21
        Caption = '&Connect'
        TabOrder = 1
        OnClick = ConnectBtClick
      end
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 1
      Width = 983
      Height = 55
      Align = alClient
      Caption = 'Interval'
      TabOrder = 1
      object Label3: TLabel
        Left = 588
        Top = 24
        Width = 94
        Height = 13
        Caption = 'Date and time From'
      end
      object Label2: TLabel
        Left = 200
        Top = 24
        Width = 82
        Height = 13
        Caption = 'Date and time To'
      end
      object IntervalSelectionCb: TComboBox
        Left = 17
        Top = 20
        Width = 145
        Height = 21
        Style = csDropDownList
        ItemIndex = 2
        TabOrder = 0
        Text = '1 hours'
        OnChange = IntervalSelectionCbChange
        Items.Strings = (
          '10 min'
          '30 min'
          '1 hours'
          '24 hours'
          'Custom')
      end
      object DateTimePickerFrom: TDateTimePicker
        Left = 288
        Top = 20
        Width = 186
        Height = 21
        Date = 44805.000000000000000000
        Time = 0.386717951390892300
        Enabled = False
        ParentShowHint = False
        ShowHint = False
        TabOrder = 1
      end
      object DateTimePickerTo: TDateTimePicker
        Left = 688
        Top = 20
        Width = 186
        Height = 21
        Date = 44805.000000000000000000
        Time = 0.386896192132553600
        Enabled = False
        TabOrder = 2
      end
      object DateTimePickertTo: TDateTimePicker
        Left = 880
        Top = 20
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
      object DateTimePickertFrom: TDateTimePicker
        Left = 480
        Top = 20
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
    end
  end
  object PgconnConnection: TFDConnection
    LoginPrompt = False
    Left = 62
    Top = 256
  end
  object SyslogTable: TFDQuery
    Connection = PgconnConnection
    FetchOptions.AssignedValues = [evMode, evRecordCountMode]
    FetchOptions.RecordCountMode = cmTotal
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
