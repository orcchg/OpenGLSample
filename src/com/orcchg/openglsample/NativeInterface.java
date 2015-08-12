package com.orcchg.openglsample;

import android.view.Surface;

public class NativeInterface {
  private final long descriptor;
  
  NativeInterface() {
    descriptor = init();
  }
  
  void setSurface(Surface surface) { setSurface(descriptor, surface); }
  void destroy() { destroy(descriptor); }
  
  private native long init();
  private native void setSurface(long descriptor, Surface surface);
  private native void destroy(long descriptor);
}
