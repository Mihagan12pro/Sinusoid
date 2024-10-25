// CNonModal.cpp : implementation file
//

#include "pch.h"
#include "Sinusoid.h"
#include "afxdialogex.h"
#include "CNonModal.h"


// CNonModal dialog

IMPLEMENT_DYNAMIC(CNonModal, CDialogEx)

CNonModal::CNonModal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangeColorDlg, pParent)
{

}

CNonModal::~CNonModal()
{
}

void CNonModal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNonModal, CDialogEx)
END_MESSAGE_MAP()


// CNonModal message handlers
