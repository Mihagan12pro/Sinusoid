// CNonModal.cpp : implementation file
//

#include "pch.h"
#include "Sinusoid.h"
#include "afxdialogex.h"
#include "CNonModal.h"

#include"SinusoidView.h"
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
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_ColorCrl);
}


BEGIN_MESSAGE_MAP(CNonModal, CDialogEx)
	ON_BN_CLICKED(IDC_AcceptColorBtn, &CNonModal::OnBnClickedAcceptcolorbtn)
END_MESSAGE_MAP()


// CNonModal message handlers


void CNonModal::OnBnClickedAcceptcolorbtn()
{
	pMainView -> m_SinusColor = m_ColorCrl.GetColor();

	pMainView -> Invalidate();
	// TODO: Add your control notification handler code here
}
