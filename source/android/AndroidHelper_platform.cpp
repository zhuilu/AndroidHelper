/*
 * android-specific implementation of the AndroidHelper extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "AndroidHelper_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_GetModeType;
static jmethodID g_HasFeature;
static jmethodID g_IsTV;
static jmethodID g_HasGamePad;
static jmethodID g_Share;

s3eResult AndroidHelperInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("AndroidHelper");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_GetModeType = env->GetMethodID(cls, "GetModeType", "()I");
    if (!g_GetModeType)
        goto fail;

    g_HasFeature = env->GetMethodID(cls, "HasFeature", "(Ljava/lang/String;)Z");
    if (!g_HasFeature)
        goto fail;

    g_IsTV = env->GetMethodID(cls, "IsTV", "()Z");
    if (!g_IsTV)
        goto fail;

    g_HasGamePad = env->GetMethodID(cls, "HasGamePad", "()Z");
    if (!g_HasGamePad)
        goto fail;

    g_Share = env->GetMethodID(cls, "Share", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
    if (!g_Share)
        goto fail;



    IwTrace(ANDROIDHELPER, ("ANDROIDHELPER init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(AndroidHelper, ("One or more java methods could not be found"));
    }

    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);
    return S3E_RESULT_ERROR;

}

void AndroidHelperTerminate_platform()
{ 
    // Add any platform-specific termination code here
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->DeleteGlobalRef(g_Obj);
    g_Obj = NULL;
}

int GetModeType_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_GetModeType);
}

bool HasFeature_platform(const char* pszFeatureName)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring pszFeatureName_jstr = env->NewStringUTF(pszFeatureName);
    return (bool)env->CallBooleanMethod(g_Obj, g_HasFeature, pszFeatureName_jstr);
}

bool IsTV_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_IsTV);
}

bool HasGamePad_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_HasGamePad);
}

void Share_platform(const char* pszSubject, const char* pszTitle, const char* pszText)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring pszSubject_jstr = env->NewStringUTF(pszSubject);
    jstring pszTitle_jstr = env->NewStringUTF(pszTitle);
    jstring pszText_jstr = env->NewStringUTF(pszText);
    env->CallVoidMethod(g_Obj, g_Share, pszSubject_jstr, pszTitle_jstr, pszText_jstr);
}
