/* EWL
 * Copyright � 1995-2009 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2012/06/01 21:11:38 $
 * $Revision: 1.1 $
 */

#ifndef _NEW_H
#define _NEW_H

#include <new>

#ifdef _EWL_USING_NAMESPACE
using std::size_t;
#endif

#ifndef _EWL_NO_CPP_NAMESPACE
using std::bad_alloc;
using std::new_handler;
using std::nothrow;
using std::nothrow_t;
using std::set_new_handler;
#endif // _EWL_NO_CPP_NAMESPACE

#endif // _NEW_H
