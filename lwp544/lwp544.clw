; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLwp544View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "lwp544.h"
LastPage=0

ClassCount=6
Class1=CLwp544App
Class2=CLwp544Doc
Class3=CLwp544View
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_TOOLBAR1
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Resource3=IDR_MENU1
Class6=CMyDlg
Resource4=IDR_MAINFRAME
Resource5=IDD_DIALOG1

[CLS:CLwp544App]
Type=0
HeaderFile=lwp544.h
ImplementationFile=lwp544.cpp
Filter=N

[CLS:CLwp544Doc]
Type=0
HeaderFile=lwp544Doc.h
ImplementationFile=lwp544Doc.cpp
Filter=N

[CLS:CLwp544View]
Type=0
HeaderFile=lwp544View.h
ImplementationFile=lwp544View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CLwp544View


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_A




[CLS:CAboutDlg]
Type=0
HeaderFile=lwp544.cpp
ImplementationFile=lwp544.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_MYDLG
CommandCount=17

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_OPEN
Command2=ID_APP_ABOUT
CommandCount=2

[MNU:IDR_MENU1]
Type=1
Class=CLwp544View
Command1=ID_TEST1
Command2=ID_TEST2
CommandCount=2

[DLG:IDD_DIALOG1]
Type=1
Class=CMyDlg
ControlCount=7
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_EDIT3,edit,1484849280
Control5=IDC_NUM1,static,1342308608
Control6=IDC_NUM2,static,1342308608
Control7=IDC_NUM3,static,1342308352

[CLS:CMyDlg]
Type=0
HeaderFile=MyDlg.h
ImplementationFile=MyDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMyDlg
VirtualFilter=dWC

[TB:IDR_TOOLBAR1]
Type=1
Class=?
Command1=ID_A
Command2=ID_B
Command3=ID_C
CommandCount=3

