
// SinusoidDoc.h: интерфейс класса CSinusoidDoc 
//



#pragma once



class CSinusoidView;
class CMainFrm;
class CControlTreeView;

class CSinusoidDoc : public CDocument
{
protected: // создать только из сериализации
	CSinusoidDoc() noexcept;
	DECLARE_DYNCREATE(CSinusoidDoc)

// Атрибуты
public:
	//static SinusoidFunction *sinusoida ;
	CControlTreeView* m_pTreeView;
	CSinusoidView *m_pView;
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
	bool m_bCoord, m_bSinus, m_bHatch, m_bHatch45;
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
