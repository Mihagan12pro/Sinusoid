// CControlTreeView.cpp: файл реализации
//

#include "pch.h"
#include "Sinusoid.h"
#include "CControlTreeView.h"
#include"SinusoidDoc.h"

// CControlTreeView

IMPLEMENT_DYNCREATE(CControlTreeView, CTreeView)

CControlTreeView::CControlTreeView()
{

}

CControlTreeView::~CControlTreeView()
{
}

void CControlTreeView::FillTree()
{
	//CControlTreeView& tree = GetTreeCtrl();

	//tree.DeleteAllItems();

	//m_hCoord = tree.InsertItem(L"Система координат", -1, -1, NULL, TVI_ROOT);
	//m_hSinus = tree.InsertItem(L"Синус", -1, -1, NULL, TVI_ROOT);
	//m_hHatch = tree.InsertItem(L"Штриховка", -1, -1, NULL, TVI_ROOT);

	CTreeCtrl& tree = GetTreeCtrl();

	tree.DeleteAllItems();

	m_hCoord = tree.InsertItem(L"Система координат", -1, -1, NULL, TVI_ROOT);
	m_hSinus = tree.InsertItem(L"Синус", -1, -1, NULL, TVI_ROOT);
	m_hHatch = tree.InsertItem(L"Штриховка", -1, -1, NULL, TVI_ROOT);
}

BEGIN_MESSAGE_MAP(CControlTreeView, CTreeView)
END_MESSAGE_MAP()


// Диагностика CControlTreeView

#ifdef _DEBUG
void CControlTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CControlTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений CControlTreeView
