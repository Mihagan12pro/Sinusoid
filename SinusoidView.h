
// SinusoidView.h: интерфейс класса CSinusoidView
//

#pragma once
class CSinusoidDoc;

class CSinusoidView : public CView
{
protected: // создать только из сериализации
	CSinusoidView() noexcept;
	DECLARE_DYNCREATE(CSinusoidView)


// Атрибуты
public:
	
	CSinusoidDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSinusoidView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	const double eps = 1e-6;
	const double PI = 3.14;

	//double EquationSolver(double a, double b, double m, double b_const, double amplitude, double period);
	double f(double x,  double b, double amplitude, double period);
	double EquationSolverByDichotomy(double a, double b,  double b_const, double amplitude, double period);
// Созданные функции схемы сообщений
	double SimpleIterations(double start, double end, double b_const, double amplitude, double period);
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в SinusoidView.cpp
inline CSinusoidDoc* CSinusoidView::GetDocument() const
   { return reinterpret_cast<CSinusoidDoc*>(m_pDocument); }
#endif

