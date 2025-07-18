﻿// CObjectsDlg.cpp: файл реализации
//

#include "pch.h"
#include "Sinusoid.h"
#include "afxdialogex.h"
#include "CObjectsDlg.h"
#include"SinusoidDoc.h"
#include "SinusoidView.h"
#include"MainFrm.h"
// Диалоговое окно CObjectsDlg

IMPLEMENT_DYNAMIC(CObjectsDlg, CDialogEx)

CObjectsDlg::CObjectsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ObjectsDlg, pParent)
	, m_bCoord(FALSE)
	, m_bSinus(FALSE)
{

}

CObjectsDlg::~CObjectsDlg()
{
}

void CObjectsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CoordsCB, m_bCoord);
	DDX_Check(pDX, IDC_SinusCB, m_bSinus);
}


BEGIN_MESSAGE_MAP(CObjectsDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений CObjectsDlg
