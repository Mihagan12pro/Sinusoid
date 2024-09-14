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

	m_hCoord = tree.InsertItem(L"Система координат", -1, -1, NULL, TVI_FIRST);
	m_hSinus = tree.InsertItem(L"Синус", -1, -1, NULL, TVI_FIRST);
	m_hHatch = tree.InsertItem(L"Штриховка", -1, -1, NULL, TVI_FIRST);

	tree.Expand(m_hSinus, TVE_EXPAND);
}

BEGIN_MESSAGE_MAP(CControlTreeView, CTreeView)
	ON_WM_CREATE()
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
