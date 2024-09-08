
// SinusoidView.cpp: реализация класса CSinusoidView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Sinusoid.h"
#endif

#include "SinusoidDoc.h"
#include "SinusoidView.h"








#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSinusoidView

IMPLEMENT_DYNCREATE(CSinusoidView, CView)

BEGIN_MESSAGE_MAP(CSinusoidView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Создание или уничтожение CSinusoidView

CSinusoidView::CSinusoidView() noexcept
{
	// TODO: добавьте код создания

}

CSinusoidView::~CSinusoidView()
{
}

BOOL CSinusoidView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CSinusoidView

void CSinusoidView::OnDraw(CDC* pDC)
{
	CSinusoidDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rc;
	GetClientRect(&rc);

	pDC->MoveTo(0, rc.Height() / 2);
	pDC->LineTo(rc.Width(), rc.Height() / 2);

	pDC->MoveTo(0, rc.Height());

	const int points_count = 40;

	for (int i = 0;i < points_count;i++)
	{
		Point point(i, rc.Width(), rc.Height(), points_count);


		if (i == 0)
		{
			pDC->MoveTo(i * (rc.Width() / (point.points_count - 1)),point.Y());
		}
		else
		{
			pDC->LineTo(i * (rc.Width() / (point.points_count - 1)), point.Y());
		}
	}

	//Point p();
	//for (int i = 0; i < *&p.points_count; i++)
	//{
	//	// Вычисляем x в диапазоне от 0 до 4π (или больше, если нужно)
	//	double x = (2 * pi * i) / (num_points - 1);

	//	double y = centerY + amplitude * sin(frequency * x);


	//	if (i == 0)
	//		pDC->MoveTo(i * (rc.Width() / (num_points - 1)), y);
	//	else
	//		pDC->LineTo(i * (rc.Width() / (num_points - 1)), y);
	//}

	// TODO: добавьте здесь код отрисовки для собственных данных
}


// Печать CSinusoidView

BOOL CSinusoidView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CSinusoidView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CSinusoidView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CSinusoidView

#ifdef _DEBUG
void CSinusoidView::AssertValid() const
{
	CView::AssertValid();
}

void CSinusoidView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSinusoidDoc* CSinusoidView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSinusoidDoc)));
	return (CSinusoidDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CSinusoidView
