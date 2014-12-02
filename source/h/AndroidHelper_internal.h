/*
 * Internal header for the AndroidHelper extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef ANDROIDHELPER_INTERNAL_H
#define ANDROIDHELPER_INTERNAL_H

#include "s3eTypes.h"
#include "AndroidHelper.h"
#include "AndroidHelper_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult AndroidHelperInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult AndroidHelperInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void AndroidHelperTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void AndroidHelperTerminate_platform();
int GetModeType_platform();

bool HasFeature_platform(const char* pszFeatureName);

bool IsTV_platform();

bool HasGamePad_platform();

void Share_platform(const char* pszSubject, const char* pszTitle, const char* pszText);


#endif /* !ANDROIDHELPER_INTERNAL_H */