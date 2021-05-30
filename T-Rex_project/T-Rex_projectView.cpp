﻿
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
#include "windows.h"
#pragma comment(lib, "winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define bottom 300
#define start 40
// CTRexprojectView

IMPLEMENT_DYNCREATE(CTRexprojectView, CView)

BEGIN_MESSAGE_MAP(CTRexprojectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CTRexprojectView 생성/소멸

CTRexprojectView::CTRexprojectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_dino_x = start;
	m_dino_y = 300;
	m_ncount = 0;
	m_Huddlespeed = 0;
	m_frame = 0.f;
	m_framespeed = 0.4f;
	m_jump = false;
	m_bottom = true;
	m_Huddlesignal = false;
	m_tree_x = 1000;m_tree_y = 320;
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

void CTRexprojectView::OnDraw(CDC* pDC)
{
	CTRexprojectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOutW(10, 10, _T("게임을 시작하려면 space bar 게임을 나오려면 q를 눌러주세요."));
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


void CTRexprojectView::OnPaint()
{
	//바닥
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CPen pen, * oldpen;
	pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	oldpen = dc.SelectObject(&pen);
	dc.MoveTo(10, 380);
	dc.LineTo(1080, 380);
	//마우스 포인터 위치 출력용 (공룡게임과 무관)
	CString str;
	str.Format(L"x = %d, y = %d", m_pos.x, m_pos.y);
	dc.TextOut(m_pos.x- 100, m_pos.y, str);
}


void CTRexprojectView::OnMouseMove(UINT nFlags, CPoint point)
{
	//마우스 포인터 위치 춮력용 (공룡게임과 무관)
	CClientDC dc(this);
	m_pos = point;
	Invalidate();
	
	CView::OnMouseMove(nFlags, point);
}

void CTRexprojectView::OnTimer(UINT_PTR nIDEvent)
{
	CView::OnTimer(nIDEvent);
	static int ncount;
	static int huddle;
	int huddlespeed;
	CClientDC dc(this);
	Moving();
	HuddleMove();
	m_score.Format(_T("%d"), (ncount++ / 10));
	dc.TextOutW(900, 10, _T("Score :   ") + m_score);

}

void CTRexprojectView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	m_startsignal = true;
	Gamestart();
	switch (nChar)
	{
	case VK_SPACE:
		m_jump = true;
		break;
	case VK_UP:
		m_jump = true;
		break;
	case VK_CONTROL:
		break;
	default:
		m_jump = false;
		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
//점프 함수
void CTRexprojectView::jumping() {
		if (m_jump && !m_bottom)
		{
			m_jump == true;
			m_bottom == false;
		}
		if (m_dino_y > bottom) {
			m_dino_y = bottom;
			m_bottom = true;
		}
		if (m_dino_y < bottom - 150) {
			m_jump = false;
		}
		if (m_jump) {
			m_dino_y -= 5;
		}
		else {
			m_dino_y += 5;
		}
}
//Player 움직임 구현
void CTRexprojectView::Moving() {
	static int m_ncount = 0;
	const int changeframe = 5;
	m_frame += m_framespeed;
	jumping();
	if (m_frame >= changeframe)
	{
		m_frame -= changeframe;
		++m_ncount;
		++m_Huddlespeed;
		if (m_ncount >= 2) { m_ncount = 0; }
	}
	if (m_ncount == 0)
	{
		Player1();
	}
	else
	{
		Player2();
	}
}
//점수 시작하는 함수
void CTRexprojectView::Gamestart() {
	if(m_startsignal == true)
		SetTimer(0, 7, NULL);
}
//Player 1 비트맵 불러오기
void CTRexprojectView::Player1() {
	CClientDC dc(this);
	CBitmap bmpPlayer1;
	bmpPlayer1.LoadBitmap(IDB_Player1);
	CDC memDC1; memDC1.CreateCompatibleDC(&dc);
	memDC1.SelectObject(&bmpPlayer1);
	//dc.BitBlt(m_dino_x, m_dino_y, 80, 80, &memDC1, 0, 80, SRCCOPY);
	dc.BitBlt(m_dino_x, m_dino_y, 80, 160, &memDC1, 0, 0, SRCCOPY);
	memDC1.DeleteDC();
	bmpPlayer1.DeleteObject();
}
//Player 2 비트맵 불러오기
void CTRexprojectView::Player2() {
	CClientDC dc(this);
	CBitmap bmpPlayer2;
	bmpPlayer2.LoadBitmap(IDB_Player2);
	CDC memDC2; memDC2.CreateCompatibleDC(&dc);
	memDC2.SelectObject(&bmpPlayer2);
	//dc.BitBlt(m_dino_x, m_dino_y, 80, 80, &memDC2, 0, 80, SRCCOPY);
	dc.BitBlt(m_dino_x, m_dino_y, 80, 160, &memDC2, 0, 0, SRCCOPY);
	memDC2.DeleteDC();
	bmpPlayer2.DeleteObject();
}
//Tree 비트맵 불러오기

}

void CTRexprojectView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_jump = true;
	CView::OnLButtonDown(nFlags, point);
}
