import com.ideaworks3d.marmalade.LoaderAPI;
import com.ideaworks3d.marmalade.LoaderActivity;

import android.app.UiModeManager;
import android.content.res.Configuration;
import android.content.Intent;
import android.view.InputDevice;
import android.util.Log;
import android.content.pm.PackageManager;

class AndroidHelper
{
  //===========================================================================
  // GetModeType
  //
  // DESCRIPTION: Calls and retuns whatever uiModeManager.getCurrentModeType()
  //              has to say.
  //===========================================================================
  public int GetModeType()
  {
    UiModeManager uiModeManager = (UiModeManager) LoaderAPI.getActivity().getSystemService(LoaderAPI.getActivity().UI_MODE_SERVICE);
    return uiModeManager.getCurrentModeType();
  }


  //===========================================================================
  // HasFeature
  //
  // DESCRIPTION: Passes a string to PackageManager.hasFeature and returns
  //              whether or not it's supported.
  //
  // PARAMS: 
  // pszFeatureName - A feature string to query. See more:
  // http://developer.android.com/reference/android/content/pm/PackageManager.html
  //===========================================================================
  public boolean HasFeature(String pszFeatureName)
  {    
    return LoaderAPI.getActivity().getPackageManager().hasSystemFeature(pszFeatureName);
  }


  //===========================================================================
  // IsTV
  //
  // DESCRIPTION: Determines if this app is running on an Android TV device.
  //===========================================================================
  public boolean IsTV()
  {
    UiModeManager uiModeManager = (UiModeManager) LoaderAPI.getActivity().getSystemService(LoaderAPI.getActivity().UI_MODE_SERVICE);
    
    if (uiModeManager.getCurrentModeType() == Configuration.UI_MODE_TYPE_TELEVISION) 
    {
      return true;
    } 
    else 
    {
      return false;
    }
  }

  
  //===========================================================================
  // HasGamePad
  //
  // DESCRIPTION: Checks if there is a gamepad attached to the system.
  //===========================================================================
  public boolean HasGamePad()
  {
    int[] aDeviceIds = InputDevice.getDeviceIds();

    for (int nDeviceId : aDeviceIds) 
    {
      InputDevice dev = InputDevice.getDevice(nDeviceId);
      int sources = dev.getSources();

      if (((sources & InputDevice.SOURCE_GAMEPAD) == InputDevice.SOURCE_GAMEPAD) || 
          ((sources & InputDevice.SOURCE_JOYSTICK) == InputDevice.SOURCE_JOYSTICK)) 
      {
        return true;
      }
    }
      
    return false;
  }


  //===========================================================================
  // Share
  //
  // DESCRIPTION: Shares a string via any of the social media apps installed on
  //              the users phone. Pops up a list of eligible apps for the user
  //              to choose from.  
  //===========================================================================
  public void Share(String pszSubject, String pszTitle, String pszText)
  {
    Intent intent = new Intent(Intent.ACTION_SEND);
    intent.setType("text/plain");    
    intent.putExtra(Intent.EXTRA_SUBJECT, pszSubject);
    intent.putExtra(Intent.EXTRA_TITLE, pszTitle);
    intent.putExtra(Intent.EXTRA_TEXT, pszText);
    LoaderAPI.getActivity().startActivity(Intent.createChooser(intent, "Share your score!"));      
  }  
}
