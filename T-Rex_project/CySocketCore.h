#pragma once
#include <afxsock.h>
#include "CySocketDataT1.h"
// CCySocketCore 명령 대상

class CCySocketCore : public CSocket
{
public:
	CCySocketCore();
	virtual ~CCySocketCore();
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual int SocketSendData(CCySocketDataT1 *sock_data_send);
};



