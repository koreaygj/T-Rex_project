
// T-Rex_projectView.h: CTRexprojectView 클래스의 인터페이스
//

#pragma once


class CTRexprojectView : public CView
{
protected: // serialization에서만 만들어집니다.
	CTRexprojectView() noexcept;
	DECLARE_DYNCREATE(CTRexprojectView)

// 특성입니다.
public:
	CTRexprojectDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTRexprojectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_pos;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void Line();
	void jumping();
	void Moving();
	void Gamestart();
	void Player1();
	void Player2();
	void Huddle1();
	void Huddle2();
	void GameoverPlayer();
	void HuddleMove();
	void HuddleMove2();
	BOOL CollisionAlgorithm();
	void Scorebox();
	BOOL m_stop;
	BOOL m_jump;
	BOOL m_bottom;
	BOOL m_startsignal;
	BOOL m_jumpsignal;
	BOOL m_nodouble;
	BOOL m_Huddlesignal;
	BOOL m_Gameover_x1, m_Gameover_x2;
	BOOL m_Gameover_y;
	BOOL m_Gameover;
	BOOL m_Gameoversignal1, m_Gameoversignal2;
	int m_dino_x;
	int m_dino_y;
	int m_huddle_x1, m_huddle_x2, m_huddle_y1, m_huddle_y2;
	CString m_score;
	CString m_username;
	int m_ncount;
	int m_Huddlespeed, m_Huddlespeed2;
	int m_Timer;
	float m_frame, m_framespeed;
};

#ifndef _DEBUG  // T-Rex_projectView.cpp의 디버그 버전
inline CTRexprojectDoc* CTRexprojectView::GetDocument() const
   { return reinterpret_cast<CTRexprojectDoc*>(m_pDocument); }
#endif

