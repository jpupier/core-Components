/*
* This file is part of Wakanda software, licensed by 4D under
*  (i) the GNU General Public License version 3 (GNU GPL v3), or
*  (ii) the Affero General Public License version 3 (AGPL v3) or
*  (iii) a commercial license.
* This file remains the exclusive property of 4D and/or its licensors
* and is protected by national and international legislations.
* In any event, Licensee's compliance with the terms and conditions
* of the applicable license constitutes a prerequisite to any use of this file.
* Except as otherwise expressly stated in the applicable license,
* such license does not include any other license or rights on this file,
* 4D's and/or its licensors' trademarks and/or other proprietary rights.
* Consequently, no title, copyright or other proprietary rights
* other than those specified in the applicable license is granted.
*/
#include "HTTPServer.h"

#if 0 // TBD: Cleanup
//--------------------------------------------------------------------------------------------------


NameValueCollection::NameValueCollection()
{
}


NameValueCollection::NameValueCollection (const NameValueCollection& inNameValueCollection)
: fMap (inNameValueCollection.fMap)
{
}


NameValueCollection::~NameValueCollection()
{
	fMap.clear();
}


NameValueCollection& NameValueCollection::operator = (const NameValueCollection& inNameValueCollection)
{
	if (&inNameValueCollection != this)
	{
		fMap.clear();
		fMap.insert (inNameValueCollection.begin(), inNameValueCollection.end());
	}

	return *this;
}


const XBOX::VString& NameValueCollection::operator [] (const XBOX::VString& inName) const
{
	ConstIterator it = std::find_if (fMap.begin(), fMap.end(), EqualFirstVStringFunctor<XBOX::VString> (inName));
	if (it != fMap.end())
		return it->second;

	return STRING_EMPTY;
}


void NameValueCollection::set (const XBOX::VString& inName, const XBOX::VString& inValue)
{
	Iterator it = std::find_if (fMap.begin(), fMap.end(), EqualFirstVStringFunctor<XBOX::VString> (inName));
	if (it != fMap.end())
		it->second = inValue;
	else
		fMap.insert (NameValueMap::value_type (inName, inValue));
}

	
void NameValueCollection::add (const XBOX::VString& inName, const XBOX::VString& inValue)
{
	fMap.insert (NameValueMap::value_type (inName, inValue));
}

	
const XBOX::VString& NameValueCollection::get (const XBOX::VString& inName) const
{
	ConstIterator it = std::find_if (fMap.begin(), fMap.end(), EqualFirstVStringFunctor<XBOX::VString> (inName));
	if (it != fMap.end())
		return it->second;

	return STRING_EMPTY;
}


const XBOX::VString& NameValueCollection::get (const XBOX::VString& inName, const XBOX::VString& inDefaultValue) const
{
	ConstIterator it = std::find_if (fMap.begin(), fMap.end(), EqualFirstVStringFunctor<XBOX::VString> (inName));
	if (it != fMap.end())
		return it->second;
	else
		return inDefaultValue;
}


bool NameValueCollection::has (const XBOX::VString& inName) const
{
 	return (std::find_if (fMap.begin(), fMap.end(), EqualFirstVStringFunctor<XBOX::VString> (inName)) != fMap.end());
}


NameValueCollection::ConstIterator NameValueCollection::find (const XBOX::VString& inName) const
{
	return std::find_if (fMap.begin(), fMap.end(), EqualFirstVStringFunctor<XBOX::VString> (inName));
}


NameValueCollection::ConstIterator NameValueCollection::begin() const
{
	return fMap.begin();
}

	
NameValueCollection::Iterator NameValueCollection::begin()
{
	return fMap.begin();
}

	
NameValueCollection::ConstIterator NameValueCollection::end() const
{
	return fMap.end();
}


NameValueCollection::Iterator NameValueCollection::end()
{
	return fMap.end();
}


bool NameValueCollection::empty() const
{
	return fMap.empty();
}


int NameValueCollection::size() const
{
	return (int) fMap.size();
}


void NameValueCollection::erase (const XBOX::VString& inName)
{
	fMap.erase (inName);
}


void NameValueCollection::erase (Iterator& inIter)
{
	fMap.erase (inIter);
}


void NameValueCollection::clear()
{
	fMap.clear();
}

#endif