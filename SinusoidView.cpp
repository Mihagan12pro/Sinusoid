
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

#include<vector>

#include<vector>
using namespace std;




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
	//CPaintDC dc(this);

	

	CSinusoidDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rc;
	GetClientRect(&rc);
	CPen* pOld;

	double mx = 2 * 3.14 / rc.Width();
	double my = 2.f / rc.Height();

	if (pDoc->m_bCoord)
	{
		pDC->MoveTo(0, rc.Height() / 2);
		pDC->LineTo(rc.Width(), rc.Height() / 2);

		pDC->MoveTo(0, rc.Height() / 2);
	}

	if (pDoc->m_bSinus)
	{
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));

		 pOld = pDC->SelectObject(&pen);

		//pDC->MoveTo(0, rc.Height() / 2);
		

		for (int x = 0; x < rc.Width();x++)
		{
			double X_rad = x * mx;
			int y = rc.Height() / 2 + sin(X_rad) / my;

			pDC->LineTo(x, y);
		}
		pDC->SelectObject(pOld);

		
	}
	
	if (pDoc->m_bHatch)
	{

		for (int x = 0; x < rc.Width();x++)
		{
			double X_rad = x * mx;
			int y = rc.Height() / 2 + sin(X_rad) / my;
			/*CPen pen(PS_SOLID, 1, RGB(0, 255, 0));

			pOld = pDC->SelectObject(&pen);*/
			if (x % 20 == 0)
			{
				pDC->MoveTo(x, y);
				pDC->LineTo(x, rc.Height() / 2);

			}
			//pDC->LineTo(x, y);
			//pDC->SelectObject(pOld);
		}

	}
	if (pDoc->m_bHatch45)
	{
		double halfWidth = rc.Width()/2;
		double halfHeight = rc.Height() / 2;
		double height = rc.Height();
		
		
		for (int x = 0; x < rc.Width(); x++)
		{
		
			if (x % 60 == 0 )
			{
				double b = x - halfWidth; // Смещение прямой

				double start = -rc.Width(); // Начало интервала
				double end = rc.Width(); // Конец интервала

				double root = EquationSolverByDichotomy(start, end,  b, halfHeight, halfWidth);
				double y = halfHeight * sin(PI / halfWidth * root);

				double Y = height - halfHeight - y;
				double X = halfWidth + root;
				if (x < rc.Width() / 2)
				{
					pDC->MoveTo(x, halfHeight);
					pDC->LineTo(X, Y);
				}
				else
				{
					pDC->MoveTo(X, Y);
					pDC->LineTo(x, halfHeight);
				}	
			}
		}
	}

	if (pDoc -> m_bBrush)
	{

	}
}


double CSinusoidView::f(double x, double b, double amplitude, double period) 
{
	double frequency = PI / period * x; // Частота
	return amplitude * sin(frequency) - (1 * x + b); // Разность между синусом и уравнением прямой
}


// Метод бисекции
double CSinusoidView::EquationSolverByDichotomy(double start, double end,double b_const, double amplitude, double period) {


	double root;
	while ((end - start) >= eps)
	{
		root = (start + end) / 2; // Средняя точка
		if (f(root,  b_const, amplitude, period) == 0.0)
		{
			break; // c является корнем
		}
		else if (f(root,  b_const, amplitude, period) * f(start,  b_const, amplitude, period) < 0)
		{
			end = root; // Корень находится в левой части
		}
		else
		{
			start = root; // Корень находится в правой части
		}
	}
	return (start + end) / -2; // Возвращаем среднюю точку как приближенную к корню
}

double CSinusoidView::SimpleIterations(double start, double end, double b_const, double amplitude, double period)
{
	for (double x = start; x <= end; x += 0.1) //цикл грубого поиска
	{
		double a, b;
		//признак того что на интервале есть корень
		if (f(x,b_const,amplitude,period) * f(0.1+x,b_const, amplitude, period ) < 0)
		{
			 a = x; //левая граница интервала уточнения корня
			 b = x + 0.1; //правая граница интервала уточнения корня
			//цикл уточнения корня
			while (fabs(b - a) > eps)
			{
				double c = (a + b) / 2.f; //середина очередного интервала
				//признак нахождения корня в левом интервале
				if (f(c, b_const, amplitude, period) * f(a,  b_const, amplitude, period) < 0)
				{
					b = c; //отбрасываем правый интервал
				}
				else

					a = c; //отбрасываем левый интервал

			}
			return (a + b) /-2.f;
			
			//вывод сообщения о том что найден корень
			//cout << "Найден корень " << (a + b) / 2.f << "\n";
		}

	}
	return 0;

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
