/* EWL
 * Copyright � 1995-2009 Freescale Corporation.  All rights reserved.
 *
 * $Date: 2012/06/12 20:40:39 $
 * $Revision: 1.1.2.1 $
 */

#ifndef _EWLSTRING_H
#define _EWLSTRING_H

// _EWLstring is a special simple string class used by <stdexept>.  This
// class breaks a potentially cyclic relationship between <stdexcept> and
// <string>.  Without this class, <string> throws classes from <stdexcept>
// and <stdexcept> processes <string>.  By making <stdexcept> depend on
// _EWLstring instead of <string>, the cycle is broken.

#include <ewlconfig>
#include <memory>
#include <ewl_smart_pointers>
#include <stringfwd>
#include <cstring>

#ifdef __CWCC__
#pragma options align=native

#ifdef _EWL_FORCE_ENUMS_ALWAYS_INT
	#if _EWL_FORCE_ENUMS_ALWAYS_INT
		#pragma enumsalwaysint on
	#else
		#pragma enumsalwaysint off
	#endif
#endif  // _EWL_FORCE_ENUMS_ALWAYS_INT

#ifdef _EWL_FORCE_ENABLE_BOOL_SUPPORT
	#if _EWL_FORCE_ENABLE_BOOL_SUPPORT
		#pragma bool on
	#else
		#pragma bool off
	#endif
#endif  // _EWL_FORCE_ENABLE_BOOL_SUPPORT
#endif

#ifndef _EWL_NO_CPP_NAMESPACE
	namespace std {
#endif

class _EWLstring {
public:
	_EWLstring(const char* value);
	_EWL_IMP_EXP_CPP _EWLstring(const string& value);
	const char* c_str() const;
protected:
private:
	_TR1::shared_ptr<char> data_;
};

inline
_EWLstring::_EWLstring(const char* value)
	: data_(new char [strlen(value)+1], detail::default_delete<char[]>())
{
	strcpy(const_cast<char*>(static_cast<const char*>(data_.get())), value);
}

inline
const char*
_EWLstring::c_str() const
{
	return data_.get();
}

#ifndef _EWL_NO_CPP_NAMESPACE
	} // namespace std
#endif

#ifdef __CWCC__
#ifdef _EWL_FORCE_ENUMS_ALWAYS_INT
	#pragma enumsalwaysint reset
#endif

#ifdef _EWL_FORCE_ENABLE_BOOL_SUPPORT
	#pragma bool reset
#endif

#pragma options align=reset
#endif

#endif // _EWLSTRING_H
