// CControlTreeView.cpp: файл реализации
//

#include "pch.h"
#include "Sinusoid.h"
#include "CControlTreeView.h"
#include"SinusoidDoc.h"
#include"SinusoidView.h"

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
	m_hMain = tree.InsertItem(L"Дерево построений", -1, -1, NULL, TVI_FIRST);

	m_hCoord = tree.InsertItem(L"Система координат", -1, -1, m_hMain, TVI_FIRST);
	m_hSinus = tree.InsertItem(L"Синус", -1, -1, m_hMain, TVI_FIRST);
	m_hHatch = tree.InsertItem(L"Штриховка", -1, -1, m_hMain, TVI_FIRST);
	m_hHatch45 = tree.InsertItem(L"Штриховка 45 градусов", -1, -1, m_hMain, TVI_FIRST);

	tree.Expand(m_hSinus, TVE_EXPAND);
}


BEGIN_MESSAGE_MAP(CControlTreeView, CTreeView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
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


int CControlTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	lpCreateStruct->style |= TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS | TVS_CHECKBOXES;
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Добавьте специализированный код создания

	return 0;
}


void CControlTreeView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	//CTreeView::OnLButtonDown(nFlags, point);

	CTreeCtrl& tree = GetTreeCtrl();
	CTreeView::OnLButtonDown(nFlags, point);

	CRect rc;
	tree.GetItemRect( m_hCoord, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hCoord);
	tree.GetItemRect(m_hCoord, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hSinus);
	tree.GetItemRect(m_hSinus, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hHatch);
	tree.GetItemRect(m_hHatch, &rc, false);

	if (rc.PtInRect(point))
		tree.SelectItem(m_hHatch45);
	tree.GetItemRect(m_hHatch45, &rc, false);





	if (tree.GetSelectedItem() == m_hMain)
	{
		bool check = tree.GetCheck(m_hMain);
		tree.SetCheck(m_hCoord, check);
		tree.SetCheck(m_hSinus, check);
		tree.SetCheck(m_hHatch, check);
		tree.SetCheck(m_hHatch45, check);

	}
	else
		tree.SetCheck(m_hMain, false);

	m_pDoc->m_bCoord = tree.GetCheck(m_hCoord);
	m_pDoc->m_bSinus = tree.GetCheck(m_hSinus);
	m_pDoc->m_bHatch = tree.GetCheck(m_hHatch);
	m_pDoc->m_bHatch45 = tree.GetCheck(m_hHatch45);

	m_pDoc->m_pView->Invalidate();

}
