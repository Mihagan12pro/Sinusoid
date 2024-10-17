// SinusoidDoc.cpp: реализация класса CSinusoidDoc 
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Sinusoid.h"
#include"MainFrm.h"
#endif
#include"CControlTreeView.h"
#include"SinusoidView.h"
#include "SinusoidDoc.h"
#include"CObjectsDlg.h"

#include <propkey.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSinusoidDoc

IMPLEMENT_DYNCREATE(CSinusoidDoc, CDocument)

BEGIN_MESSAGE_MAP(CSinusoidDoc, CDocument)
	ON_COMMAND(ID_coords, &CSinusoidDoc::OnCoordsEventHandler)
	ON_COMMAND(ID_sinus, &CSinusoidDoc::OnSinusEventHandler)
	ON_UPDATE_COMMAND_UI(ID_coords, &CSinusoidDoc::OnUpdateCoordsUI)
	ON_UPDATE_COMMAND_UI(ID_sinus, &CSinusoidDoc::OnUpdateSinusUI)
	ON_COMMAND(ID_hatch, &CSinusoidDoc::OnHatchEventHandler)
	ON_COMMAND(ID_hatch45, &CSinusoidDoc::OnHatch45EventHandler)
	ON_COMMAND(ID_brush, &CSinusoidDoc::OnBrushEventHandler)
	ON_UPDATE_COMMAND_UI(ID_brush, &CSinusoidDoc::OnUpdateBrushUI)
	ON_UPDATE_COMMAND_UI(ID_hatch, &CSinusoidDoc::OnUpdateHatchUI)
	ON_UPDATE_COMMAND_UI(ID_hatch45, &CSinusoidDoc::OnUpdateHatch45UI)
	ON_COMMAND(ID_Objects_Dlg, &CSinusoidDoc::OnObjectsDlg)
END_MESSAGE_MAP()


// Создание или уничтожение CSinusoidDoc

CSinusoidDoc::CSinusoidDoc() noexcept
{
	// TODO: добавьте код для одноразового вызова конструктора

}

CSinusoidDoc::~CSinusoidDoc()
{
}

BOOL CSinusoidDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: добавьте код повторной инициализации
	// (Документы SDI будут повторно использовать этот документ)
	CWnd* MainWnd = AfxGetMainWnd();

	if (MainWnd)
	{

		m_pTreeView = (CControlTreeView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 0);

		m_pTreeView->m_pDoc = this;
		m_pView = (CSinusoidView*)((CMainFrame*)MainWnd)->m_wndSplitter.GetPane(0, 1);

	}

	m_pTreeView->FillTree();

	m_bHatch45=	m_bCoord = m_bSinus = m_bHatch = m_bBrush = false;

	return TRUE;
}




// Сериализация CSinusoidDoc

void CSinusoidDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: добавьте код сохранения		
	}
	else
	{
		// TODO: добавьте код загрузки
	}
}

#ifdef SHARED_HANDLERS

// Поддержка для эскизов
void CSinusoidDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Измените этот код для отображения данных документа
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Поддержка обработчиков поиска
void CSinusoidDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Задание содержимого поиска из данных документа.
	// Части содержимого должны разделяться точкой с запятой ";"

	// Например:  strSearchContent = _T("точка;прямоугольник;круг;объект ole;");
	SetSearchContent(strSearchContent);
}

void CSinusoidDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Диагностика CSinusoidDoc

#ifdef _DEBUG
void CSinusoidDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSinusoidDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Команды CSinusoidDoc


void CSinusoidDoc::OnCoordsEventHandler()
{
	m_bCoord = !m_bCoord;
	m_pView->Invalidate();
	m_pTreeView->FillTree();
	// TODO: добавьте свой код обработчика команд
}


void CSinusoidDoc::OnSinusEventHandler()
{
	m_bSinus = !m_bSinus;
	m_pView->Invalidate();

	m_pTreeView->FillTree();//Обновление дерева из дополнительного вида документа
	// TODO: добавьте свой код обработчика команд
}


void CSinusoidDoc::OnUpdateCoordsUI(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->SetCheck(m_bCoord);

	
}


void CSinusoidDoc::OnUpdateSinusUI(CCmdUI* pCmdUI)
{
	// TODO: добавьте свой код обработчика ИП обновления команд
	pCmdUI->SetCheck(m_bSinus);

	
}


void CSinusoidDoc::OnHatchEventHandler()
{
	m_bHatch = !m_bHatch;
	m_pView->Invalidate();
	m_pTreeView->FillTree();
	// TODO: добавьте свой код обработчика команд
}


void CSinusoidDoc::OnHatch45EventHandler()
{
	m_bHatch45 = !m_bHatch45;
	m_pView->Invalidate();
	m_pTreeView->FillTree();
	// TODO: добавьте свой код обработчика команд
}


void CSinusoidDoc::OnBrushEventHandler()
{
	m_bBrush = !m_bBrush;
	m_pView->Invalidate();
	m_pTreeView->FillTree();
	// TODO: добавьте свой код обработчика команд
}


void CSinusoidDoc::OnUpdateBrushUI(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bBrush);

	m_pTreeView->FillTree();
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CSinusoidDoc::OnUpdateHatchUI(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bHatch);

	m_pTreeView->FillTree();
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CSinusoidDoc::OnUpdateHatch45UI(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bHatch45);

	m_pTreeView->FillTree();
	// TODO: добавьте свой код обработчика ИП обновления команд
}


void CSinusoidDoc::OnObjectsDlg()
{
	// TODO: добавьте свой код обработчика команд

	CObjectsDlg dlg;

	dlg.m_bCoord = m_bCoord;
	dlg.m_bSinus = m_bSinus;

	if (dlg.DoModal() == IDOK)
	{
		m_bCoord = dlg.m_bCoord;
		m_bSinus = dlg.m_bSinus;

		m_pTreeView->FillTree();
		m_pTreeView->Invalidate(TRUE);
		
		CWnd* pWnd = AfxGetMainWnd();

		pWnd->Invalidate();
		pWnd->UpdateWindow();
		// Освобождаем контекст устройств
	}
}
