
// SinusoidDoc.h: интерфейс класса CSinusoidDoc 
//


#pragma once

class Point
{
private:


	double width, height;
	double centerY;

	double amplitude, frequency;

	int i;

public:
	 int points_count = 40;
	const double pi = 3.14159265358979323846;

	double X()
	{
		return (2 * pi * i) / (points_count - 1);
	}
	double Y()
	{
		return centerY + amplitude * sin(frequency * X());
	}

	Point(int _i, double _width, double _height,int _points_count)
	{
		i = _i;

		width = _width;
		height = _height;

		frequency = 1;

		amplitude = height / 2;
		centerY = height / 2;
		points_count = _points_count;

	}



};







class CSinusoidDoc : public CDocument
{
protected: // создать только из сериализации
	CSinusoidDoc() noexcept;
	DECLARE_DYNCREATE(CSinusoidDoc)

// Атрибуты
public:

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSinusoidDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
