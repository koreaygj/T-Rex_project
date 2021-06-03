// CDialog.cpp: 구현 파일
//

#include "pch.h"
#include "T-Rex_project.h"
#include "CDialog.h"
#include "afxdialogex.h"


// CDialog 대화 상자

IMPLEMENT_DYNAMIC(CDialog, CDialogEx)

CDialog::CDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ScoreBox, pParent)
	, m_strDialog1(_T(""))
{

}

CDialog::~CDialog()

{
}

void CDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strDialog1);
}


BEGIN_MESSAGE_MAP(CDialog, CDialogEx)
END_MESSAGE_MAP()


// CDialog 메시지 처리기
