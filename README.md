Android-Helper
==============
A small extension for Marmalade to query various system features quickly and easily. Oh also social media sharing goodness! 
This was a quick hack but, it does exactly what I need so it might help someone out there as well!

To use, simple add AndroidHelper.mkf to your .MKB and include AndroidHelper.h to your project (in the .h directory) and you are good to go!

int GetModeType() is a call to this function:
http://developer.android.com/reference/android/app/UiModeManager.html#getCurrentModeType()

bool HasFeature(String pszFeatureName) returns true or false based on if a given feature is available. You pass in features as a string which is detailed here:
http://developer.android.com/reference/android/content/pm/PackageManager.html

IsTV() returns TRUE if your game is running on an Android TV device.

HasGamePad() returns TRUE if at least one gamepad is attached.

Share() is used to share stuff with. Once called, it will generate a list of activities to the user that will allow them to pick the app they want to use to share the text you have supplied.

