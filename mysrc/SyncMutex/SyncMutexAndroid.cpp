#include "SyncMutex.h"
#include <pthread.h>
#include <stdexcept>
#include <asm-generic/errno-base.h>

SyncMutex::SyncMutex()
: m_pMutex(NULL)
{
	register int rc;
	pthread_mutex_t* mutex = new pthread_mutex_t();
	if ((rc = pthread_mutex_init(mutex, 0)))
	{
		throw std::runtime_error(strerror(rc));
	}
	m_pMutex = mutex;
}

SyncMutex::~SyncMutex()
{
	pthread_mutex_t* mutex = (pthread_mutex_t*)m_pMutex;
	pthread_mutex_destroy(mutex);
	delete mutex;
	m_pMutex = NULL;
}

void SyncMutex::lock()
{
	register int rc;
	pthread_mutex_t* mutex = (pthread_mutex_t*)m_pMutex;
	if ((rc = pthread_mutex_lock(mutex)))
	{
		throw std::runtime_error(strerror(rc));
	}
}

void SyncMutex::unlock()
{
	register int rc;
	pthread_mutex_t* mutex = (pthread_mutex_t*)m_pMutex;
	if ((rc = pthread_mutex_unlock(mutex)))
	{
		throw std::runtime_error(strerror(rc));
	}
}

bool SyncMutex::trylock()
{
	register int rc;
	pthread_mutex_t* mutex = (pthread_mutex_t*)m_pMutex;
	if ((rc = pthread_mutex_trylock(mutex)) == 0)
	{
		return true;
	}
	if (rc == EBUSY)
	{
		return false;
	}
	throw std::runtime_error(strerror(rc));
}