// CySocketDataT1.cpp: 구현 파일
//

#include "pch.h"
#include "T-Rex_project.h"
#include "CySocketDataT1.h"


// CCySocketDataT1

CCySocketDataT1::CCySocketDataT1()
{
}

CCySocketDataT1::~CCySocketDataT1()
{
}


// CCySocketDataT1 멤버 함수


void CCySocketDataT1::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code for sending data to socket
		ar<< m_score;
	
	}
	else
	{	// loading code for receiving data from socket
		ar >> m_score;

	}
}

