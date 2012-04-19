/*+========================================================================== 
* FileName: SyncMutex.h
* 
* Purpose:  SyncMutex
*
* Author	Lingfang Li (lfli@telenav.cn)
* Version	04/12/2011
* Since	VS.NET 2005
==========================================================================+*/

#ifndef SYNC_MUTEX_H
#define SYNC_MUTEX_H

class SyncMutex
{
public:
	explicit SyncMutex();
	~SyncMutex();
public:
	void lock();
	void unlock();
	bool trylock();
 
private:
	void* m_pMutex;
};

#endif