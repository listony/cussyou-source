#include "SyncMutex.h"
#include <stdexcept>
#include <windows.h>

SyncMutex::SyncMutex()
: m_pMutex(NULL)
{
	m_pMutex = ::CreateMutex((LPSECURITY_ATTRIBUTES) 0, FALSE,(LPCTSTR) 0);
	if (m_pMutex == NULL)
	{
		throw std::runtime_error("CreateMutex failed.");
	}
}

SyncMutex::~SyncMutex()
{
	::CloseHandle(m_pMutex);
}

void SyncMutex::lock()
{
	if (::WaitForSingleObject(m_pMutex, INFINITE) == WAIT_OBJECT_0)
	{
		return;
	}
	throw std::runtime_error("WaitForSingleObject failed.");

}

void SyncMutex::unlock()
{
	if (!::ReleaseMutex(m_pMutex))
	{
		throw std::runtime_error("ReleaseMutex failed.");
	}
}

bool SyncMutex::trylock()
{
	switch (::WaitForSingleObject(m_pMutex, 0)) 
	{
	case WAIT_TIMEOUT:
		return false;
	case WAIT_OBJECT_0:
		return true;
	default:
		throw std::runtime_error("WaitForSingleObbject failed.");
	}
}