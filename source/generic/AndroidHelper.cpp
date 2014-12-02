/*
Generic implementation of the AndroidHelper extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "AndroidHelper_internal.h"
s3eResult AndroidHelperInit()
{
    //Add any generic initialisation code here
    return AndroidHelperInit_platform();
}

void AndroidHelperTerminate()
{
    //Add any generic termination code here
    AndroidHelperTerminate_platform();
}

int GetModeType()
{
	return GetModeType_platform();
}

bool HasFeature(const char* pszFeatureName)
{
	return HasFeature_platform(pszFeatureName);
}

bool IsTV()
{
	return IsTV_platform();
}

bool HasGamePad()
{
	return HasGamePad_platform();
}

void Share(const char* pszSubject, const char* pszTitle, const char* pszText)
{
	Share_platform(pszSubject, pszTitle, pszText);
}
