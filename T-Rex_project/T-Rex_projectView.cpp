
// T-Rex_projectView.cpp: CTRexprojectView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "T-Rex_project.h"
#endif

#include "T-Rex_projectDoc.h"
#include "T-Rex_projectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTRexprojectView

IMPLEMENT_DYNCREATE(CTRexprojectView, CView)

BEGIN_MESSAGE_MAP(CTRexprojectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTRexprojectView 생성/소멸

CTRexprojectView::CTRexprojectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTRexprojectView::~CTRexprojectView()
{
}

BOOL CTRexprojectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTRexprojectView 그리기

void CTRexprojectView::OnDraw(CDC* /*pDC*/)
{
	CTRexprojectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CTRexprojectView 인쇄

BOOL CTRexprojectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTRexprojectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTRexprojectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTRexprojectView 진단

#ifdef _DEBUG
void CTRexprojectView::AssertValid() const
{
	CView::AssertValid();
}

void CTRexprojectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTRexprojectDoc* CTRexprojectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTRexprojectDoc)));
	return (CTRexprojectDoc*)m_pDocument;
}
#endif //_DEBUG


// CTRexprojectView 메시지 처리기
