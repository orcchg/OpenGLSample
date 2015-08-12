package com.orcchg.openglsample;

import android.app.Activity;
import android.os.Bundle;


public class MainActivity extends Activity {
  static {
    System.loadLibrary("OpenGLSample");
  }
  
  private NativeInterface ni;
  
  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);
    ni = new NativeInterface();
    RenderSurface surface = (RenderSurface) findViewById(R.id.surface_view);
    surface.setNativeInterface(ni);
  }
  
  @Override
  protected void onDestroy() {
    super.onDestroy();
    ni.destroy();
  }
}
